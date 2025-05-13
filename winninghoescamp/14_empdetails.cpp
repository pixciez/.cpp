#include <iostream>
#include <string>
using namespace std;

class Employee {
private:
    int id;
    string name;
    double salary;

public:
    void setDetails(int empId, string empName, double empSalary) {
        id = empId;
        name = empName;
        salary = empSalary;
    }

    void displayDetails() const {
        cout << "Employee ID: " << id << endl;
        cout << "Employee Name: " << name << endl;
        cout << "Employee Salary: " << salary << endl;
    }
};

int main() {
    Employee emp;
    int id;
    string name;
    double salary;
    cin >> id >> name >> salary;
    emp.setDetails(id, name, salary);
    emp.displayDetails();
    return 0;
}
