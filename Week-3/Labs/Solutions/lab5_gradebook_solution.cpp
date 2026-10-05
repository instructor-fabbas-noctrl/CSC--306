// CSCE 306 | Week 3 • Lab 1 Part 5: Gradebook with structs (SOLUTION)
// Build: g++ -std=c++17 -Wall -Wextra lab5_gradebook_solution.cpp -o lab5

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

double average(const StudentRecord& s)
{
    int sum = 0;
    for (int score : s.scores) sum += score;
    return static_cast<double>(sum) / NUM_EXAMS;
}

char letter(double avg)
{
    if (avg >= 90) return 'A';
    if (avg >= 80) return 'B';
    if (avg >= 70) return 'C';
    if (avg >= 60) return 'D';
    return 'F';
}

const StudentRecord* findStudent(const vector<StudentRecord>& book, const string& name)
{
    for (const StudentRecord& s : book)
        if (s.name == name) return &s;
    return nullptr;
}

const StudentRecord* topStudent(const vector<StudentRecord>& book)
{
    const StudentRecord* best = nullptr;
    for (const StudentRecord& s : book)
        if (best == nullptr || average(s) > average(*best)) best = &s;
    return best;
}

void lookup(const vector<StudentRecord>& book, const string& name)
{
    cout << "Lookup \"" << name << "\": ";
    if (const StudentRecord* s = findStudent(book, name))
        cout << "found, average " << average(*s) << '\n';
    else
        cout << "not found\n";
}

int main()
{
    vector<StudentRecord> book = {
        {"Ada",     {95, 88, 93}},
        {"Grace",   {80, 85, 88}},
        {"Alan",    {70, 75, 70}},
        {"Barbara", {50, 65, 60}}
    };

    const string rule(22, '-');
    cout << fixed << setprecision(1);
    cout << left << setw(10) << "Name" << right << setw(5) << "Avg" << "  Grade\n" << rule << '\n';

    double classTotal = 0.0;
    for (const StudentRecord& s : book) {
        double avg = average(s);
        classTotal += avg;
        cout << left << setw(10) << s.name << right << setw(5) << avg << "  " << letter(avg) << '\n';
    }
    cout << rule << '\n';
    cout << "Class average: " << (book.empty() ? 0.0 : classTotal / book.size()) << '\n';
    if (const StudentRecord* top = topStudent(book))
        cout << "Top student:   " << top->name << '\n';

    lookup(book, "Alan");
    lookup(book, "Linus");
    return 0;
}
