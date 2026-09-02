#include <iostream>
using namespace std;

struct Student {
	int rollNo;
	float marks;
};

int main() {
	int numberOfStudents;

	cout << "Enter number of students: ";
	cin >> numberOfStudents;

	Student* students = new Student[numberOfStudents];

	for (int i = 0; i < numberOfStudents; i++) {
		cout << "Enter roll number and marks for student " << i + 1 << ": ";
		cin >> students[i].rollNo >> students[i].marks;
	}

	cout << "Student records:"<<endl;
	float highestMarks = students[0].marks;

	for (int i = 0; i < numberOfStudents; i++) {
		cout << "Roll No: " << students[i].rollNo
			 << ", Marks: " << students[i].marks << endl;

		if (students[i].marks > highestMarks) {
			highestMarks = students[i].marks;
		}
	}

	cout << "Highest marks: " << highestMarks << endl;

	delete[] students;

	return 0;
}
