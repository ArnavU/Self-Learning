#include<iostream> 
using namespace std; 
class Base 
{
    private: 
    int *bptr; 
    public: 
    Base(void)
    {
        cout<<"Base class ctor called"<<endl; 
        bptr = new int[3]; 
    }
    ~Base( )
    {
        cout<<"Base class dtor called"<<endl; 
        delete[] bptr; 
        bptr = NULL; 
    }
}; 
class Derived : public Base 
{
    private: 
    int *dptr; 
    public: 
    Derived( void )
    {
        dptr = new int[3]; 
        cout<<"Derived class ctor called"<<endl; 
    }
    ~Derived( )
    {
        cout<<"Derived class dtor called"<<endl; 
        delete[] dptr; 
        dptr = NULL; 
    }
}; 
int main()
{
    Base *ptrBase = new Derived( ); //upcasting 
    delete ptrBase; 
    ptrBase = NULL; 
    return 0;
}

int main2()
{
    Derived *ptrDerived = new Derived( ); 
    delete ptrDerived; 
    ptrDerived = NULL; 
    return 0;
}

int main1()
{
    Base *ptrBase = new Base( ); 
    delete ptrBase; 
    ptrBase = NULL; 
    return 0;
}
