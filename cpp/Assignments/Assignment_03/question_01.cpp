#include <iostream>
using namespace std;

/*
Q1. Write a class to find volume of a Cylinder by using following members. (volume of
Cy linder=3.14 * radius * radius *height) ( use static wherever needed. hint PI)
Class having following member functions:
Cylinder()
Cylinder(double radius, double height)
getRadius()
setRadius()
getHeight()
setHeight()
calculateVolume()
Initialize members using constructor member initializer list.
*/

class Cylinder {
    private:
    double radius;
    double height;
    const static double PI; // const  -> variable cannot be modified
                            // static -> single variable shared by all the instances

    public:
    Cylinder() : radius(0), height(0) {}
    Cylinder(double radius, double height) : radius(radius), height(height) {}

    double getRadius() const {
        return radius;
    }

    void setRadius(double radius) {
        this->radius = radius;
    }

    double getHeight() const {
        return height;
    }

    void setHeight(double height) {
        this->height = height;
    }

    double calculateVolume() {
        return PI * radius * radius * height;
    }
};

const double Cylinder :: PI = 3.14;

int main() {
    Cylinder c1;
    Cylinder c2(3.0, 8.0);
    cout<<"Volume of the cylinder c2 r("<<c2.getRadius()<<") h("<<c2.getHeight()<<") is: "<<c2.calculateVolume()<<endl;

    c1.setHeight(5.3);
    c1.setRadius(8.0);
    cout<<"Volume of the cylinder c1 r("<<c1.getRadius()<<") h("<<c1.getHeight()<<") is: "<<c1.calculateVolume()<<endl;


    return 0;
}