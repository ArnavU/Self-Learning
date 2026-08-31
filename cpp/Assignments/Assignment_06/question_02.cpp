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
    Manager(int id, double salary, double bonus) : Employee(id, salary), bonus(bonus) {}
    void setBonus(double);
    double getBonus();
    void acceptManager();
    void displayManager();
};
void Manager :: setBonus(double bonus) { this->bonus = bonus; }
double Manager :: getBonus() { return bonus; }
void Manager :: acceptManager() {
    Employee::accept();
    cout<<"Bonus: ";
    cin>>bonus;
}
void Manager :: displayManager() {
    Employee::display();
    cout<<"Bonus: "<<bonus;
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
void Salesman :: setCommission(double commission) { this->commission = commission; }
double Salesman :: getCommission() { return commission; }
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
    SalesManager(int id, double salary, double bonus, double commission) : Manager(id, salary, bonus), 
                    Salesman(id, salary, commission)  {}

};

int main() {
     ///            id    salary   bonus  commission
    SalesManager sm(1001, 150000, 10000, 100);

    sm.setId(101);
    sm.setSalary(200000);

    sm.setBonus(20000);
    sm.setCommission(5000);

    cout << sm.getId() << endl;
    cout << sm.getSalary() << endl;
    cout << sm.getBonus() << endl;
    cout << sm.getCommission() << endl;

    cout<<"sm.display()"<<endl;
    sm.display();
    cout<<endl<<endl;

    cout<<"sm.displayManager()"<<endl;
    sm.displayManager();
    cout<<endl<<endl;

    cout<<"sm.displaySalesman()"<<endl;
    sm.displaySalesman();
    cout<<endl<<endl;

    cout<<"Size of Salsmanager: "<<sizeof(sm)<<endl<<endl;


    return 0;
}