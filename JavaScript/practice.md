### Closures
- Function bundled together with the references of its surrounding state (Lexical environment) is called closure. 
- Closure is created everytime a function is created

### Function Hoisting
- Only function declaration can be accessed before declaration.
    ```js
    greet(); // Hello, World!

    function greet() {
        console.log("Hello, World!");
    }
    ```
- Function expression variables are hoisted but can't call the function before declaration.
    ```js
    greet(); // TypeError: greet is not a function

    var greet = function() {
        console.log("Hello, World!");
    };
    ```
 
### 3 ways of creating objects
1) Using Object literal 
    ```js  
    let obj = {} 
    ```
2) Using new keyword
    ```js
    let obj = new Object()
    ```
3) Using constructor function
    ```js
    function Person(name, age) {
        this.name = name;
        this.age = age;
    }
    let obj = new Person("Ram", 32);
    ```
 
### Inheritance in protototypal inheritance
```js
    Object.setPrototypeOf(Employee.prototype, Person.prototype);
    // Employee.prototype.prototype = Person.prototype;  // not possible must be modified through setters only
```