// CSCE 306 | Week 4 • Vector Lab 5: Vectors inside objects inside a vector -- Course Roster (STARTER)
// Name: ____________________   Date: __________
// Build: g++ -std=c++17 -Wall -Wextra vlab5_course_roster.cpp -o vlab5
//
// UML:   Course ◆——— 0..* Student        Student has a vector<int> of scores
//
// Two levels of vectors: Course holds vector<Student>, and each Student holds vector<int>.
// Implement every member function marked TODO.
//
// IMPORTANT (pointer invalidation): Course::find returns Student*, a pointer INTO the roster
// vector. If the vector grows (push_back) it may move its elements to new memory, and every
// old pointer dangles. Use the pointer right away -- never store it across an addStudent call.

#include <iomanip>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Student {
private:
    int         id;
    string      name;
    vector<int> scores;
public:
    Student(int i, const string& n) : id(i), name(n) {}

    bool   addScore(int s);              // reject scores outside 0..100
    double average() const;              // 0.0 if no scores
    int    best() const;                 // highest score, 0 if none
    int    scoreCount() const { return static_cast<int>(scores.size()); }
    int    getId() const      { return id; }
    string getName() const    { return name; }
};

bool Student::addScore(int s)
{
    // TODO
    (void)s; return false;
}

double Student::average() const
{
    // TODO
    return 0.0;
}

int Student::best() const
{
    // TODO
    return 0;
}

class Course {
private:
    string          code;
    vector<Student> roster;
public:
    explicit Course(const string& c) : code(c) {}

    bool     addStudent(int id, const string& name);   // false if the id is already enrolled
    Student* find(int id);                             // nullptr if not enrolled (non-const: allows changes)
    const Student* find(int id) const;                 // const overload for const Courses
    bool     recordScore(int id, int score);           // false if no such student OR invalid score
    double   classAverage() const;                     // average of student averages; 0.0 if empty
    const Student* topStudent() const;                 // highest average; nullptr if empty
    vector<int> letterCounts() const;                  // 5 counters: A, B, C, D, F (90/80/70/60)
    vector<string> namesBelow(double cutoff) const;    // names whose average < cutoff, roster order
    void     report() const;
};

bool Course::addStudent(int id, const string& name)
{
    // TODO: reuse find(); emplace_back(id, name) builds the Student in place
    (void)id; (void)name; return false;
}

Student* Course::find(int id)
{
    // TODO: loop with Student& (a reference, so the address is the element's, not a copy's)
    (void)id; return nullptr;
}

const Student* Course::find(int id) const
{
    // TODO
    (void)id; return nullptr;
}

bool Course::recordScore(int id, int score)
{
    // TODO
    (void)id; (void)score; return false;
}

double Course::classAverage() const
{
    // TODO
    return 0.0;
}

const Student* Course::topStudent() const
{
    // TODO
    return nullptr;
}

vector<int> Course::letterCounts() const
{
    // TODO: start with vector<int> counts(5, 0)
    return vector<int>(5, 0);
}

vector<string> Course::namesBelow(double cutoff) const
{
    // TODO
    (void)cutoff; return {};
}

void Course::report() const
{
    // TODO: header line, then: id, name (left, width 10), average (1 decimal, width 6), best (width 5)
}

// ----------------------------- test driver (do not change) -----------------------------
void check(const string& label, bool ok) { cout << (ok ? "PASS  " : "FAIL  ") << label << '\n'; }

int main()
{
    Course oop("CSCE 306");
    check("add Ada",                    oop.addStudent(1, "Ada"));
    oop.addStudent(2, "Grace");
    oop.addStudent(3, "Alan");
    oop.addStudent(4, "Linus");
    check("duplicate id rejected",      !oop.addStudent(2, "Impostor"));

    const int ada[] = {95, 88, 92}, grace[] = {81, 79, 85}, alan[] = {70, 64}, linus[] = {55, 61, 58};
    for (int s : ada)   oop.recordScore(1, s);
    for (int s : grace) oop.recordScore(2, s);
    for (int s : alan)  oop.recordScore(3, s);
    for (int s : linus) oop.recordScore(4, s);
    check("score for unknown id fails", !oop.recordScore(9, 80));
    check("invalid score rejected",     !oop.recordScore(1, 101));

    const Student* a = oop.find(1);
    check("Ada has 3 scores",           a && a->scoreCount() == 3);
    check("Ada average 91.67",          a && a->average() > 91.66 && a->average() < 91.67);
    check("Alan best 70",               oop.find(3) && oop.find(3)->best() == 70);
    check("top student Ada",            oop.topStudent() && oop.topStudent()->getName() == "Ada");
    check("letterCounts A1 B1 C0 D1 F1", oop.letterCounts() == vector<int>({1, 1, 0, 1, 1}));
    check("namesBelow(70)",             oop.namesBelow(70) == vector<string>({"Alan", "Linus"}));
    double avg = oop.classAverage();
    check("class average 74.58",        avg > 74.58 && avg < 74.59);
    oop.report();

    const Course empty("EMPTY");
    check("empty course",               empty.classAverage() == 0.0 && empty.topStudent() == nullptr && empty.find(1) == nullptr);
    return 0;
}
