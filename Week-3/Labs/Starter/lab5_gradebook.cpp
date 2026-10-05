// CSCE 306 | Week 3 • Lab 1 Part 5: Gradebook with structs (STARTER)
// Name: ____________________   Date: __________
// Build: g++ -std=c++17 -Wall -Wextra lab5_gradebook.cpp -o lab5
//
// Brings the week together: structs, arrays inside structs, vectors of structs,
// const references, and searching. Next week you will turn this struct into a CLASS.
//
// Expected output:
//   Name        Avg  Grade
//   ----------------------
//   Ada        92.0  A
//   Grace      84.3  B
//   Alan       71.7  C
//   Barbara    58.3  F
//   ----------------------
//   Class average: 76.6
//   Top student:   Ada
//   Lookup "Alan": found, average 71.7
//   Lookup "Linus": not found

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
using namespace std;

constexpr int NUM_EXAMS = 3;

struct StudentRecord {
    string name;
    int scores[NUM_EXAMS];
};

// TODO 1: return the average of s.scores
double average(const StudentRecord& s)
{
    (void)s;
    return 0.0;
}

// TODO 2: return 'A' (>=90), 'B' (>=80), 'C' (>=70), 'D' (>=60), else 'F'
char letter(double avg)
{
    (void)avg;
    return 'F';
}

// TODO 3: return a POINTER to the student with that name, or nullptr if absent
const StudentRecord* findStudent(const vector<StudentRecord>& book, const string& name)
{
    (void)book; (void)name;
    return nullptr;
}

// TODO 4: return a pointer to the student with the highest average (nullptr if empty)
const StudentRecord* topStudent(const vector<StudentRecord>& book)
{
    (void)book;
    return nullptr;
}

int main()
{
    vector<StudentRecord> book = {
        {"Ada",     {95, 88, 93}},
        {"Grace",   {80, 85, 88}},
        {"Alan",    {70, 75, 70}},
        {"Barbara", {50, 65, 60}}
    };

    // TODO 5: print the table, class average, top student, and the two lookups
    //         exactly as shown in the expected output above.

    return 0;
}
