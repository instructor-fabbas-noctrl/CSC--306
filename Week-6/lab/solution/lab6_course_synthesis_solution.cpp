// CSCE 306 | Week 6 • Lab Part 6: Synthesis -- design and build a Course system (SOLUTION)
// Build: g++ -std=c++17 -Wall -Wextra lab6_course_synthesis_solution.cpp -o lab6
//
/* ============================ DESIGN (Step 1) ==============================

   Classes: Student, Instructor, Course, Enrollment (the "association class" that holds
   the grade for one student+course pair). gpa() is a free function (registrar service).

     Instructor 1 <——————— 0..* Course              association (Course knows its teacher)
     Course     1 ◆——————> 0..* Enrollment          composition (Course owns enrollments)
     Enrollment 0..* ——————> 1  Student             association (non-owning Student*)
     gpa(...)  - - - - - - -> Course, Student       dependency (parameters only)

   Net effect Course 0..* —— 0..* Student, realized through Enrollment.
   ========================================================================== */

#include <iostream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

class Student {
    int    id;
    string name;
public:
    Student(int i, const string& n) : id(i), name(n) {}
    int    getId() const   { return id; }
    string getName() const { return name; }
};

class Instructor {
    string name;
public:
    explicit Instructor(const string& n) : name(n) {}
    string getName() const { return name; }
};

class Enrollment {
    Student* student;
    char     grade = '-';
public:
    explicit Enrollment(Student* s) : student(s) {}
    const Student* getStudent() const { return student; }
    char  getGrade() const   { return grade; }
    void  setGrade(char g)   { grade = g; }
};

class Course {
    string             code;
    int                credits;
    int                capacity;
    Instructor*        teacher;
    vector<Enrollment> enrollments;

    const Enrollment* findEnrollment(int id) const
    {
        for (const Enrollment& e : enrollments)
            if (e.getStudent()->getId() == id) return &e;
        return nullptr;
    }

public:
    Course(const string& c, int cr, int cap, Instructor* t)
        : code(c), credits(cr), capacity(cap), teacher(t) {}

    bool enroll(Student* s)
    {
        if (s == nullptr || findEnrollment(s->getId()) != nullptr) return false;
        if (static_cast<int>(enrollments.size()) >= capacity) return false;
        enrollments.emplace_back(s);
        return true;
    }

    bool assignGrade(int id, char g)
    {
        if (string("ABCDF").find(g) == string::npos) return false;
        for (Enrollment& e : enrollments)
            if (e.getStudent()->getId() == id) { e.setGrade(g); return true; }
        return false;
    }

    char gradeFor(int id) const
    {
        const Enrollment* e = findEnrollment(id);
        return e ? e->getGrade() : '?';
    }

    int    getCredits() const     { return credits; }
    string getCode() const        { return code; }
    string instructorName() const { return teacher ? teacher->getName() : "TBA"; }
};

double points(char grade)
{
    switch (grade) {
        case 'A': return 4; case 'B': return 3; case 'C': return 2;
        case 'D': return 1; case 'F': return 0;
        default:  return -1;   // ungraded / not enrolled
    }
}

double gpa(const Student& s, const vector<const Course*>& courses)
{
    double qualityPoints = 0.0;
    int    gradedCredits = 0;
    for (const Course* c : courses) {
        double p = points(c->gradeFor(s.getId()));
        if (p < 0) continue;
        qualityPoints += p * c->getCredits();
        gradedCredits += c->getCredits();
    }
    return gradedCredits == 0 ? 0.0 : qualityPoints / gradedCredits;
}

// ----------------------------- test driver -----------------------------
void check(const string& label, bool ok) { cout << (ok ? "PASS  " : "FAIL  ") << label << '\n'; }

int main()
{
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
    return 0;
}
