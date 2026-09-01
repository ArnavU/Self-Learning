#include <iostream>
using namespace std;

class Base {
    private:
    int num1, num2;
    public:
    Base() : num1(0), num2(0) {}
    void setNum1(int num1) {
        this->num1 = num1;
    }
    void setNum2(int num2) {
        this->num2 = num2;
    }
    virtual void printRecord() {
        cout<<"Num1: "<<num1<<endl;
        cout<<"Num2: "<<num2<<endl;
    }
};

class Derived : public Base {
    private:
    int num3;
    public:
    Derived() : num3(0) {}
    void setNum3(int num3) {
        this->num3 = num3;
    }
    void printRecord() {
        Base::printRecord();
        cout<<"Num3: "<<num3<<endl;
    }
};


int main()
{
    Base *ptrBase = new Derived(); //upcasting 
    ptrBase->setNum1(10); 
    ptrBase->setNum2(20); 
    //Derived *ptrDerived = (Derived*)ptrBase; // downcasting  
    Derived *ptrDerived = dynamic_cast<Derived*>(ptrBase); 
    //In case of pointer if, dynamic_cast operator fail to do 
    //downcasting then it returns NULL.
    if(ptrDerived!=NULL)
    {
        ptrDerived->setNum3(30); 
    }
    else 
      cout<<"NULL"<<endl;
    ptrDerived->printRecord( );  
    return 0;
}