#include<stdio.h>

/*
    Q1. Write a menu driven program for Date in a C. Declare a structure Date having data members
    day, month, year. Implement the following functions.
    void initDate(struct Date* ptrDate);
    void printDateOnConsole(struct Date* ptrDate);
    void acceptDateFromConsole(struct Date* ptrDate);
*/

struct Date {
    int day;
    int month;
    int year;
};

void initDate(struct Date* ptr) {
    ptr->day = 0;
    ptr->month = 0;
    ptr->month = 0;
}

void printDateOnConsole(const struct Date* ptr) {
    printf("Date entered was: %d-%d-%d\n", ptr->day, ptr->month, ptr->year);
}

void acceptDateFromConsole(struct Date* ptr) {
    printf("Enter dd mm yyyy: ");
    scanf("%d%d%d", &ptr->day, &ptr->month, &ptr->year);
}

int main() {
    int choice;
    struct Date d;
    initDate(&d);
    
    do {
        printf("\nEnter your choice: \n1. Enter date. \n2. Print on console. \n3. End\n");
        scanf("%d", &choice);
        switch(choice) {
            case 1: {
                acceptDateFromConsole(&d);
                break;
            }
            case 2: {
                printDateOnConsole(&d);
                break;
            } 
        }
    } while(choice>0 && choice<3);

    printf("End of the program\n");

    

    return 0;
}