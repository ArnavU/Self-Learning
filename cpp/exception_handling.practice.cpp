#include <iostream>
using namespace std;

void acceptRecord(string msg, int& num) {
    cout<<msg;
    cin>>num;
}

class ArithmeticException {
    private:
    string message;
    public:
    ArithmeticException(string message) {
        this->message = message;
    }
    string getMessage() {
        return this->message;
    }
};

int main() {
    int num1;
    ::acceptRecord("num1: ", num1);

    int num2;
    ::acceptRecord("num2: ", num2);

    try {
        if(num2 == 0) {
            throw ArithmeticException("Divide by 0.");
        }
        else {
            cout<<"Result: "<<num1/num2<<endl;
        }    
    } catch(ArithmeticException ex) {
        cout<<"Exception occured: "<<ex.getMessage()<<endl;
    }

    return 0;
}