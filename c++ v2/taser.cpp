#include <iostream>
#include <vector>
#include <thread>
#include <mutex>
#include <chrono>
#include <functional>
#include <memory>
#include <string>

using namespace std;

// Mutex for thread synchronization
mutex consoleMutex;

// Task class that can be executed with a delay
class Task {
private:
    function<void()> action;
    string name;
    int delayMs;

public:
    // Constructor
    Task(string taskName, function<void()> taskAction, int taskDelayMs)
        : name(move(taskName)), action(move(taskAction)), delayMs(taskDelayMs) {}

    // Move constructor
    Task(Task&& other) noexcept
        : name(move(other.name)), 
          action(move(other.action)), 
          delayMs(other.delayMs) {}

    // Move assignment operator
    Task& operator=(Task&& other) noexcept {
        if (this != &other) {
            name = move(other.name);
            action = move(other.action);
            delayMs = other.delayMs;
        }
        return *this;
    }

    // Delete copy constructor and assignment to enforce move semantics
    Task(const Task&) = delete;
    Task& operator=(const Task&) = delete;

    // Execute the task with the specified delay
    void execute() const {
        {
            lock_guard<mutex> lock(consoleMutex);
            cout << "Starting task: " << name << endl;
        }

        // Apply the delay
        this_thread::sleep_for(chrono::milliseconds(delayMs));

        // Execute the task action
        action();

        {
            lock_guard<mutex> lock(consoleMutex);
            cout << "Completed task: " << name << endl;
        }
    }

    // Getter for task name
    const string& getName() const {
        return name;
    }
};

// TaskScheduler class to manage and execute tasks
class TaskScheduler {
private:
    vector<shared_ptr<Task>> tasks;

public:
    // Add a unique_ptr task (transfers ownership to scheduler)
    void addTask(unique_ptr<Task> task) {
        lock_guard<mutex> lock(consoleMutex);
        cout << "Adding task: " << task->getName() << endl;
        // Convert unique_ptr to shared_ptr using move
        tasks.push_back(shared_ptr<Task>(move(task)));
    }

    // Execute all tasks concurrently
    void executeAll() {
        vector<thread> threads;
        
        // Create threads for each task
        for (const auto& task : tasks) {
            threads.emplace_back([task]() {
                task->execute();
            });
        }

        // Join all threads to wait for completion
        for (auto& thread : threads) {
            thread.join();
        }
    }
};

int main() {
    TaskScheduler scheduler;

    // Create tasks using lambda expressions with auto type inference
    auto createTask = [](const string& name, int delay, const string& message) {
        return make_unique<Task>(
            name,
            [message]() {
                lock_guard<mutex> lock(consoleMutex);
                cout << "Message: " << message << endl;
            },
            delay
        );
    };

    // Add tasks to the scheduler
    scheduler.addTask(createTask("Task 1", 2000, "Task 1 completed after 2 seconds"));
    scheduler.addTask(createTask("Task 2", 1000, "Task 2 completed after 1 second"));
    scheduler.addTask(createTask("Task 3", 3000, "Task 3 completed after 3 seconds"));

    cout << "Starting all tasks...\n";
    scheduler.executeAll();
    cout << "All tasks completed.\n";

    return 0;
}