
#include <iostream>
#include <string>
using namespace std;

const int MAX_STUDENTS = 100;

class Student {
public:
    int rollNo;
    string name;
    float marks;

    void input() {
        cout << "Enter Roll Number: ";
        cin >> rollNo;

        cout << "Enter Student Name: ";
        getline(cin >> ws, name);

        cout << "Enter Marks (out of 100): ";
        cin >> marks;
    }

    void display() {
        cout << "\nRoll Number: " << rollNo;
        cout << "\nName: " << name;
        cout << "\nMarks: " << marks;
        cout << "\nGrade: ";

        if (marks >= 90)
            cout << "A+";
        else if (marks >= 80)
            cout << "A";
        else if (marks >= 70)
            cout << "B";
        else if (marks >= 60)
            cout << "C";
        else if (marks >= 40)
            cout << "D";
        else
            cout << "Fail";

        cout << "\n-------------------------\n";
    }
};

int main() {
    Student students[MAX_STUDENTS];
    int count = 0;
    int choice;

    do {
        cout << "\n===== STUDENT MANAGEMENT SYSTEM =====\n";
        cout << "1. Add Student\n";
        cout << "2. Display All Students\n";
        cout << "3. Search Student by Roll Number\n";
        cout << "4. Exit\n";
        cout << "Enter Your Choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            if (count < MAX_STUDENTS) {
                students[count].input();
                count++;
                cout << "\nStudent Added Successfully!\n";
            } else {
                cout << "\nStudent Limit Reached!\n";
            }
            break;

        case 2:
            if (count == 0) {
                cout << "\nNo Students Found!\n";
            } else {
                for (int i = 0; i < count; i++) {
                    students[i].display();
                }
            }
            break;

        case 3: {
            int searchRoll;
            bool found = false;

            cout << "Enter Roll Number to Search: ";
            cin >> searchRoll;

            for (int i = 0; i < count; i++) {
                if (students[i].rollNo == searchRoll) {
                    students[i].display();
                    found = true;
                    break;
                }
            }

            if (!found) {
                cout << "\nStudent Not Found!\n";
            }
            break;
        }

        case 4:
            cout << "\nThank You for Using the System!\n";
            break;

        default:
            cout << "\nInvalid Choice! Try Again.\n";
        }

    } while (choice != 4);

    return 0;
}
