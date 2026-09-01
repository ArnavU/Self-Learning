#include <iostream>
using namespace std;

class Complex {
    private:
    int real, imag;
    public:
    void displayRecord() {
        cout<<"Real: "<<real<<endl;
        cout<<"Imag: "<<imag<<endl;
    }
};

int main() {
    Complex *c1 = new Complex();

    int* ptr = reinterpret_cast<int*>(c1);
    *ptr = 100;
    ptr++;
    *ptr = 200;
    c1->displayRecord();


    return 0;
}