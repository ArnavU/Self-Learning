// destructuring
const e1 = { empid: 1, name: 'anil', salary: 10000, mobile: '9876543210' }
const {empid:eid, name:ename, salary} = e1;
console.log(eid, ename, salary)

// splice
let arr = [1, 2, 3, 4, 5, 6, 7];
console.log(arr.splice(2, 3, 111, 112, 112));
console.log(arr);