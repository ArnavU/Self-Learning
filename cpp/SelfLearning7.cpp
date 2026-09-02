#include <iostream>
#include <string>
using namespace std;

namespace college
{
    class Student
    {
    private:
        int rollNo;
        string name;

    public:
        // Constructor
        Student(int rollNo, string name)
        {
            this->rollNo = rollNo;
            this->name = name;
        }

        // Getters
        int getRollNo()
        {
            return rollNo;
        }

        string getName()
        {
            return name;
        }

        // Setters
        void setRollNo(int rollNo)
        {
            this->rollNo = rollNo;
        }

        void setName(string name)
        {
            this->name = name;
        }

        // Display
        void display()
        {
            cout << "Student Roll No : " << rollNo << endl;
            cout << "Student Name    : " << name << endl;
        }
    };


    class Teacher
    {
    private:
        int teacherId;
        string name;

    public:

        Teacher(int teacherId, string name)
        {
            this->teacherId = teacherId;
            this->name = name;
        }

        int getTeacherId()
        {
            return teacherId;
        }

        string getName()
        {
            return name;
        }

        void setTeacherId(int teacherId)
        {
            this->teacherId = teacherId;
        }

        void setName(string name)
        {
            this->name = name;
        }

        void display()
        {
            cout << "Teacher ID   : " << teacherId << endl;
            cout << "Teacher Name : " << name << endl;
        }
    };
}

int main()
{
    college::Student s1(101, "Rahul");
    college::Teacher t1(501, "Mr. Sharma");

    cout << "Student Details" << endl;
    s1.display();
    cout << endl;
    cout << "Teacher Details" << endl;
    t1.display();

    s1.setName("Amit");
    t1.setName("Mr. Verma");
    cout << "After Updating Names" << endl;
    s1.display();

    t1.display();

    return 0;
}