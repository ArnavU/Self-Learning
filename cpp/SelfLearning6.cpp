#include <iostream>
#include <string>
using namespace std;

class BankAccount
{
private:
    long long accountNumber;
    string accountHolderName;
    double balance;

public:
    BankAccount(long long accountNumber, string accountHolderName, double balance) : accountNumber(accountNumber), accountHolderName(accountHolderName), balance(balance)
    {
    }

    void deposit(double amount)
    {
        balance = balance + amount;
    }

    void withdraw(double amount)
    {
        if(amount <= balance)
        {
            balance = balance - amount;
        }
        else
        {
            cout << "Insufficient balance" << endl;
        }
    }

    void displayBalance()
    {
        cout << "Account Number : " << accountNumber << endl;
        cout << "Account Holder : " << accountHolderName << endl;
        cout << "Balance : " << balance << endl;
    }
};

int main()
{
    BankAccount account(101, "Rahul", 5000);

    account.displayBalance();
    account.deposit(2000);
    account.withdraw(1000);
    account.displayBalance();

    return 0;
}