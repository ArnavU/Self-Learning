#include<iostream>
using namespace std;

inline int factorial(int number){
    int result = 1;
    for(int i = 1; i <= number; i++){
        result *= i;
    }
    return result;
}

inline int power(int base, int exponent){
    int result = 1;
    for(int i = 1; i <= exponent; i++){
        result *= base;
    }
    return result;
}

int main(){
    int number, base, exponent;

    cin >> number >> base >> exponent;

    cout << "Factorial: " << factorial(number) << endl;
    cout << "Power: " << power(base, exponent) << endl;

    return 0;
}