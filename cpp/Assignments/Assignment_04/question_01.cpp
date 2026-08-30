#include <iostream>
using namespace std;

/*
Q1. Write a class for Time and provide the functionality
Time()
Time(int h,int m,int s)
getHour()
getMinute()
getSeconds()
printTime()
setHour()
setMinute()
setSeconds()
In main create array of objects of Time.
Allocate the memory for the array and the object dynamically.
Write a menu driven code which provides below functionality
1. Add Time
2. Display All Time
3. Display only hrs of all time objects
*/

class Time {
    private: 
    int hrs, mins, secs;

    public:
    Time() : hrs(0), mins(0), secs(0) {}
    Time(int hrs, int mins, int secs) : hrs(hrs), mins(mins), secs(secs) {
        this->hrs = hrs==24 ? 0 : hrs;
        this->mins = mins==60 ? 0 : mins;
        this->secs = secs==60 ? 0 : secs;
    }
    int getHour();
    int getMinute();
    int getSeconds();
    void printTime();
    void setHour(int);
    void setMinute(int);
    void setSeconds(int);
};

int Time :: getHour() { return hrs; } 
int Time :: getMinute() { return mins; } 
int Time :: getSeconds() { return secs; } 
void Time :: printTime() { cout<<"["<<hrs<<":"<<mins<<":"<<secs<<"]"; } 
void Time :: setHour(int hrs) { this->hrs = hrs; } 
void Time :: setMinute(int mins) { this->mins = mins; } 
void Time :: setSeconds(int secs) { this->secs = secs; }

bool isValid(int hrs, int mins, int secs) {
    return !(hrs<0 || hrs>24 || mins<0 || mins>60 || secs<0 || secs>60);
}

void checkAndResizeTimes(int& size, const int idx, Time** &arr) {
    if(idx==size) {
        Time** temp = new Time*[size+10];
        size += 10;
        for(int i=0; i<idx; i++) {
            temp[i] = arr[i];
            delete arr[i];
        }
        delete[] arr;
        arr = NULL;
        arr = temp;
    }
}

int main() {
    int size = 10, idx = 0;
    int choice;
    Time** times = new Time*[size];
    
    start:
    cout<<"\nWelcome the word of times!!! \n\n";
    do {
        cout<<"\nEnter your choice. \n1. Add Time. \n2. Display All Time. \n3. Display only hrs of all time objects.\n\n";
        cin>>choice;

        checkAndResizeTimes(size, idx, times); // resize 
        switch(choice) {
            case(1): { // getting [hrs:mins:secs]
                int hrs, mins, secs;
                cout<<"Enter [hrs mins secs]: ";
                cin>>hrs>>mins>>secs;
                if(!isValid(hrs, mins, secs)) {
                    cout<<"\nPlease enter valid time.\n\n";
                    continue;
                }
                Time* t1 = new Time(hrs, mins, secs);
                times[idx++] = t1;
                break;
            }
            case(2): { // displaying all time
                cout<<"\nAll times:\n";
                for(int i=0; i<idx; i++) {
                    times[i]->printTime();
                    cout<<" ";
                }
                cout<<endl<<endl;
                break;
            }
            case(3) : { // displaying only hrs
                cout<<"\nDisplaying only hours: \n";
                for(int i=0; i<idx; i++) {
                    cout<<times[i]->getHour()<<" ";
                    cout<<" ";
                }
                cout<<endl<<endl;
                break;
            }
            default: {
                char ch;
                cout<<"Are you sure you want to end the program [y/n]: ";
                cin>>ch;
                if(ch=='n') goto start;
                cout<<"\nEnd of the program.\n";
            }
        }
    } while(choice>0 && choice<4);

    for(int i=0; i<idx; i++) {
        delete times[i];
    }
    delete[] times;

    return 0;
}