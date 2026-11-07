#include<iostream>
using namespace std;

class Array {
private: 
    int size;
    int* arr;
public:
    Array(int size) {
        this->size = size;
        this->arr = new int[this->size];
        for(int i=0; i<this->size; i++) {
            this->arr[i] = 0;
        }
    }

    // copy constructor
    Array(const Array& other) {
        this->size = other.size;
        this->arr = new int[5];
        for(int i=0; i<this->size; i++) 
            this->arr[i] = other.arr[i];
    }

    void acceptRecord() {
        for(int i=0; i<this->size; i++) {
            cout<<"Element "<<i<<": ";
            cin>>this->arr[i];
        }
    }

    void printRecord() {
        for(int i=0; i<size; i++) {
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }

    ~Array() {
        if(this->arr) {
            delete[] arr;
        } 
    }
};

int main() {
    Array arr1(5);
    arr1.acceptRecord();
    arr1.printRecord();

    Array arr2 = arr1;
    arr2.printRecord();

    return 0;
}