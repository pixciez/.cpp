#include <iostream>
using namespace std;

int calculateSalary(int stipend) {
    return stipend;
}

int calculateSalary(int baseSalary, int bonuses) {
    return baseSalary + bonuses;
}

int calculateSalary(int baseSalary, int bonuses, int incentives) {
    return baseSalary + bonuses + incentives;
}

int main() {
    int stipend, baseSalary1, bonuses1, baseSalary2, bonuses2, incentives;
    cin >> stipend >> baseSalary1 >> bonuses1 >> baseSalary2 >> bonuses2 >> incentives;
    cout << "Intern Salary: " << calculateSalary(stipend) << endl;
    cout << "Employee Salary: " << calculateSalary(baseSalary1, bonuses1) << endl;
    cout << "Manager Salary: " << calculateSalary(baseSalary2, bonuses2, incentives) << endl;
    return 0;
}
