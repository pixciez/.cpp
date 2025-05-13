#include <iostream>
#include <string>
using namespace std;

class Student {
protected:
    int rollNumber;
    string name;

public:
    void setStudentDetails(int roll, string studentName) {
        rollNumber = roll;
        name = studentName;
    }

    void displayStudentDetails() const {
        cout << "Roll Number: " << rollNumber << endl;
        cout << "Name: " << name << endl;
    }
};

class Result : public Student {
private:
    int marks[3];

public:
    void setMarks(int m1, int m2, int m3) {
        marks[0] = m1;
        marks[1] = m2;
        marks[2] = m3;
    }

    void displayResult() const {
        int total = marks[0] + marks[1] + marks[2];
        double percentage = total / 3.0;
        cout << "Marks: " << marks[0] << ", " << marks[1] << ", " << marks[2] << endl;
        cout << "Total: " << total << endl;
        cout << "Percentage: " << percentage << "%" << endl;
    }
};

int main() {
    Result student;
    int roll, m1, m2, m3;
    string name;
    cin >> roll >> name >> m1 >> m2 >> m3;
    student.setStudentDetails(roll, name);
    student.setMarks(m1, m2, m3);
    student.displayStudentDetails();
    student.displayResult();
    return 0;
}
 