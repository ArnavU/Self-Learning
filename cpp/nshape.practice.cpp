#include <iostream>
using namespace std;

namespace nShape {
    enum ShapeType {
        EXIT,
        RECTANGLE,
        CIRCLE
    };

    class Shape {
        protected:
        double area;

        public:
        Shape() : area(0) {}
        virtual void calculateArea() = 0;
        void displayRecord() {
            cout<<"Area: "<<area<<endl;
        }
    };

    class Rectangle : public Shape {
        double length, breadth;

        public:
        Rectangle() : length(0), breadth(0) {}
        Rectangle(double length, double breadth) : length(length), breadth(breadth) {}
        void setLength(double length) { this->length = length; }
        void setBreadth(double breadth) { this->breadth = breadth; }
        double getBreadth() { return breadth; }
        double getLength() { return length; }

        void calculateArea() {
            area = length * breadth;
        }
    };

    class Math {
        public:
        static const double PI;
        static double pow(double x, int n) {
            double result = 1.0;
            for(int i=0; i<n; i++) {
                result *= x;
            }
            return result;
        }
    };
    const double Math :: PI = 3.14;

    class Circle : public Shape {
        double radius;
        public:
        Circle() : radius(0.0) {}
        Circle(double radius) : radius(radius) {}
        
        void setRadius(double radius) { this->radius = radius; }
        double getRadius() { return radius; }
        void calculateArea() {
            area = Math::PI * Math::pow(radius, 2);
        }
    };

    ShapeType menuList() {
        int choice;
        cout << "0.Exit" << endl;
        cout << "1.Rectangle" << endl;
        cout << "2.Circle" << endl;
        cout << "Enter the choice : ";
        cin >> choice;
        return ShapeType(choice);
    }

    class ShapeFactory {
        public:
        static Shape* getInstance(ShapeType choice) {
            Shape* shapePtr = NULL;
            switch(choice) {
                case RECTANGLE:
                    shapePtr = new Rectangle();
                    break;
                case CIRCLE:
                    shapePtr = new Circle();
                    break;
            }
            return shapePtr;
        }
    };
}
using namespace nShape;

void acceptRecord(Shape* ptr) {
    if(dynamic_cast<Rectangle*>(ptr) != NULL) {
        Rectangle* rect = dynamic_cast<Rectangle*>(ptr);
        double length, breadth;
        cout<<"Enter length: ";
        cin>>length;
        cout<<"Enter breadth: ";
        cin>>breadth;
        rect->setBreadth(breadth);
        rect->setLength(length);
    } else if(dynamic_cast<Circle*>(ptr) != NULL) {
        Circle* circ = dynamic_cast<Circle*>(ptr);
        cout<<"Enter radius: ";
        double radius;
        cin>>radius;
        circ->setRadius(radius);
    }
}

int main() {
    ShapeType choice;
    Shape* shapePtr = NULL;
    while((choice = menuList()) != 0) {
        switch(choice) {
            case RECTANGLE:
                shapePtr = ::ShapeFactory::getInstance(choice);
                break;
            case CIRCLE: 
                shapePtr = ::ShapeFactory::getInstance(choice);
                break;
        }
        if(shapePtr != NULL) {
            ::acceptRecord(shapePtr);
            shapePtr->calculateArea();
            shapePtr->displayRecord();
            delete shapePtr;
            shapePtr = NULL;
        }
    }
    

    return 0;
}