#include <iostream>
using namespace std;

template <typename T>
class Stack {
private:
    static const int MAX_SIZE = 2; // Maximum size of the stack
    T elements[MAX_SIZE];         // Array to hold stack elements
    int top;                      // Index of the top of the stack

public:
    Stack() : top(-1) {}          // Constructor initializes top to -1

    bool isEmpty() const {
        return top == -1;
    }

    bool isFull() const {
        return top == MAX_SIZE - 1;
    }

    void push(const T& value) {
        if (isFull()) {
            cout << "Push failed: Stack Overflow." << endl;
            return;
        }
        elements[++top] = value; 
    }

    T pop() {
        if (isEmpty()) {
            cout << "Pop failed: Stack Underflow." << endl;
            return T(); // Return default value of T
        }
        return elements[top--]; 
    }

    T peek() const {
        if (isEmpty()) {
            cout << "Peek failed: Empty stack." << endl;
            return T(); 
        }
        return elements[top];
    }

    void display() const {
        if (isEmpty()) {
            cout << "Stack is empty." << endl;
        } else {
            cout << "Stack: ";
            for (int i = 0; i <= top; ++i)
                cout << elements[i] << " ";
            cout << endl;
        }
    }
};

int main() {
    Stack<int> intStack;

    cout << "Integer Stack:" << endl;
    intStack.display();
    intStack.push(1);
    intStack.push(2);
    intStack.push(3); //  overflow
    intStack.display();
    cout << "Peek: " << intStack.peek() << endl;
    cout << "Popped: " << intStack.pop() << endl;
    cout << "Popped: " << intStack.pop() << endl;
    intStack.display(); 
    intStack.pop(); //  underflow

    return 0;
}


