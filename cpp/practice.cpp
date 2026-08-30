#include <iostream>
using namespace std;

int divide(int a, int b) {
    return a/b;
}

float divide(int a, int b) {
    return (float)a/b;
}

int main() {
    int res = divide(10, 2);
    float res2 = divide(10, 2);

    return 0;
}