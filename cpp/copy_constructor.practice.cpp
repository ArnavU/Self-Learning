#include <iostream>
using namespace std;

class Complex {
    private: 
    int real, imag;
    public:
    Complex() : real(0), imag(0) {}
    Complex(int real, int imag) : real(real), imag(imag) {}

    Complex(const Complex &other) {
        this->real = other.real + 1;;
        this->imag = other.imag + 1;
    }

    void printRecord() {
        cout<<"Real: "<<real<<endl;
        cout<<"Imag: "<<imag<<endl;
    }
};

int main() {
    Complex c1(10, 20);
    c1.printRecord();

    Complex c2 = c1;
    c2.printRecord();

    return 0;
}