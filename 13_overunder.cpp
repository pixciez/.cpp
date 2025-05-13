#include <iostream>
#include <iomanip>
using namespace std;

#define MAX_SIZE 5

class Stack {
private:
    int arr[MAX_SIZE];
    int top;

public:
    Stack() {
        top = -1;
    }

    void push(int value) {
        if (top >= MAX_SIZE - 1) {
            cout << "Stack is full! Cannot push " << value << " onto the stack." << endl;
        } else {
            arr[++top] = value;
            cout << "Pushed " << setw(2) << value << " onto the stack." << endl;
        }
    }

    void pop() {
        if (top < 0) {
            cout << "Stack is empty! Cannot pop." << endl;
        } else {
            cout << "Popped " << setw(2) << arr[top] << " from the stack." << endl;
            top--;
        }
    }
};

int main() {
    Stack s;
    
    cout << "Demonstrating stack overflow:" << endl;
    for (int i = 0; i < MAX_SIZE + 1; ++i) {
        s.push(i);
    }
    cout << "-----------------------------------" << endl;
    
    cout << "Demonstrating stack underflow:" << endl;
    for (int i = 0; i < MAX_SIZE + 1; ++i) {
        s.pop();
    }
    cout << "-----------------------------------" << endl;

    return 0;
}
