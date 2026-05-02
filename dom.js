let newheading =document.getElementById("heading");
newheading.textContent = "DOM Manipulation in JavaScript";
newheading.style.color = "red";
newheading.style.fontSize = "50px";

let newparagraph = document.getElementById("paragraph");
newparagraph.innerHTML = "<strong>This is a new paragraph created using JavaScript.</strong>";
newparagraph.style.color = "blue";

let newDiv=document.createElement("div");
newDiv.textContent="This is a new div element created using JavaScript.";