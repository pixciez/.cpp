#include <iostream>
#include <vector>
#include <thread>
#include <mutex>
#include <chrono>
#include <functional>
#include <memory>

using namespace std;

// Mutex for thread synchronization
mutex consoleMutex;

// Simple Task class
class Task {
private:
    string name;
    function<void()> action;
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

    // Deleted copy operations
    Task(const Task&) = delete;
    Task& operator=(const Task&) = delete;

    // Execute the task
    void execute() const {
        // Print start status
        {
            lock_guard<mutex> lock(consoleMutex);
            cout << "Starting task: " << name << endl;
        }

        // Wait for the delay
        this_thread::sleep_for(chrono::milliseconds(delayMs));
        
        // Execute the task
        action();
        
        // Print completion status
        {
            lock_guard<mutex> lock(consoleMutex);
            cout << "Completed task: " << name << endl;
        }
    }

    string getName() const { return name; }
};

int main() {
    // Create a vector to store tasks
    vector<unique_ptr<Task>> tasks;
    
    // Create tasks using lambda expressions
    auto task1 = make_unique<Task>("Task 1", 
        []() {
            lock_guard<mutex> lock(consoleMutex);
            cout << "Message: Task 1 completed after 2 seconds" << endl;
        }, 
        2000);
    
    auto task2 = make_unique<Task>("Task 2", 
        []() {
            lock_guard<mutex> lock(consoleMutex);
            cout << "Message: Task 2 completed after 1 second" << endl;
        }, 
        1000);
    
    auto task3 = make_unique<Task>("Task 3", 
        []() {
            lock_guard<mutex> lock(consoleMutex);
            cout << "Message: Task 3 completed after 3 seconds" << endl;
        }, 
        3000);
    
    // Add tasks to vector
    tasks.push_back(move(task1));
    tasks.push_back(move(task2));
    tasks.push_back(move(task3));
    
    // Print start message
    cout << "Starting all tasks...\n";
    
    // Create threads for tasks
    vector<thread> threads;
    for (auto& task : tasks) {
        threads.emplace_back([&task]() {
            task->execute();
        });
    }
    
    // Wait for all threads to complete
    for (auto& t : threads) {
        t.join();
    }
    
    cout << "All tasks completed.\n";
    
    return 0;
}