#include <iostream>
#include <vector>
#include <thread>
#include <mutex> // sync 
#include <chrono> // time
#include <functional> // poly wrapper func temp
#include <memory> // smart ptr
//conc schedule
using namespace std;

// Mutex for thread-safe console output
mutex consoleMutex;

// Task class stored in std func
class Task {
private:
    string name;
    function<void()> action; // as func obj 
    int delayMs;

public:
    // Constructor
    Task(string taskName, function<void()> taskAction, int taskDelayMs)
        : name(move(taskName)), action(move(taskAction)), delayMs(taskDelayMs) {}

    // Move constructor
    Task(Task&& other) noexcept
        : name(move(other.name)), action(move(other.action)), delayMs(other.delayMs) {}

    // Move assignment
    Task& operator=(Task&& other) noexcept {
        if (this != &other) {
            name = move(other.name);
            action = move(other.action);
            delayMs = other.delayMs;
        }
        return *this;
    }

    // Delete copy operations 
    Task(const Task&) = delete;
    Task& operator=(const Task&) = delete;

    // Execute the task
    void execute() {
        {
            lock_guard<mutex> lock(consoleMutex);
            cout << ">> Starting task: " << name << " (delay: " << delayMs << "ms)" << endl;
        }
        this_thread::sleep_for(chrono::milliseconds(delayMs));
        action();
        {
            lock_guard<mutex> lock(consoleMutex);
            cout << ">> Completed task: " << name << endl;
        }
    }
};

int main() {
   
    vector<unique_ptr<Task>> tasks;
 // smart ptr
    tasks.push_back(make_unique<Task>("Task 1", []() { //lambda capture +lambda body //explicitly specified
        lock_guard<mutex> lock(consoleMutex);
        cout << "   Message: Task 1 completed after 2 seconds" << endl;
    }, 2000));

    tasks.push_back(make_unique<Task>("Task 2", []() {
        lock_guard<mutex> lock(consoleMutex);
        cout << "   Message: Task 2 completed after 1 second" << endl;
    }, 1000));
// task3 deduced to be unique_ptr<Task>
// Automatically deduce the type of a variable from its initializer.
    auto task3 = make_unique<Task>("Task 3", []() {
        lock_guard<mutex> lock(consoleMutex);
        cout << "   Message: Task 3 completed after 3 seconds" << endl;
    }, 3000);

    tasks.push_back(move(task3));
// multithreading 
    vector<thread> threads;

    cout << "\n=== Starting execution of " << tasks.size() << " tasks ===\n" << endl;

    for (auto& task : tasks) {
        threads.emplace_back([&task]() {
            task->execute();
        });
    }

    for (auto& t : threads) {
        t.join();
    }

    cout << "\n=== All tasks completed successfully ===\n" << endl;

    return 0;
}
