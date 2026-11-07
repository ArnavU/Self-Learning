#include <iostream>
#include <typeinfo>
using namespace std;

int main1() {
    const int num = 10;
    cout<<num<<endl; // 10

    const int* ptr = &num;
    
    int* ptr2 =  const_cast<int*>(ptr);
    *ptr2 = 20;

    cout<<num<<endl; // 10 || but undefined-behavior
    /** There is no valid way to convert originally 
      * const variable into non-const variable.
      * const_cast<> is useful when we want to change the 
      * pointer-to-const to pointer-to-non-const
    */
    return 0;
}

int main() {
    int num = 20;
    cout<<num<<endl;

    const int* ptr = &num;

    int* ptr2 = const_cast<int*>(ptr);
    *ptr2 = 200;

    cout<<num<<endl;
}