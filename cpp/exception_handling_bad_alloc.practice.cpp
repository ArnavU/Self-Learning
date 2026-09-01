#include <iostream>
using namespace std;

int main() {
    try {
        int* ptr = new int(10);
        cout<<"Int value: "<<*ptr<<endl;
        delete ptr;
        ptr = nullptr;
    } catch(bad_alloc ex) {
        cout<<"Bad memory allocation exception: "<<endl;
    }

    return 0;
}