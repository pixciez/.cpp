#include <iostream>
#include <vector>
#include <thread>
#include <mutex>
#include <chrono>
#include <functional>
#include <memory>

using namespace std;

// Mutex for thread-safe console output
mutex consoleMutex;

// Simple Task class
class Task {
private:
    string name;
    function<void()> action;
    int delayMs;
    bool completed = false;

public:
    // Constructor
    Task(string taskName, function<void()> taskAction, int taskDelayMs)
        : name(move(taskName)), action(move(taskAction)), delayMs(taskDelayMs) {}

    // Move constructor
    Task(Task&& other) noexcept
        : name(move(other.name)), 
          action(move(other.action)), 
          delayMs(other.delayMs),
          completed(other.completed) {}

    // Move assignment
    Task& operator=(Task&& other) noexcept {
        if (this != &other) {
            name = move(other.name);
            action = move(other.action);
            delayMs = other.delayMs;
            completed = other.completed;
        }
        return *this;
    }

    // Delete copy operations
    Task(const Task&) = delete;
    Task& operator=(const Task&) = delete;

    // Execute the task
    void execute() {
        // Print start message
        {
            lock_guard<mutex> lock(consoleMutex);
            cout << ">> Starting task: " << name << " (delay: " << delayMs << "ms)" << endl;
        }

        // Wait for the specified delay
        this_thread::sleep_for(chrono::milliseconds(delayMs));
        
        // Execute the task action
        action();
        
        // Mark as completed
        completed = true;
        
        // Print completion message
        {
            lock_guard<mutex> lock(consoleMutex);
            cout << ">> Completed task: " << name << endl;
        }
    }

    string getName() const { return name; }
    bool isCompleted() const { return completed; }
};

int main() {
    // Vector to store tasks
    vector<unique_ptr<Task>> tasks;
    
    // Add tasks to the vector
    tasks.push_back(make_unique<Task>("Task 1", 
        []() {
            lock_guard<mutex> lock(consoleMutex);
            cout << "   Message: Task 1 completed after 2 seconds" << endl;
        }, 
        2000));
    
    tasks.push_back(make_unique<Task>("Task 2", 
        []() {
            lock_guard<mutex> lock(consoleMutex);
            cout << "   Message: Task 2 completed after 1 second" << endl;
        }, 
        1000));
    
    // Demonstrate move semantics
    auto task3 = make_unique<Task>("Task 3", 
        []() {
            lock_guard<mutex> lock(consoleMutex);
            cout << "   Message: Task 3 completed after 3 seconds" << endl;
        }, 
        3000);
    
    cout << "Created Task 3, now transferring ownership with std::move" << endl;
    tasks.push_back(move(task3));  // Transfer ownership using move
    
    // Vector to store threads
    vector<thread> threads;
    
    // Print start message
    cout << "\n=== Starting execution of " << tasks.size() << " tasks ===\n" << endl;
    
    // Create a thread for each task
    for (auto& task : tasks) {
        threads.emplace_back([&task]() {
            task->execute();
        });
    }
    
    // Wait for all threads to finish
    for (auto& t : threads) {
        t.join();
    }
    
    // Print completion message
    cout << "\n=== All tasks completed successfully ===\n" << endl;
    
    return 0;
}