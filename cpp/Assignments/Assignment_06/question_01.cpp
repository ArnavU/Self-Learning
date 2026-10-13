#include <iostream>
using namespace std;

/*
Q1. A shop sells book or tapes. The Book class holds id, title, author, and price; whereas Tape class
holds id, title, artist, and price. There is 5% discount on tapes, while 10% discount on books.
Assuming that each user purchase 3 products (either book or tape), calculate final bill. The program should be menu driven and should not cause memory leakage.
Hint: Create class Product and inherit into Book and Tape. Also create array like Product* arr[3]
*/

class Product {
    int id, discount;
    string title;
    double price;

    public: 
    Product() : id(0), title(""), price(0.0), discount(0) {}
    Product(int id, string title, double price, int discount) : id(id), title(title), price(price), discount(discount) {}

    void setDiscount(int discount) {
        this->discount = discount;
    }

    virtual void acceptRecord() {
        cout<<"Id: ";
        cin>>id;
        cout<<"Title: ";
        cin>>title;
        cout<<"Price: ";
        cin>>price;
    }

    virtual void printRecord() {
        cout<<"Id: "<<id<<endl;
        cout<<"Discount: "<<discount<<endl;
        cout<<"Title: "<<title<<endl;
        cout<<"Price: "<<price<<endl;
    }

    double calculatePrice() {
        return price * (100-discount)/100.0;
    }
    
};

class Book : public Product {
    string author;

    public:
    Book() : author("") {}
    Book(int id, int discount, string title, double price) : Product(id, title, price, 10), author(author) { }

    void acceptRecord() {
        Product::acceptRecord();
        setDiscount(10);
        cout<<"Author: ";
        cin>>author;
    }

    void printRecord() {
        Product::printRecord();
        cout<<"Author: "<<author<<endl;
        cout<<"Price: "<<calculatePrice()<<endl;
    }

};

class Tape : public Product {
    string artist;

    public:
    Tape() : artist("") {}
    Tape(int id, int discount, string title, double price) : Product(id, title, price, 5), artist(artist) { } 
    
    void acceptRecord() {
        setDiscount(5);
        Product::acceptRecord();
        cout<<"Artist: ";
        cin>>artist;
    }

    void printRecord() {
        Product::printRecord();
        cout<<"Artist: "<<artist<<endl;
        cout<<"Price: "<<calculatePrice()<<endl;
    }
};


int main() {
    int choice;
    Product* arr[3] = {NULL, NULL, NULL};
    int idx = 0;
    
    do {
        cout<<"\n0. End."<<endl;
        cout<<"1. Buy book."<<endl;
        cout<<"2. Buy tape."<<endl<<endl;
        cin>>choice;

        switch(choice) {
            case(1): {
                arr[idx] = new Book();
                arr[idx]->acceptRecord();
                idx++;
                break;
            }
            case(2): {
                arr[idx] = new Tape();
                arr[idx]->acceptRecord();
                idx++;
                break;
            }
        } 
    } while(choice<3 && idx<3);

    double totalBill = 0.0;
    cout<<"\nPurchase Summary: "<<endl;
    for(int i=0; i<idx; i++) {
        totalBill += arr[i]->calculatePrice();
        arr[i]->printRecord();
        delete arr[i];
        cout<<endl;
    }
    cout<<"Total bill: "<<totalBill<<endl<<endl;    

    return 0;
}