#include <iostream>
using namespace std;

/*
Q1. Write a menu driven program to calculate volume of the box(length * width * height).
Provide parameterless, parameterized(with 3 parameters) and single
paramaterized constructor.
Create the local objects in respective case and call the function to caluclate area.
Menu options
-->
1. Calculate Volume with default values
2. Calculate Volume with length,breadth and height with same value
3. Calculate Volume with different length,breadth and height values.
*/

class Box {
    private:
    int length;
    int breadth;
    int height;

    public:
    Box() : length(0), breadth(0), height(0) {}
    Box(int l, int b, int h) : length(l), breadth(b), height(h) {}
    Box(int val) : length(val), breadth(val), height(val) {}

    int calcVolume() {
        return length*breadth*height;
    }
};

int main() {
    int choice;
    do {
        cout<<"\nEnter your choice. \n1. Calculate Volume with default values \n2. Calculate Volume with length,breadth and height with same value. \n3. Calculate Volume with different length,breadth and height values. \n4. End.\n";
        cin>>choice;
        int l; int b; int h;

        switch(choice) {
            case(1): {
                Box b;
                cout<<"Volume of the box with default values: "<<b.calcVolume()<<endl;
                break;
            }
            case(2): {
                cout<<"Enter length, bredth and height: ";
                cin>>l>>b>>h;
                Box b2(l, b, h);
                cout<<"Volume of the box with length, bredth, and height: "<<b2.calcVolume()<<endl;
                break;
            }
            case(3): {
                int val;
                cout<<"Enter single value: ";
                cin>>val;
                Box b3(val);
                cout<<"Volume of box with same dimensions: "<<b3.calcVolume()<<endl;
                break;
            }
            default: {
                cout<<"\n End of the program."<<endl;
            }
        }
    } while(choice>0 && choice<4);

    return 0;
}