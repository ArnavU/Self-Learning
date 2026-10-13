#include <iostream>
using namespace std;

/*
Q2. Imagine a tollbooth at a bridge. Cars passing by the booth are expected to pay a fifty
cent toll.
Mostly they do, but sometimes a car goes by without paying.
The tollbooth keeps track of the number of cars that have gone by and of the total amount of money
collected. Model this tollbooth with a class called tollbooth.
The two data items are a type unsigned int to hold the total number of cars, and a type double to
hold the total amount of money collected
A constructor initializes all data members to 0. A member function called payingCar() increments
the car total and adds 0.50 to the cash total. An other function, called nopayCar()
increments the car total but adds nothing to the cash total. Finally, a member function called
printOnConsole() displays the two totals and number of paying as well as non paying cars total.
*/

class TollBooth {
    private:
    unsigned int cars;
    double collection;

    public:
    TollBooth() : cars(0), collection(0.0) {}

    void payingCar() {
        cars++;
        collection += 0.50;
    }

    void nopayCar() {
        cars++;
    }

    void printOnConsole() {
        double expectedMoney = cars*0.5;
        double diff = expectedMoney - collection;
        int nonPayingCars = diff/0.5;
        int payingCars = cars - nonPayingCars;
        cout<<"Total cars: "<<cars<<endl;
        cout<<"Paying cars: "<<payingCars<<endl;
        cout<<"Non-paying cars: "<<nonPayingCars<<endl;
        cout<<"Total toll collection: "<<collection<<endl;
    }
};

int main() {
    int choice;
    TollBooth tb;
    cout<<"\nWelcome to Karad tollbooth. :)\n\n";
    do {
        cout<<"\nEnter your choice: \n1. Car payed and passed. \n2. Car passed without paying. \n3. End.\n";
        cin>>choice;
        switch(choice) {
            case(1): {
                tb.payingCar();
                break;
            }
            case(2): {
                tb.nopayCar();
                break;
            }
        }
    } while(choice>0 && choice<3);

    cout<<"\n";
    tb.printOnConsole();  
    cout<<"\n";

    return 0;
}