//object data type
//object is a collection of properties and methods
//object is a non-primitive data type
//object is a reference data type
//object is a collection of key-value pairs
//object is a collection of properties and methods
let person = {
    name: "Lavi",
    age: 20,
    city: "Ghaziabad",
};
console.log(person.name); //Lavi
console.log(person.age); //20
console.log(person.city); //Ghaziabad

// array data type
// array is a collection of values
// array is a non-primitive data type
let numbers = [1, 2, 3, 4, 5];
console.log(numbers[0]); //1
console.log(numbers[1]); //2
console.log(numbers[2]); //3
console.log(numbers[3]); //4   

//mixed data type
// mixed data type is a collection of values of different data types
let mixed = [1, "Lavi", true, null, undefined];
console.log(mixed[0]);
console.log(mixed[1]);
console.log(mixed[2]);
console.log(mixed[3]);
console.log(mixed[4]);

//map on array
//map creates a new array by calling a function on every element of the original array
let numbers2 = [1, 2, 3, 4, 5];
let squares = numbers2.map(function (num) {
    return num * num;
});
console.log(squares); // [1, 4, 9, 16, 25]