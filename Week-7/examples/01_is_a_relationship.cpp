// CSCE 306 — Object-Oriented Software Development | Fall 2026
// Week 7 • Example 01: Inheritance and the is-a relationship (Ch. 15.1)
// Build: g++ -std=c++17 -Wall -Wextra 01_is_a_relationship.cpp -o isa
//
// UML:   GradedActivity  <|——  FinalExam      (hollow triangle points at the BASE class)

#include <iostream>
using namespace std;

class GradedActivity {                    // BASE class (superclass / parent)
private:
    double score = 0.0;
public:
    void   setScore(double s) { if (s >= 0 && s <= 100) score = s; }
    double getScore() const   { return score; }
    char   getLetterGrade() const
    {
        if (score >= 90) return 'A';
        if (score >= 80) return 'B';
        if (score >= 70) return 'C';
        if (score >= 60) return 'D';
        return 'F';
    }
};

// DERIVED class (subclass / child). "A FinalExam IS-A GradedActivity."
class FinalExam : public GradedActivity {
private:
    int numQuestions = 0;
    int numMissed    = 0;
public:
    void set(int questions, int missed)
    {
        numQuestions = questions;
        numMissed    = missed;
        double pointsEach = 100.0 / questions;
        setScore(100.0 - missed * pointsEach);   // calls an INHERITED public member
    }
    int getNumMissed() const { return numMissed; }
};

int main()
{
    FinalExam exam;
    exam.set(40, 6);
    // A FinalExam object has ALL the public members of GradedActivity plus its own.
    cout << "Missed " << exam.getNumMissed() << " -> score "
         << exam.getScore() << " (" << exam.getLetterGrade() << ")\n";

    // A derived object can be used wherever a base object is expected:
    const GradedActivity& asBase = exam;
    cout << "Viewed as a GradedActivity: " << asBase.getScore() << '\n';
    // asBase.getNumMissed();   // ERROR: the base "view" only knows base members
    return 0;
}
