#include <iostream>
using namespace std;

class Account {
protected:
    int balance;
public:
    Account(int bal) : balance(bal) {}
    virtual void calculateInterest() = 0;
    virtual ~Account() {}
};

class SavingsAccount : public Account {
    double rate;
    int time;
public:
    SavingsAccount(int bal, double r, int t) : Account(bal), rate(r), time(t) {}
    void calculateInterest() override {
        cout << "Savings Account Interest: " << balance * rate * time / 100 << endl;
    }
};

class CurrentAccount : public Account {
    int fee;
public:
    CurrentAccount(int bal, int f) : Account(bal), fee(f) {}
    void calculateInterest() override {
        cout << "Balance after fee deduction: " << balance - fee << endl;
    }
};

int main() {
    int type;
    cin >> type;
    if (type == 1) {
        int bal, t;
        double r;
        cin >> bal >> r >> t;
        SavingsAccount sa(bal, r, t);
        sa.calculateInterest();
    } else if (type == 2) {
        int bal, fee;
        cin >> bal >> fee;
        CurrentAccount ca(bal, fee);
        ca.calculateInterest();
    } else {
        cout << "Invalid account type." << endl;
    }
    return 0;
}
