let person={
    name: "gaurav",
    age:18,
    city:"haldwani"

};
console.log(person.city);
let numbers =[1,2,3,4,5];
console.log(numbers[0]);
console.log(numbers[1]);
console.log(numbers[2]);
console.log(numbers[3]);
console.log(numbers);

let newarray = [1, 2, 3, 4, 5];
let squaredarray = newarray.map(num => num * num);
console.log(squaredarray);


let evenNumbers=[1,2,3,4,5];
let filteredEvenNumbers = evenNumbers.filter(num => num%2==0);
console.log(filteredEvenNumbers);