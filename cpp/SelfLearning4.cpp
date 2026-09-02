// Laptop class implementation
#include <iostream>
using namespace std;

class Laptop {
private:
	int brandId;
	int price;

public:
	Laptop():brandId(1) , price(5000) {
		cout << "Laptop Constructor Called" << endl;
	}

    
	void display() {
        cout << "Brand ID: " << brandId << endl;
		cout << "Price: " << price << endl;
	}

    ~Laptop() {
        cout << "Laptop Destructor Called" << endl;
    }
};

int main() {
	Laptop laptop;
	laptop.display();
	return 0;
}
