#include <iostream>
#include <string>
using namespace std;

class Person
{
protected:
    string name;
    int age;

public:
    Person(string name, int age)
    {
        this->name = name;
        this->age = age;
    }

    void display()
    {
        cout << "Name : " << name << endl;
        cout << "Age  : " << age << endl;
    }

    // Pure virtual function
    virtual void work() = 0;
};


class Student : public Person
{
private:
    int marks;

public:
    Student(string name, int age, int marks)
        : Person(name, age)
    {
        this->marks = marks;
    }

    void study()
    {
        cout << "Student is studying" << endl;
    }

    void work()
    {
        cout << "Student work: Studying" << endl;
    }

    void display()
    {
        Person::display();
        cout << "Marks : " << marks << endl;
    }
};


class Teacher : public Person
{
private:
    double salary;

public:
    Teacher(string name, int age, double salary)
        : Person(name, age)
    {
        this->salary = salary;
    }

    void teach()
    {
        cout << "Teacher is teaching" << endl;
    }

    void work()
    {
        cout << "Teacher work: Teaching" << endl;
    }

    void display()
    {
        Person::display();
        cout << "Salary : " << salary << endl;
    }
};


int main()
{
    Student s1("Rahul", 22, 85);
    Teacher t1("Sharma", 45, 50000);

    cout << "Student Details" << endl;
    s1.display();
    s1.study();

    cout << endl;

    cout << "Teacher Details" << endl;
    t1.display();
    t1.teach();

    cout << endl;

    // Runtime polymorphism
    Person *p;

    p = &s1;
    p->work();       // Student::work()

    p = &t1;
    p->work();       // Teacher::work()

    return 0;
}