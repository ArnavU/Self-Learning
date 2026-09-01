#include <iostream>
#include <typeinfo>
using namespace std;

class Shape {
    protected:
    double area;
    
    public:
    virtual void calculateArea() = 0;

    void displayRecord() {
        cout<<"Area is: "<<area<<endl;
    }
};

class Rectangle : public Shape {
    int length, breadth;
    public:
    Rectangle() : length(0), breadth(0) {}
    void setLength(int length) {
        this->length = length;
    }
    int getLength() {
        return length;
    }
    void setBreadth(int breadth) {
        this->breadth = breadth;
    }
    int getBreadth() {
        return breadth;
    }
    void calculateArea() {
        area = length * breadth;

    }
};

class Math {
    public:
    static const double PI;
    static double pow(double base, int n) {
        double result = 1;
        for(int i=0; i<n; i++) {
            result = (double)result * base;
        }
        return result;
    }
};
const double Math::PI = 3.14f;

class Circle : public Shape {
    int radius;
    public: 
    Circle() : radius(0) {}
    int getRadius() {
        return this->radius;
    }
    void setRadius(int radius) {
        this->radius = radius;
    }
    void calculateArea() {
        area = Math::PI * Math::pow(radius, 2);
    }
};

int menuList() {
    int choice;
    cout<<"\n0. Exit."<<endl;
    cout<<"1. Rectangle."<<endl;
    cout<<"2. Circle."<<endl;
    cin>>choice;
    return choice;
}

void acceptRecord(Shape* shape) {
    if(typeid(*shape) == typeid(Rectangle)) {
        int length, breadth;
        Rectangle* rect = (Rectangle*)shape;
        cout<<"Length: ";
        cin>>length;
        rect->setLength(length);
        cout<<"Breadth: ";
        cin>>breadth;
        rect->setBreadth(breadth);
    } else {
        int radius;
        Circle* circ = (Circle*)shape;
        cout<<"Radius: ";
        cin>>radius;
        circ->setRadius(radius);
    }
}

int main() {
    int choice;
    Shape* shape;
    while((choice = ::menuList()) != 0) {
        switch(choice) {
            case 1: 
                shape = new Rectangle();
                break;
            case 2: 
                shape = new Circle();
                break;
        }
        if(shape != NULL) {
            ::acceptRecord(shape);
            shape->calculateArea();
            shape->displayRecord();
        }
    }

    return 0;
}