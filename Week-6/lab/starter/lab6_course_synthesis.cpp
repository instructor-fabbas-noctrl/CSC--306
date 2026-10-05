// CSCE 306 | Week 6 • Lab Part 6: Synthesis -- design and build a Course system (STARTER)
// Name: ____________________   Date: __________
// Build: g++ -std=c++17 -Wall -Wextra lab6_course_synthesis.cpp -o lab6
//
// REQUIREMENTS
//   A Course has a code, a credit count, a capacity, and one Instructor (who may teach
//   several courses). Students enroll in courses; a Student exists independently of any
//   Course. For each enrollment the course records a letter grade, initially '-'.
//   The registrar computes a student's GPA across a set of courses, weighted by credits
//   (A=4, B=3, C=2, D=1, F=0; ungraded '-' enrollments are ignored).
//
// STEP 1 (design, in the comment block below): list the classes, then draw the UML
//         with relationship types and multiplicities. Decide where 'grade' lives
//         (hint: it is a property of the PAIR student+course, not of either one).
// STEP 2 (code): implement your design so this interface works:
//     Student(int id, string name)         getId(), getName()
//     Instructor(string name)              getName()
//     Course(string code, int credits, int capacity, Instructor* teacher)
//         bool enroll(Student* s)          // false: null, duplicate, or full
//         bool assignGrade(int id, char g) // false: not enrolled or g not in "ABCDF"
//         char gradeFor(int id) const      // '?' if not enrolled
//         int  getCredits() const;  string getCode() const;  string instructorName() const
//     double gpa(const Student& s, const vector<const Course*>& courses)   // free function
//
/* ============================ DESIGN (Step 1) ==============================

   Classes:

   UML:

   ========================================================================== */

#include <iostream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

// TODO: classes and the gpa() function

// ----------------------------- test driver -----------------------------
void check(const string& label, bool ok) { cout << (ok ? "PASS  " : "FAIL  ") << label << '\n'; }

int main()
{
    /*  Uncomment when ready
    Instructor abbas("Prof. Abbas");
    Student ada(1, "Ada"), grace(2, "Grace"), alan(3, "Alan");
    Course oop("CSCE 306", 4, 2, &abbas);
    Course web("CSCE 230", 3, 30, &abbas);

    check("enroll Ada",            oop.enroll(&ada));
    check("no duplicates",         !oop.enroll(&ada));
    check("enroll Grace",          oop.enroll(&grace));
    check("capacity enforced",     !oop.enroll(&alan));
    check("null rejected",         !web.enroll(nullptr));
    web.enroll(&ada);
    check("default grade '-'",     oop.gradeFor(1) == '-');
    check("not enrolled '?'",      oop.gradeFor(3) == '?');
    check("bad grade rejected",    !oop.assignGrade(1, 'Q'));
    check("grade A",               oop.assignGrade(1, 'A'));
    check("grade for stranger",    !oop.assignGrade(3, 'B'));
    vector<const Course*> all = {&oop, &web};
    check("GPA ignores ungraded",  fabs(gpa(ada, all) - 4.0) < 1e-9);
    web.assignGrade(1, 'C');
    check("weighted GPA 3.142857", fabs(gpa(ada, all) - 22.0 / 7.0) < 1e-9);
    check("no grades -> 0.0",      gpa(alan, all) == 0.0);
    check("shared instructor",     oop.instructorName() == web.instructorName());
    */
    return 0;
}
