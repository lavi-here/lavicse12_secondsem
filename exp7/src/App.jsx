import React from "react";
import "./studentcard.css";
import StudentCard from "./studentcard";
function App(){
  return(
    <div className="app">
      <h1 className="app__title">Exp -7 Student Card</h1>
      <div className="student-list">
        <StudentCard name="John Doe" course="Computer Science" marks={85} />
        <StudentCard name="Jane Smith" course="Mathematics" marks={92} />
        <StudentCard name="Alice Johnson" course="Physics" marks={78} />
      </div>
    </div>
  );
}
export default App;