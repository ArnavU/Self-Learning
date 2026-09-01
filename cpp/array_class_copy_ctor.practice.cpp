#include <bits/stdc++.h>
using namespace std;

class Array {
    private:
    int size;
    int* arr;

    public:
    Array(int size) : size(size) {
        arr = new int[size];
        memset(arr, 0, this->size*sizeof(int));
    }

    Array(const Array &other) {
        this->size = other.size;
        this->arr = new int[this->size];
        memset(this->arr, 0, this->size*sizeof(int));
    }

    void acceptRecord() {
        cout<<"Enter elements: ";
        for(int i=0; i<this->size; i++) {
            cout<<"Element: ";
            cin>>this->arr[i];
        }
    }

    void printRecord() {
        cout<<"Size: "<<size<<endl;
        for(int i=0; i<this->size; i++) {
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
};

int main() {
    Array a1(5);
    Array a2 = a1;
    a2.acceptRecord();
    a2.printRecord();


    return 0;
}