
function Person(name, age) {
    this.name = name;
    this.age = age;
}
Person.prototype.displayPerson = function() {
    console.log(`Name: ${this.name} \nAge: ${this.age}`);
}
Person.prototype.toString = function() {
    return `${this.name}-${this.age}`
}
let p1 = new Person("Aranv", 23);
p1.displayPerson();
console.log(p1.toString());