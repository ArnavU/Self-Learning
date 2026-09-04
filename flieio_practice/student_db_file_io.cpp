#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Student {
private:
    int id;
    string name;
    int age;
    double marks;

public:
    Student() {
        id = 0;
        name = "";
        age = 0;
        marks = 0;
    }

    Student(int id, string name, int age, double marks) {
        this->id = id;
        this->name = name;
        this->age = age;
        this->marks = marks;
    }

    int getId() {
        return id;
    }

    string getName() {
        return name;
    }

    int getAge() {
        return age;
    }

    double getMarks() {
        return marks;
    }

    void accept() {
        cout << "Enter ID: ";
        cin >> id;

        cin.ignore();

        cout << "Enter Name: ";
        getline(cin, name);

        cout << "Enter Age: ";
        cin >> age;

        cout << "Enter Marks: ";
        cin >> marks;
    }

    void display() {
        cout << "ID     : " << id << endl;
        cout << "Name   : " << name << endl;
        cout << "Age    : " << age << endl;
        cout << "Marks  : " << marks << endl;
        cout << "---------------------------" << endl;
    }

    void writeToFile(ofstream& file) {
        file << id << endl;
        file << name << endl;
        file << age << endl;
        file << marks << endl;
    }

    bool readFromFile(ifstream& file) {
        if (!(file >> id))
            return false;

        file.ignore();

        getline(file, name);

        file >> age;
        file >> marks;

        file.ignore();

        return true;
    }
};


// --------------------------------------
// ADD STUDENT
// --------------------------------------

void addStudent() {

    Student s;

    s.accept();

    ofstream file("students.dat", ios::app);

    if (!file) {
        cout << "Error opening file!\n";
        return;
    }

    s.writeToFile(file);

    file.close();

    cout << "\nStudent added successfully!\n";
}


// --------------------------------------
// DISPLAY ALL STUDENTS
// --------------------------------------

void displayStudents() {

    ifstream file("students.dat");

    if (!file) {
        cout << "\nNo student records found.\n";
        return;
    }

    Student s;

    cout << "\n===== STUDENT RECORDS =====\n";

    bool found = false;

    while (s.readFromFile(file)) {
        s.display();
        found = true;
    }

    file.close();

    if (!found) {
        cout << "No student records found.\n";
    }
}


// --------------------------------------
// SEARCH STUDENT
// --------------------------------------

void searchStudent() {

    int searchId;

    cout << "Enter Student ID to search: ";
    cin >> searchId;

    ifstream file("students.dat");

    if (!file) {
        cout << "\nNo student records found.\n";
        return;
    }

    Student s;

    bool found = false;

    while (s.readFromFile(file)) {

        if (s.getId() == searchId) {

            cout << "\nStudent found!\n";
            s.display();

            found = true;
            break;
        }
    }

    file.close();

    if (!found) {
        cout << "\nStudent not found.\n";
    }
}


// --------------------------------------
// UPDATE STUDENT
// --------------------------------------

void updateStudent() {

    int searchId;

    cout << "Enter Student ID to update: ";
    cin >> searchId;

    ifstream file("students.dat");

    if (!file) {
        cout << "\nNo student records found.\n";
        return;
    }

    ofstream temp("temp.dat");

    Student s;

    bool found = false;

    while (s.readFromFile(file)) {

        if (s.getId() == searchId) {

            cout << "\nCurrent record:\n";
            s.display();

            cout << "\nEnter new details:\n";

            Student updated;
            updated.accept();

            // Keep the same ID
            // so the record being updated remains identifiable.

            temp << updated.getId() << endl;
            temp << updated.getName() << endl;
            temp << updated.getAge() << endl;
            temp << updated.getMarks() << endl;

            found = true;
        }
        else {
            s.writeToFile(temp);
        }
    }

    file.close();
    temp.close();

    if (found) {

        remove("students.dat");
        rename("temp.dat", "students.dat");

        cout << "\nStudent updated successfully!\n";
    }
    else {

        remove("temp.dat");

        cout << "\nStudent not found.\n";
    }
}


// --------------------------------------
// DELETE STUDENT
// --------------------------------------

void deleteStudent() {

    int searchId;

    cout << "Enter Student ID to delete: ";
    cin >> searchId;

    ifstream file("students.dat");

    if (!file) {
        cout << "\nNo student records found.\n";
        return;
    }

    ofstream temp("temp.dat");

    Student s;

    bool found = false;

    while (s.readFromFile(file)) {

        if (s.getId() == searchId) {

            found = true;

            // Don't write this record.
            // Therefore it gets deleted.
            continue;
        }

        s.writeToFile(temp);
    }

    file.close();
    temp.close();

    if (found) {

        remove("students.dat");
        rename("temp.dat", "students.dat");

        cout << "\nStudent deleted successfully!\n";
    }
    else {

        remove("temp.dat");

        cout << "\nStudent not found.\n";
    }
}


// --------------------------------------
// MAIN
// --------------------------------------

int main() {

    int choice;

    do {

        cout << "\n";
        cout << "===============================\n";
        cout << "   STUDENT DATABASE SYSTEM\n";
        cout << "===============================\n";

        cout << "1. Add Student\n";
        cout << "2. Display Students\n";
        cout << "3. Search Student\n";
        cout << "4. Update Student\n";
        cout << "5. Delete Student\n";
        cout << "6. Exit\n";

        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice) {

            case 1:
                addStudent();
                break;

            case 2:
                displayStudents();
                break;

            case 3:
                searchStudent();
                break;

            case 4:
                updateStudent();
                break;

            case 5:
                deleteStudent();
                break;

            case 6:
                cout << "\nExiting program...\n";
                break;

            default:
                cout << "\nInvalid choice!\n";
        }

    } while (choice != 6);

    return 0;
}