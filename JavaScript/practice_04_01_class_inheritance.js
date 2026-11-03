function Date(day, month, year) {
	this.day = day;
	this.month = month;
	this.year = year;
}

Date.prototype.display = function () {
	console.log(`${this.day}/${this.month}/${this.year}`);
};

function Person(name, mobile, day, month, year) {
	this.name = name;
	this.mobile = mobile;
    this.dob = new Date(day, month, year);
}

Person.prototype.display = function () {
	console.log(`Name: ${this.name}`);
	console.log(`Mobile: ${this.mobile}`);
	this.dob.display();
};

function Employee(name, mobile, day, month, year, empId, salary) {
    Person.call(this, name, mobile, day, month, year);
    this.empId = empId;
    this.salary = salary;
}
Object.setPrototypeOf(Employee.prototype, Person.prototype);

Employee.prototype.display = function() {
    Object.getPrototypeOf(Employee.prototype).display.call(this);
    console.log(`EmpId: ${this.empId}`);
    console.log(`Salary: ${this.salary}`);
}

const e1 = new Employee("Arnav", "89932", 39, 1, 2003, 99, 89999.94934);
console.log(e1);
e1.display();
