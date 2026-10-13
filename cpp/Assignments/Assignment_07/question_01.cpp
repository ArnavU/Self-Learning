#include <iostream>
using namespace std;

class Employee {
    int id;
    double salary;

    public:
    Employee() : id(0), salary(0.0) {}
    Employee(int id, double salary) : id(id), salary(salary) {}  
    void setId(int);
    int getId();
    void setSalary(double);
    double getSalary();
    void accept();
    void display();
};

void Employee :: setId(int id) { this->id = id; }
int Employee :: getId() { return id; }
void Employee :: setSalary(double salary) { this->salary = salary; }
double Employee :: getSalary() { return salary; }

void Employee :: accept() {
    cout<<"Id: ";
    cin>>id;
    cout<<"Salary: ";
    cin>>salary;
}

void Employee :: display() {
    cout<<"Id: "<<id<<endl;
    cout<<"Salary: "<<salary<<endl;
}


class Manager : virtual public Employee {
    double bonus;

    public:
    Manager() : Employee(), bonus(0) {}

    Manager(int id, double salary, double bonus)
        : Employee(id, salary), bonus(bonus) {}

    void setBonus(double);
    double getBonus();
    void acceptManager();
    void displayManager();
};

void Manager :: setBonus(double bonus) {
    this->bonus = bonus;
}

double Manager :: getBonus() {
    return bonus;
}

void Manager :: acceptManager() {
    Employee::accept();

    cout<<"Bonus: ";
    cin>>bonus;
}

void Manager :: displayManager() {
    Employee::display();
    cout<<"Bonus: "<<bonus<<endl;
}


class Salesman : virtual public Employee {
    double commission;

    public:
    Salesman() {}

    Salesman(int id, double salary, double comission) {}

    void setCommission(double);
    double getCommission();
    void acceptSalesman();
    void displaySalesman();
};

void Salesman :: setCommission(double commission) {
    this->commission = commission;
}

double Salesman :: getCommission() {
    return commission;
}

void Salesman :: acceptSalesman() {
    Employee::accept();

    cout<<"Commission: ";
    cin>>commission;
}

void Salesman :: displaySalesman() {
    Employee::display();
    cout<<"Commission: "<<commission<<endl;
}


class SalesManager : public Manager, public Salesman {
    public:
    SalesManager() {}

    SalesManager(int id, double salary, double bonus, double commission)
        : Manager(id, salary, bonus),
          Salesman(id, salary, commission) {}

};


int menuList()
{
    int choice;

    cout<<endl;
    cout<<"0. EXIT"<<endl;
    cout<<"1. Add Manager"<<endl;
    cout<<"2. Add Salesman"<<endl;
    cout<<"3. Add SalesManager"<<endl;
    cout<<"4. Display count of all employees with respect to designation"<<endl;
    cout<<"5. Display All Managers"<<endl;
    cout<<"6. Display All Salesman"<<endl;
    cout<<"7. Display All SalesManagers"<<endl;

    cout<<"Enter choice : ";
    cin>>choice;

    return choice;
}


int main()
{
    Manager *ptrMan[5];
    Salesman *ptrSal[5];
    SalesManager *ptrSM[5];

    int mCount = 0;
    int sCount = 0;
    int smCount = 0;

    int choice;

    while((choice = menuList()) != 0)
    {
        switch(choice)
        {
            case 1:
            {
                if(mCount < 5)
                {
                    ptrMan[mCount] = new Manager();

                    ptrMan[mCount]->acceptManager();

                    mCount++;
                }
                else
                {
                    cout<<"Manager array is full"<<endl;
                }

                break;
            }

            case 2:
            {
                if(sCount < 5)
                {
                    ptrSal[sCount] = new Salesman();

                    ptrSal[sCount]->acceptSalesman();

                    sCount++;
                }
                else
                {
                    cout<<"Salesman array is full"<<endl;
                }

                break;
            }

            case 3:
            {
                if(smCount < 5)
                {
                    ptrSM[smCount] = new SalesManager();

                    ptrSM[smCount]->Employee::accept();

                    double x;
                    double y;

                    cout<<"Bonus: ";
                    cin>>x;

                    cout<<"Commission: ";
                    cin>>y;

                    ptrSM[smCount]->setBonus(x);
                    ptrSM[smCount]->setCommission(y);

                    smCount++;
                }
                else
                {
                    cout<<"SalesManager array is full"<<endl;
                }

                break;
            }

            case 4:
            {
                cout<<"Total Managers : "<<mCount<<endl;
                cout<<"Total Salesman : "<<sCount<<endl;
                cout<<"Total SalesManagers : "<<smCount<<endl;

                break;
            }

            case 5:
            {
                for(int i = 0; i < mCount; i++)
                {
                    cout<<endl;
                    cout<<"Manager "<<i+1<<endl;
                    ptrMan[i]->displayManager();
                }

                break;
            }

            case 6:
            {
                for(int i = 0; i < sCount; i++)
                {
                    cout<<endl;
                    cout<<"Salesman "<<i+1<<endl;
                    ptrSal[i]->displaySalesman();
                }

                break;
            }

            case 7:
            {
                for(int i = 0; i < smCount; i++)
                {
                    cout<<endl;
                    cout<<"SalesManager "<<i+1<<endl;

                    ptrSM[i]->Employee::display();
                    cout<<"Bonus: "<<ptrSM[i]->getBonus()<<endl;
                    cout<<"Commission: "<<ptrSM[i]->getCommission()<<endl;
                }

                break;
            }

            default:
            {
                cout<<"Wrong choice"<<endl;
            }
        }
    }

    return 0;
}