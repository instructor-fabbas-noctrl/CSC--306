// CSCE 306 | Week 6 • Lab Part 5: Reverse translation -- code -> UML (SOLUTION)
// Build: g++ -std=c++17 -Wall -Wextra lab5_reverse_translation_solution.cpp -o lab5
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

// ---- Part C ----
int FitnessClass::spotsLeft() const
{
    return capacity - booked();
}

const FitnessClass* Gym::busiestClass() const
{
    const FitnessClass* best = nullptr;
    for (const FitnessClass& c : schedule)
        if (best == nullptr || c.booked() > best->booked()) best = &c;
    return best;
}

/* ============================ UML (Part A) =================================

  +-------------------------------------------+   +-------------------------------------------+
  | Gym                                       |   | FitnessClass                              |
  +-------------------------------------------+   +-------------------------------------------+
  | - name : string                           |   | - title : string                          |
  | - schedule : vector<FitnessClass>         |   | - capacity : int                          |
  +-------------------------------------------+   | - trainer : Trainer*                      |
  | + Gym(n : string)                         |   | - attendees : vector<Member*>             |
  | + addClass(t : string, cap : int,         |   +-------------------------------------------+
  |       tr : Trainer*) : FitnessClass&      |   | + FitnessClass(t : string, cap : int,     |
  | + find(title : string) : FitnessClass*    |   |       tr : Trainer*)                      |
  | + busiestClass() : const FitnessClass*    |   | + book(m : Member*) : bool                |
  |       {query}                             |   | + spotsLeft() : int {query}               |
  | + printSpots() : void {query}             |   | + booked() : int {query}                  |
  +-------------------------------------------+   | + getTitle() : string {query}             |
                                                  +-------------------------------------------+
  +-------------------------------------------+   +-------------------------------------------+
  | Trainer                                   |   | Member                                    |
  +-------------------------------------------+   +-------------------------------------------+
  | - name : string                           |   | - name : string                           |
  +-------------------------------------------+   | - _memberCount : int_        (static)     |
  | + Trainer(n : string)                     |   +-------------------------------------------+
  | + getName() : string {query}              |   | + Member(n : string)                      |
  +-------------------------------------------+   | + getName() : string {query}              |
                                                  | + _count() : int_            (static)     |
                                                  +-------------------------------------------+
  Relationships:
    Gym          1 ◆——————> 0..*  FitnessClass   composition
    FitnessClass 0..* ——————> 1   Trainer        association (navigable FitnessClass -> Trainer)
    FitnessClass 0..* ◇——————> 0..* Member       aggregation

   ============================ ANSWERS (Part B) =============================
   Q1. Composition (◆). schedule is a vector<FitnessClass> held BY VALUE: the Gym creates
       the classes (emplace_back) and they are destroyed with the Gym.
   Q2. Aggregation (◇). attendees holds Member* pointers; Members are created elsewhere,
       outlive any class, and are never deleted by FitnessClass. A member can attend many
       classes, so the Member end is 0..* and the FitnessClass end is 0..*.
   Q3. FitnessClass end: 0..* (one trainer may lead many classes).
       Trainer end: 1 (every class is given exactly one trainer in its constructor).
   Q4. Returning a reference lets the caller book immediately without a lookup. But when
       schedule grows, the vector may reallocate and MOVE its elements, so any reference or
       pointer obtained earlier dangles. Look objects up after all insertions, store
       indices, or hold the classes by pointer (e.g., vector<unique_ptr<FitnessClass>>).
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
