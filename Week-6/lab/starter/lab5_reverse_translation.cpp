// CSCE 306 | Week 6 • Lab Part 5: Reverse translation -- code -> UML (STARTER)
// Name: ____________________   Date: __________
// Build: g++ -std=c++17 -Wall -Wextra lab5_reverse_translation.cpp -o lab5
//
// PART A (diagram): Read the GymSystem code below. In the comment block marked
//   "YOUR UML", draw a text-form UML class diagram showing, for every class:
//   attributes with visibility and types, operations with parameters, return types,
//   {query} and underlined statics; and EVERY relationship with its correct
//   symbol (◆ ◇ ——> - - ->) and multiplicities at both ends.
//
// PART B (questions): answer Q1-Q4 in the comment block.
//
// PART C (code): FitnessClass::spotsLeft() and Gym::busiestClass() are declared but
//   not finished. Implement them so the driver prints the expected output:
//     third Spin booking accepted? false
//     Yoga: 2 spot(s) left
//     Spin: 0 spot(s) left
//     Busiest: Spin
//     Members: 3

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Trainer {
    string name;
public:
    explicit Trainer(const string& n) : name(n) {}
    string getName() const { return name; }
};

class Member {
    string name;
    static int memberCount;
public:
    explicit Member(const string& n) : name(n) { ++memberCount; }
    string getName() const { return name; }
    static int count() { return memberCount; }
};
int Member::memberCount = 0;

class FitnessClass {
    string          title;
    int             capacity;
    Trainer*        trainer;            // set in constructor; may be shared by many classes
    vector<Member*> attendees;
public:
    FitnessClass(const string& t, int cap, Trainer* tr) : title(t), capacity(cap), trainer(tr) {}
    bool book(Member* m)
    {
        if (static_cast<int>(attendees.size()) >= capacity) return false;
        attendees.push_back(m);
        return true;
    }
    int    spotsLeft() const;            // TODO (Part C)
    int    booked() const   { return static_cast<int>(attendees.size()); }
    string getTitle() const { return title; }
};

class Gym {
    string               name;
    vector<FitnessClass> schedule;      // the Gym creates and owns its classes
public:
    explicit Gym(const string& n) : name(n) {}
    FitnessClass& addClass(const string& t, int cap, Trainer* tr)
    {
        schedule.emplace_back(t, cap, tr);
        return schedule.back();
    }
    FitnessClass* find(const string& title)
    {
        for (FitnessClass& c : schedule)
            if (c.getTitle() == title) return &c;
        return nullptr;
    }
    const FitnessClass* busiestClass() const;   // TODO (Part C): most bookings; nullptr if none
    void printSpots() const
    {
        for (const FitnessClass& c : schedule)
            cout << c.getTitle() << ": " << c.spotsLeft() << " spot(s) left\n";
    }
};

// TODO (Part C)
int FitnessClass::spotsLeft() const { return 0; }
const FitnessClass* Gym::busiestClass() const { return nullptr; }

/* ============================ YOUR UML (Part A) ============================



   ============================ ANSWERS (Part B) =============================
   Q1. Gym -> FitnessClass: which relationship, and what in the code tells you?

   Q2. FitnessClass -> Member: which relationship, and what in the code tells you?

   Q3. FitnessClass -> Trainer: multiplicity on EACH end?

   Q4. Why does addClass return FitnessClass& -- and what danger does that create
       if more classes are added later? (Hint: what does vector do when it grows?)
   ========================================================================== */

int main()
{
    Trainer kim("Kim");
    Member a("Ada"), g("Grace"), l("Linus");
    Gym gym("Cardinal Fitness");
    gym.addClass("Yoga", 3, &kim);
    gym.addClass("Spin", 2, &kim);

    // Look classes up AFTER all are added (see Q4 for why we don't keep addClass's reference)
    gym.find("Yoga")->book(&a);
    FitnessClass* spin = gym.find("Spin");
    spin->book(&a); spin->book(&g);
    cout << boolalpha << "third Spin booking accepted? " << spin->book(&l) << '\n';

    gym.printSpots();
    if (const FitnessClass* best = gym.busiestClass())
        cout << "Busiest: " << best->getTitle() << '\n';
    cout << "Members: " << Member::count() << '\n';
    return 0;
}
