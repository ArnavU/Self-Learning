#include <iostream>
using namespace std;

class Programmer
{
public:
    Programmer()
    {
        cout << "Programmer constructor called" << endl;
    }

    void work()
    {
        cout << "Programmer is working" << endl;
    }
};

class Teacher
{
public:
    Teacher()
    {
        cout << "Teacher constructor called" << endl;
    }

    void work()
    {
        cout << "Teacher is teaching" << endl;
    }
};

class ProgrammingTeacher : public Programmer, public Teacher
{
public:
    ProgrammingTeacher()
    {
        cout << "ProgrammingTeacher constructor called" << endl;
    }
};

int main()
{
    ProgrammingTeacher pt;
    
    // pt.work();   // ERROR: ambiguous

    // Resolve ambiguity using scope resolution operator
    pt.Programmer::work();

    pt.Teacher::work();

    return 0;
}