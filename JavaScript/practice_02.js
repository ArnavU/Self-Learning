
function Person(name, mobile) {
    this.name = name;
    this.mobile = mobile;
}

function Employee(name, mobile, empId, salary) {
    Person.call(this, name, mobile);
    this.empId = empId;
    this.salary = salary;
}

Employee.prototype.displayEmployee = function() {
    console.log(`EmpId: ${this.empId}`);
    console.log(`Salary: ${this.salary}`);
    this.displayPerson();
}

Person.prototype.displayPerson = function() {
    console.log(`Name: ${this.name}`); 
    console.log(`Mobile: ${this.mobile}`);
}

Object.setPrototypeOf(Employee.prototype, Person.prototype);
// Employee.prototype.prototype = Person.prototype;  // not possible must be modified through setters only

// let p1 = new Person("Arnav", "83298320");
let e1 = new Employee("Arnav", "8323233", 111, 50000.99);
console.log(e1);
e1.displayEmployee();

