#include <iostream>
using namespace std;

/*
Q1. Create a class Date with data memebrs day,month and year.
Cretae a class Person with data members name,address and birthdate. The birthdate should be of type Date.
Create a class Student with data members id, marks , course and joining date , end date . The joining
date and end date should be of type date.
Implement above classes. Test all functionalities in main().
(Note Only Perform the Association in the above case. No need of Inheritance)
*/

class Date {
    int day, month, year;
    
    public:
    Date() : day(0), month(0), year(0) {}
    Date(int day, int month, int year) : day(day), month(month), year(year) {}
    void setDay(int);
    void setMonth(int);
    void setYear(int);
    void acceptDate();
    int getDay();
    int getMonth();
    int getYear();
    string getDate();
};

void Date :: setDay(int day) { this->day = day; }
void Date :: setMonth(int month) { this->month = month; }
void Date :: setYear(int year) { this->year = year; }
void Date :: acceptDate() {
    cout<<"Enter date parameters [dd mm yyyy]: ";
    cin>>day>>month>>year;
}
int Date :: getDay() { return day; }
int Date :: getMonth() { return month; }
int Date :: getYear() { return year; } 
string Date :: getDate() { return (to_string(day) + "/" + to_string(month) + "/" + to_string(year)); }

class Person {
    string name, address;
    Date birthDate;

    public:
    Person() : name(""), address("") {}
    Person(string name, string address, Date birthDate) : name(name), address(address), birthDate(birthDate) {}
    Person(string name, string address, int day, int month, int year) : name(name), address(address) {
        birthDate = Date(day, month, year);
    }
    void setName(string);
    void setAddress(string);
    void setBirthDate(Date);
    void acceptRecord();
    string getName();
    string getAddress();
    string getBirthDate();
    void displayRecord();
};
void Person :: setName(string name) { this->name = name; }
void Person :: setAddress(string address) { this->address = address; }
void Person :: setBirthDate(Date birthDate) { this->birthDate = birthDate; }
void Person :: acceptRecord() {
    cout<<"Enter student name: ";
    cin>>name;
    cout<<"Enter student address: ";
    cin.ignore();
    getline(cin, address);
    cout<<"Enter birth date of student: ";
    birthDate = Date();
    birthDate.acceptDate();
}
string Person :: getName() { return name; }
string Person :: getAddress() { return address; }
string Person :: getBirthDate() { return birthDate.getDate(); }
void Person :: displayRecord() {
    cout<<"Displaying persosn record: "<<endl;
    cout<<"Name: "<<name<<endl;
    cout<<"Address: "<<address<<endl;
    cout<<"Birth date: "<<birthDate.getDate()<<endl;
}

class Student {
    int id, marks;
    string course;
    Date joiningDate, endDate;
    
    public:
    Student() : id(0), marks(0), course("") {}
    Student(int id, int marks, string course, Date joiningDate, Date endDate) : id(id), marks(marks), course(course) {
        this->joiningDate = joiningDate;
        this->endDate = endDate;
    }
    void setId(int);
    void setMarks(int);
    void setCourse(string);
    void setJoiningDate(int day, int month, int year);
    void setEndDate(int day, int month, int year);
    void acceptRecord();
    int getId();
    int getMarks();
    string getCourse();
    string getJoiningDate();
    string getEndDate();
    void displayRecord();
};
void Student :: setId(int id) { this-> id = id; }
void Student :: setMarks(int marks) { this-> marks = marks; }
void Student :: setCourse(string course) { this->course = course; }
void Student :: setJoiningDate(int day, int month, int year) { joiningDate = Date(day, month, year); }
void Student :: setEndDate(int day, int month, int year) { endDate = Date(day, month, year); }
void Student :: acceptRecord() {
    cout<<"Enter student details: \n";
    cout<<"id: ";
    cin>>id;
    cout<<"Marks: ";
    cin>>marks;
    cout<<"Course: ";
    cin>>course;
    joiningDate = Date();
    endDate = Date();
    cout<<"Enter joining date: \n";
    joiningDate.acceptDate();
    cout<<"Enter end date: \n";
    endDate.acceptDate();
}
int Student :: getId() { return id; }
int Student :: getMarks() { return marks; }
string Student :: getCourse() { return course; }
string Student :: getJoiningDate() { return joiningDate.getDate(); }
string Student :: getEndDate() { return endDate.getDate(); }
void Student :: displayRecord() {
    cout<<"\nDisplaying student record: \n";
    cout<<"Id: "<<id<<endl;
    cout<<"Marks: "<<marks<<endl;
    cout<<"Course: "<<course<<endl;
    cout<<"Joining date: "<<joiningDate.getDate()<<endl;
    cout<<"End date: "<<endDate.getDate()<<endl;
}

namespace menu {
    void activateStudentMenu() {
        int choice;
        Student stu;
        stu.acceptRecord();
        
        do {
            cout<<"\n0. End."<<endl;
            cout<<"1. Display student record."<<endl;
            cout<<"2. Display student marks."<<endl;
            cout<<"3. Display student id."<<endl;
            cout<<"4. Display student course."<<endl;
            cout<<"5. Display course joining date."<<endl;
            cout<<"6. Display course end date."<<endl;
            cout<<"7. Modify id."<<endl;
            cout<<"8. Modify marks."<<endl;
            cout<<"9. Modify course name."<<endl;
            cout<<"10. Modify joining date."<<endl;
            cout<<"11. Modify end date."<<endl<<endl;
            int day, month, year, id, marks;
            string course;
            cin>>choice;
            switch(choice) {
                case(1): {
                    stu.displayRecord();
                    cout<<endl;
                    break;
                } 
                case(2): {
                    cout<<"Marks: "<<stu.getMarks()<<endl;
                    break;
                } 
                case(3): {
                    cout<<"Id: "<<stu.getId()<<endl;
                    break;
                }
                case(4): {
                    cout<<"Course: "<<stu.getCourse()<<endl;
                    break;
                }
                case(5): {
                    cout<<"Course joining date: "<<stu.getJoiningDate()<<endl;
                    break;
                }
                case(6): {
                    cout<<"Course end date: "<<stu.getEndDate()<<endl;
                    break;
                }
                case(7): {
                    cout<<"Enter id: ";
                    cin>>id;
                    stu.setId(id);
                    break;
                }
                case(8): {
                    cout<<"Enter marks: ";
                    cin>>marks;
                    stu.setMarks(marks);
                    break;
                }
                case(9): {
                    cout<<"Enter course: ";
                    cin>>course;
                    stu.setCourse(course);
                    break;
                }
                case(10): {
                    cout<<"Enter new joining date [dd mm yyyy]: ";
                    cin>>day>>month>>year;
                    stu.setJoiningDate(day, month, year);
                    break;
                }
                case(11): {
                    cout<<"Enter new end date [dd mm yyyy]: ";
                    cin>>day>>month>>year;
                    stu.setEndDate(day, month, year);
                    break;
                }
                default: {
                    cout<<"\nStudent record cleared.\n";
                }
            }
        } while(choice>0 && choice<12);
    }

    void activatePersonMenu() {
        // string name, address;
        // Date birthDate;
        int choice;
        Person p;
        p.acceptRecord();
        string name, address;
        Date dob;
        int day, month, year;

        do {
            cout<<"\n0. End."<<endl;
            cout<<"1. Display person record."<<endl;
            cout<<"2. Display person name."<<endl;
            cout<<"3. Display person address."<<endl;
            cout<<"4. Display date of birth."<<endl;
            cout<<"5. Modify person name."<<endl;
            cout<<"6. Modify person address."<<endl;
            cout<<"7. Modify person date of birth."<<endl;

            cin>>choice;
            switch(choice) {
                case 1: {
                    p.displayRecord();
                    cout<<endl;
                    break;
                }
                case 2: {
                    cout<<"Name: "<<p.getName()<<endl;
                    break;
                } 
                case 3: {
                    cout<<"Address: "<<p.getAddress()<<endl;
                    break;
                }
                case 4: {
                    cout<<"Date of birth: "<<p.getBirthDate()<<endl;
                    break;
                }
                case 5: {
                    cout<<"Enter modified name: ";
                    cin>>name;
                    p.setName(name);
                    break;
                }
                case 6: {
                    cout<<"Enter new address: ";
                    cin.ignore();
                    getline(cin, address);
                    p.setAddress(address);
                    break;
                }
                case 7: {
                    cout<<"Enter date of birth [dd mm yyyy]: ";
                    cin>>day>>month>>year;
                    p.setBirthDate(Date(day, month, year));
                    break;
                }
            }
        } while(choice>0 && choice<8);
    }
}

int main() {
    int choice;
    
    do {
        cout<<"0. Exit. \n1. Enter person details. \n2. Enter student details.\n";
        cin>>choice;

        switch(choice) {
            case 1: {
                menu::activatePersonMenu();
                break;
            }
            case 2: {
                menu::activateStudentMenu();
                break;
            }
            default: {
                cout<<"\n\nEnd of the program!!!";
            }
        }
    } while(choice>0 && choice<3);

    return 0;
}