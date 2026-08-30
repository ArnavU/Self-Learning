#include <iostream>
using namespace std;

/*
    Q2. Write a menu driven program for Date in a CPP language using structure and also using class.
    Date is having data members
    day, month, year. Implement the following functions.
    void initDate();
    void printDateOnConsole();
    void acceptDateFromConsole();
    bool isLeapYear();
*/

class Date {
private:
    int day;
    int month;
    int year;

public:
    void initDate();
    void printDateOnConsole();
    void acceptDateFromConsole();
    bool isLeapYear();
};

void Date :: initDate() {
    day = 0;
    month = 0;
    year = 0;
}

void Date :: printDateOnConsole() {
    cout<<"Date entered was: "<<day<<" "<<month<<" "<<year<<endl;
}

void Date :: acceptDateFromConsole() {
    printf("Enter the date (dd mm yyyy): ");
    cin>>day>>month>>year;
}

bool Date :: isLeapYear() {
    return ((year%4==0 && year%100!=0) || year%400==0);
}

int main() {
    int choice;
    Date d;
    d.initDate();

    do {
        cout<<"\nEnter your choice. \n1. Enter date. \n2. Print date. \n3. Check leap year.\n";
        cin>>choice;

        switch(choice) {
            case(1): {
                d.acceptDateFromConsole();
                break;
            }
            case(2): {
                d.printDateOnConsole();
                break;
            } 
            case(3): {
                if(d.isLeapYear()) {
                    cout<<"Entered year is leap year.\n";
                } else {
                    cout<<"Entered year is a normal year.\n";
                }
                break;
            } 
            default: {
                cout<<"End of program.\n";
            }
        }
    } while(choice>0 && choice<4);

    return 0;
}