import { useState } from 'react';
function GameScore(){
  const [score, setScore] = useState(0);
  const increment = () => {
    setScore(score + 1);
  };
}
const decrement = () => {
    setScore(score - 1);
}
return (
    <div>
        <h1>Game Score: {score}</h1>
        <button onClick={increment}>Increment</button>
        <button onClick={decrement}>Decrement</button>
    </div>
);
export default GameScore;