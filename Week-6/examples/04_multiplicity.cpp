// CSCE 306 | Week 6 • Example 04: Multiplicity -> C++ member types
// Build: g++ -std=c++17 -Wall -Wextra 04_multiplicity.cpp -o mult
//
//   UML multiplicity      Typical C++ member
//   ----------------      ------------------------------------------------
//   1                     value member (composition) or reference/pointer set in ctor
//   0..1                  pointer that may be nullptr   (or std::optional<T>)
//   *  / 0..*             std::vector<T> (owned) or std::vector<T*> (not owned)
//   1..*                  vector + a constructor that requires at least one element
//   2..4                  vector + validation of the size in the interface
//
//   Team  1 ——— 1..* Player          Team  1 ——— 0..1 Coach

#include <iostream>
#include <string>
#include <vector>
#include <optional>
#include <stdexcept>
using namespace std;

class Player {
    string name;
public:
    explicit Player(const string& n) : name(n) {}
    string getName() const { return name; }
};

class Team {
private:
    string           name;
    vector<Player>   players;      // 1..*  (enforced below)
    optional<string> coach;        // 0..1
public:
    Team(const string& n, const Player& first) : name(n), players{first} {}   // can't be empty
    void addPlayer(const Player& p) { players.push_back(p); }
    void setCoach(const string& c)  { coach = c; }
    void print() const
    {
        cout << name << " -- coach: " << coach.value_or("(none)") << " -- players:";
        for (const Player& p : players) cout << ' ' << p.getName();
        cout << '\n';
    }
};

int main()
{
    Team cardinals("Cardinals", Player("Ada"));
    cardinals.addPlayer(Player("Grace"));
    cardinals.print();
    cardinals.setCoach("Prof. Abbas");
    cardinals.print();
    return 0;
}
