#include <bits/stdc++.h>
using namespace std;

class Employee {
    int empId;
    string name;
    double salary;

    public:
    Employee() : empId(0), name(""), salary(0.l) {}
    Employee(int empId, string name, double salary) : empId(empId), name(name), salary(salary) {}

    void setEmpid(int empId) { this->empId = empId; }
    void setName(int name) { this->name = name; }
    int getEmpId() { return this->empId; }
    string getName() { return this->name; }
    double getSalary() { return this->salary; }

    void accept() {
        cout<<"EmpId: ";
        cin>>empId;
        cout<<"Name: ";
        cin>>name;
        cout<<"Salary: ";
        cin>>salary;
    }
};

void write(Employee emp) {
    ofstream fout("./demo/demo2.txt");
    fout<<emp.getEmpId()<<", "<<emp.getName()<<", "<<emp.getSalary();
    fout.close();
}

void read() {
    ifstream fin("./demo/demo2.txt");
    string str;
    getline(fin, str, ',');
    cout<<"Emp id: "<<stoi(str)<<endl;
    getline(fin, str, ',');
    cout<<"Emp name: "<<str<<endl;
    getline(fin, str, ',');
    cout<<"Emp salary: "<<stod(str)<<endl;
}

int main() {
    Employee emp;
    emp.accept();

    write(emp);
    // read();
    
    return 0;
}