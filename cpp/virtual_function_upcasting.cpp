#include <iostream>
using namespace std;
// clases
// 1. Product
//      price, title
// 2. Tape
//      playTime
// 3. Book
//      pageCount

class Product {
    int price;
    string title;
    
    public:
    Product() : price(0), title("") {}
    Product(int price, string title) : price(price), title(title) {}
    
    virtual void acceptRecord() {
        cout<<"Price: ";
        cin>>price;
        cout<<"Title: ";
        cin>>title;
    }
    virtual void printRecord() {
        cout<<"Price: "<<price<<endl;
        cout<<"Title: "<<title<<endl;
    }
};

class Tape : public Product{
    int playTime;
    
    public:
    Tape() : playTime(0) {}
    Tape(int price, string title, int playTime) : Product(price, title), playTime(playTime) {}

    void acceptRecord() {
        Product::acceptRecord();
        cout<<"Play time: ";
        cin>>playTime;
    }
    void printRecord() {
        cout<<"\nTape: "<<endl;
        Product::printRecord();
        cout<<"Play time: "<<playTime<<endl;
    }
};

class Book : public Product {
    int pageCount;

    public:
    Book() : pageCount(0) {}
    Book(int price, string title, int pageCount) : pageCount(pageCount) {}
    void acceptRecord() {
        Product::acceptRecord();
        cout<<"Page count: ";
        cin>>pageCount;
    }

    void printRecord() {
        cout<<"\nBook: "<<endl;
        Product::printRecord();
        cout<<"Page count: "<<pageCount<<endl;
    }
};

int main() {
    Product *p = new Book();
    p->acceptRecord();
    p->printRecord();
    
    p = new Tape();
    p->acceptRecord();
    p->printRecord();
    
    return 0;
}