function add(n1, n2) {
    return n1+n2;
}

add.mul = function(n1, n2) {
    return n1*n2;
}
let sum = add(10, 20);
let prod = add.mul(10, 20);

console.log(sum);
console.log(prod);
