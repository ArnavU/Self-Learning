
function Person(name, mobile) {
    this.name = name;
    this.mobile = mobile;
}

function Employee(name, mobile, empId, salary) {
    Person.call(this, name, mobile);
    this.empId = empId;
    this.salary = salary;
}

Object.setPrototypeOf(Employee.prototype, Person.prototype);

Person.prototype.display = function() {
    console.log(`Name: ${this.name}`);
    console.log(`Mobile: ${this.mobile}`);
}

Employee.prototype.display = function() {
    Object.getPrototypeOf(Employee.prototype).display.call(this);
    console.log(`EmpId: ${this.empId}`);
    console.log(`Salary: ${this.salary}`);
}

let e = new Employee("Ram", "832932", 111, 50000.99);
console.log(e);
e.display();