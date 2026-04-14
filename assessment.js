// ============================================================
//  Student Marks Management System — assessment.js
// ============================================================

const students = [];

// ── Helpers ──────────────────────────────────────────────────

function getTotal(student) {
  return student.maths + student.science + student.english;
}

function getAverage(student) {
  return (getTotal(student) / 3).toFixed(2);
}

function getGrade(avg) {
  if (avg >= 90) return { letter: "A+", cls: "grade-a" };
  if (avg >= 80) return { letter: "A",  cls: "grade-a" };
  if (avg >= 70) return { letter: "B",  cls: "grade-b" };
  if (avg >= 60) return { letter: "C",  cls: "grade-c" };
  if (avg >= 40) return { letter: "D",  cls: "grade-d" };
  return           { letter: "F",  cls: "grade-f" };
}

function val(id) {
  return document.getElementById(id).value.trim();
}

function clearInputs() {
  ["name", "rollnumber", "maths", "science", "english"].forEach(
    id => (document.getElementById(id).value = "")
  );
}

function showOutput(html) {
  document.getElementById("output").innerHTML = html;
}

function showError(msg) {
  showOutput(`<div class="error-msg">⚠️ ${msg}</div>`);
}

// Build a styled HTML table from a list of student objects
function buildTable(list, caption = "") {
  if (!list.length) {
    return `<div class="empty-msg">No students found.</div>`;
  }

  const rows = list
    .map(s => {
      const total = getTotal(s);
      const avg   = getAverage(s);
      const grade = getGrade(Number(avg));
      return `
        <tr>
          <td>${s.roll}</td>
          <td>${s.name}</td>
          <td>${s.maths}</td>
          <td>${s.science}</td>
          <td>${s.english}</td>
          <td><strong>${total}</strong></td>
          <td>${avg}</td>
          <td><span class="badge ${grade.cls}">${grade.letter}</span></td>
        </tr>`;
    })
    .join("");

  return `
    ${caption ? `<p class="table-caption">${caption}</p>` : ""}
    <div class="table-wrapper">
      <table>
        <thead>
          <tr>
            <th>Roll No.</th>
            <th>Name</th>
            <th>Maths</th>
            <th>Science</th>
            <th>English</th>
            <th>Total</th>
            <th>Average</th>
            <th>Grade</th>
          </tr>
        </thead>
        <tbody>${rows}</tbody>
      </table>
    </div>`;
}

// ── Core Functions ────────────────────────────────────────────

function addStudent() {
  const name   = val("name");
  const roll   = Number(val("rollnumber"));
  const maths  = Number(val("maths"));
  const sci    = Number(val("science"));
  const eng    = Number(val("english"));

  // Validation
  if (!name) return showError("Please enter the student name.");
  if (!roll || roll <= 0) return showError("Please enter a valid roll number.");

  if (students.some(s => s.roll === roll)) {
    return showError(`Roll number <strong>${roll}</strong> already exists.`);
  }

  const subjects = { maths, science: sci, english: eng };
  for (const [subj, marks] of Object.entries(subjects)) {
    if (isNaN(marks) || marks < 0 || marks > 100) {
      return showError(`Marks for <strong>${subj}</strong> must be between 0 and 100.`);
    }
  }

  students.push({ name, roll, maths, science: sci, english: eng });
  clearInputs();

  showOutput(`
    <div class="success-msg">
      ✅ <strong>${name}</strong> (Roll: ${roll}) added successfully.
      Total students: <strong>${students.length}</strong>
    </div>`);
}

function displayStudents() {
  if (!students.length) return showError("No students added yet.");
  showOutput(buildTable(students, `All Students (${students.length})`));
}

// Called by "Marks > 80" button
function filterHigh() {
  const filtered = students.filter(s => getAverage(s) > 80);
  showOutput(
    buildTable(filtered, `Students with Average > 80 (${filtered.length} found)`)
  );
}

// Called by "Marks < 40" button
function filterLow() {
  const filtered = students.filter(s => getAverage(s) < 40);
  showOutput(
    buildTable(filtered, `Students with Average < 40 (${filtered.length} found)`)
  );
}

// Legacy alias — HTML uses filterMarks() for both buttons.
// To distinguish, check which button triggered the call.
// If your HTML stays as-is, wire up buttons differently (see note below).
function filterMarks(threshold) {
  // Fallback: called generically — show both groups
  filterHigh();
}

function totalMarks() {
  if (!students.length) return showError("No students added yet.");

  const rows = students
    .map(s => {
      const total = getTotal(s);
      return `
        <tr>
          <td>${s.roll}</td>
          <td>${s.name}</td>
          <td><strong>${total}</strong> / 300</td>
        </tr>`;
    })
    .join("");

  const grandTotal = students.reduce((sum, s) => sum + getTotal(s), 0);

  showOutput(`
    <p class="table-caption">Total Marks per Student</p>
    <div class="table-wrapper">
      <table>
        <thead><tr><th>Roll No.</th><th>Name</th><th>Total Marks</th></tr></thead>
        <tbody>${rows}</tbody>
        <tfoot>
          <tr>
            <td colspan="2"><strong>Grand Total (all subjects, all students)</strong></td>
            <td><strong>${grandTotal}</strong></td>
          </tr>
        </tfoot>
      </table>
    </div>`);
}

function averageMarks() {
  if (!students.length) return showError("No students added yet.");

  const rows = students
    .map(s => {
      const avg   = Number(getAverage(s));
      const grade = getGrade(avg);
      return `
        <tr>
          <td>${s.roll}</td>
          <td>${s.name}</td>
          <td>${avg}</td>
          <td><span class="badge ${grade.cls}">${grade.letter}</span></td>
        </tr>`;
    })
    .join("");

  const classAvg = (
    students.reduce((sum, s) => sum + Number(getAverage(s)), 0) / students.length
  ).toFixed(2);

  showOutput(`
    <p class="table-caption">Average Marks per Student</p>
    <div class="table-wrapper">
      <table>
        <thead><tr><th>Roll No.</th><th>Name</th><th>Average</th><th>Grade</th></tr></thead>
        <tbody>${rows}</tbody>
        <tfoot>
          <tr>
            <td colspan="2"><strong>Class Average</strong></td>
            <td><strong>${classAvg}</strong></td>
            <td></td>
          </tr>
        </tfoot>
      </table>
    </div>`);
}

function countStudents() {
  const total    = students.length;
  const passing  = students.filter(s => Number(getAverage(s)) >= 40).length;
  const failing  = total - passing;
  const toppers  = students.filter(s => Number(getAverage(s)) >= 80).length;

  showOutput(`
    <div class="stats-grid">
      <div class="stat-card">
        <span class="stat-number">${total}</span>
        <span class="stat-label">Total Students</span>
      </div>
      <div class="stat-card pass">
        <span class="stat-number">${passing}</span>
        <span class="stat-label">Passing (≥ 40 avg)</span>
      </div>
      <div class="stat-card fail">
        <span class="stat-number">${failing}</span>
        <span class="stat-label">Failing (< 40 avg)</span>
      </div>
      <div class="stat-card top">
        <span class="stat-number">${toppers}</span>
        <span class="stat-label">Distinction (≥ 80 avg)</span>
      </div>
    </div>`);
}

// ── HTML Button Fix Note ──────────────────────────────────────
// Your HTML has TWO buttons both calling filterMarks().
// Replace them with:
//   <button onclick="filterHigh()">Marks > 80</button>
//   <button onclick="filterLow()">Marks < 40</button>
// This JS already defines filterHigh() and filterLow() for this purpose.