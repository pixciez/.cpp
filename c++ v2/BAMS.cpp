#include <iostream>
#include <string>
using namespace std;

class BankAccount {
protected: 
    static int next;
    string acc_number, name;
    double balance;

public:
    BankAccount(string acc_name, double bal, string prefix) 
        : name(acc_name), balance(bal) {
            acc_number = prefix + to_string(next++);
        }

    void deposit(double amount) { balance += amount; }

    virtual void withdraw(double amount) = 0; // pure virtual function

    void display_balance() {
        cout << acc_number << " " << name << endl;
        cout << "Balance: Rs " << balance << endl << endl;
    }
};

// init static counter
int BankAccount::next = 31415;

class SavingsAccount : public BankAccount {
public:
    SavingsAccount(string acc_name, double bal)
        : BankAccount(acc_name, bal < 500 ? 500 : bal, "SAV") {}

    void withdraw(double amount) override {
        if (balance - amount < 500)
            cout << "Error: Minimum balance of Rs 500 must be maintained!" << endl;
        else
            balance -= amount;
    }
};

class CurrentAccount : public BankAccount {
public:
    CurrentAccount(string acc_name, double bal)
        : BankAccount(acc_name, bal, "CURR") {}

    void withdraw(double amount) override {
        if (balance < amount + 50)
            cout << "Error: Insufficient balance!" << endl;
        else
            balance -= (amount + 50);
    }
};

int main() {
    SavingsAccount sa("Varun", 1000);
   //  SavingsAccount sa2("Mimi", 2000);
    CurrentAccount ca("Mimi", 2000);

    sa.deposit(500);
    sa.withdraw(1200);
    sa.display_balance();

    ca.withdraw(1900);
    ca.display_balance();

    return 0;
}
