class Date {
    constructor(day, month, year) {
        this.day = day;
        this.month = month;
        this.year = year;
    }
    display() {
        console.log(`${this.day}/${this.month}/${this.year}`)
    }
}

class Person {
    constructor(name, mobile, day, month, year) {
        this.name = name;
        this.mobile = mobile;
        this.dob = new Date(day, month, year);
    }
    display() {
        console.log(`Name: ${this.name}`);
        console.log(`Mobile: ${this.mobile}`);
        this.dob.display();
    }
}

class Employee extends Person {
    constructor(name, mobile, day, month, year, empId, salary) {
        super(name, mobile, day, month, year);
        this.empId = empId;
        this.salary = salary;
    }
    display() {
        super.display();
        console.log(`EmpId: ${this.empId}`);
        console.log(`Salary: ${this.salary}`);
    }
}

const e1 = new Employee("Ram", "801048", 30, 1, 2003, 101, 9999.99);
console.log(e1);
e1.display();