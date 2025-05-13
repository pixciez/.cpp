#include <iostream>
#include <string>
using namespace std;

class Book {
protected:
    string title, author;
    int ISBN;
public:
    Book(string t, string a, int i) : title(t), author(a), ISBN(i) {}
};

class Borrower {
protected:
    string name;
    int ID;
public:
    Borrower(string n, int id) : name(n), ID(id) {}
};

class Library : public Book, public Borrower {
public:
    Library(string t, string a, int i, string n, int id)
        : Book(t, a, i), Borrower(n, id) {}
    void action(int act) {
        if (act == 1) {
            cout << "Borrower " << name << " (ID: " << ID << ") has borrowed \""
                 << title << "\" by " << author << " (ISBN: " << ISBN << ")." << endl;
        } else if (act == 2) {
            cout << "Borrower " << name << " (ID: " << ID << ") has returned \""
                 << title << "\" by " << author << " (ISBN: " << ISBN << ")." << endl;
        } else {
            cout << "Invalid action type." << endl;
        }
    }
};

int main() {
    Library lib("C++ Basics", "John Doe", 1234, "Alice", 42);
    int action;
    cin >> action;
    lib.action(action);
    return 0;
}
