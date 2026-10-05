// CSCE 306 | Week 5 • Lab Part 6: Aggregation vs composition -- Course and Student (SOLUTION)
// Build: g++ -std=c++17 -Wall -Wextra lab6_aggregation_composition_solution.cpp -o lab6

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Room {
private:
    string building;
    int    number;
    int    capacity;
public:
    Room(const string& b, int n, int cap) : building(b), number(n), capacity(cap) {}
    int    getCapacity() const { return capacity; }
    string toString() const    { return building + " " + to_string(number); }
};

class Student {
private:
    int    id;
    string name;
    int    courseCount = 0;
public:
    Student(int i, const string& n) : id(i), name(n) {}
    int    getId() const    { return id; }
    string getName() const  { return name; }
    int    getCourseCount() const { return courseCount; }
    void   joinedCourse()   { ++courseCount; }
    void   leftCourse()     { if (courseCount > 0) --courseCount; }
};

class Course {
private:
    string           code;
    Room             room;     // composition: value member, same lifetime as Course
    vector<Student*> roster;   // aggregation: non-owning pointers

    int indexOf(int studentId) const
    {
        for (size_t i = 0; i < roster.size(); ++i)
            if (roster[i]->getId() == studentId) return static_cast<int>(i);
        return -1;
    }

public:
    Course(const string& c, const string& building, int roomNumber, int capacity)
        : code(c), room(building, roomNumber, capacity) {}

    bool enroll(Student* s)
    {
        if (s == nullptr) return false;
        if (indexOf(s->getId()) != -1) return false;
        if (enrolledCount() >= room.getCapacity()) return false;
        roster.push_back(s);
        s->joinedCourse();
        return true;
    }

    bool drop(int studentId)
    {
        int i = indexOf(studentId);
        if (i == -1) return false;
        roster[i]->leftCourse();
        roster.erase(roster.begin() + i);   // removes the POINTER only; the Student lives on
        return true;
    }

    int enrolledCount() const { return static_cast<int>(roster.size()); }

    void printRoster() const
    {
        cout << code << " @ " << room.toString()
             << " (" << enrolledCount() << '/' << room.getCapacity() << ")\n";
        for (const Student* s : roster)
            cout << "  " << s->getId() << ' ' << s->getName() << '\n';
    }
    // No destructor needed: Course owns no heap memory (the Students are not its to delete).
};

int main()
{
    Student ada(1001, "Ada"), grace(1002, "Grace"), alan(1003, "Alan"), barbara(1004, "Barbara");
    Course oop("CSCE 306", "Wentz", 156, 3);
    Course ds ("CSCE 310", "Wentz", 110, 30);

    oop.enroll(&ada); oop.enroll(&grace); oop.enroll(&alan);
    cout << boolalpha << "enroll Barbara when full -> " << oop.enroll(&barbara) << '\n';
    cout << "enroll Ada twice -> " << oop.enroll(&ada) << '\n';
    oop.drop(1002);
    oop.enroll(&barbara);
    ds.enroll(&ada);

    oop.printRoster();
    ds.printRoster();
    cout << ada.getName() << " is still enrolled in " << ada.getCourseCount() << " course(s)\n";
    return 0;
}
