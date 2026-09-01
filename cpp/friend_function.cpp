#include <iostream>
using namespace std;

class Test {
    int num1;
    public:
    Test() : num1(10) {}

    friend void fun();
};

void fun() {
    Test t1;
    cout<<"t1.num1: "<<t1.num1<<endl;
}

int main() {
    fun();

    return 0;
}