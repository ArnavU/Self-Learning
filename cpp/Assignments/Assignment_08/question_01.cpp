/* Q1. Write a class Distance to hold feet and inches. Overload opera
tor + as member function . Also,
overload ++ operator (to increment inches) as member function and op erator as friend function.
Overload << and >> operators to accept and display distance. */

#include <iostream>
using namespace std;

class Distance
{
private:
    int feet;
    int inches;

    // Normalize inches so that inches < 12
    void normalize()
    {
        feet += inches / 12;
        inches %= 12;

        if (inches < 0)
        {
            feet--;
            inches += 12;
        }
    }

public:

    Distance() : feet(0), inches(0)
    {
    }

    Distance(int feet, int inches)
        : feet(feet), inches(inches)
    {
        normalize();
    }

    // Operator + as MEMBER function
    Distance operator+(const Distance& other)
    {
        Distance temp;

        temp.feet = this->feet + other.feet;
        temp.inches = this->inches + other.inches;

        temp.normalize();

        return temp;
    }

    // Prefix ++ as MEMBER function
    Distance& operator++()
    {
        inches++;
        normalize();

        return *this;
    }

    // Postfix ++ as MEMBER function
    Distance operator++(int)
    {
        Distance temp = *this;

        inches++;
        normalize();

        return temp;
    }

    // Friend operator -- 
    friend Distance& operator--(Distance& d);

    // Friend insertion operator <<
    friend ostream& operator<<(ostream& out, const Distance& d);

    // Friend extraction operator >>
    friend istream& operator>>(istream& in, Distance& d);
};


// Friend -- operator
Distance& operator--(Distance& d)
{
    d.inches--;

    d.normalize();

    return d;
}


// Friend << operator
ostream& operator<<(ostream& out, const Distance& d)
{
    out << d.feet << " feet " << d.inches << " inches";
    return out;
}


// Friend >> operator
istream& operator>>(istream& in, Distance& d)
{
    cout << "Enter feet: ";
    in >> d.feet;

    cout << "Enter inches: ";
    in >> d.inches;

    d.normalize();

    return in;
}


int main()
{
    Distance d1(5, 8);
    Distance d2(3, 7);

    Distance d3 = d1 + d2;

    cout << "d1 = " << d1 << endl;
    cout << "d2 = " << d2 << endl;
    cout << "d1 + d2 = " << d3 << endl;

    ++d1;
    cout << "After ++d1: " << d1 << endl;

    d1++;
    cout << "After d1++: " << d1 << endl;

    --d2;
    cout << "After --d2: " << d2 << endl;

    Distance d4;
    cin >> d4;

    cout << "Entered distance: " << d4 << endl;

    return 0;
}