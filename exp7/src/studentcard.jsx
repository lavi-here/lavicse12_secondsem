function StudentCard(props){
    return(
        <div className="student-card">
            <h2 className="student-card__name">Name: {props.name}</h2>
            <p className="student-card__info">Course: {props.course}</p>
            <p className="student-card__info">Marks: {props.marks}</p>
        </div>
    );
}
export default StudentCard;