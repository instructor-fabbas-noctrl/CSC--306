// CSCE 306 | Week 5 • Lab Part 4: Copy constructor and the Rule of Three -- Playlist (STARTER)
// Name: ____________________   Date: __________
// Build:      g++ -std=c++17 -Wall -Wextra lab4_rule_of_three.cpp -o lab4
// Bug-finder: g++ -std=c++17 -g -fsanitize=address lab4_rule_of_three.cpp -o lab4 && ./lab4
//
// Playlist stores song titles in a DYNAMICALLY ALLOCATED array of std::string.
// The given code has a destructor but NO copy constructor or copy assignment,
// so the test driver crashes (double delete) or corrupts data. Fix it:
//   TODO 1: copy constructor        -- deep copy
//   TODO 2: copy assignment operator -- self-assignment check, deep copy, return *this
// Then run with -fsanitize=address: no errors should be reported.

#include <iostream>
#include <string>
using namespace std;

class Playlist {
private:
    string  name;
    string* songs;
    int     count;
    int     capacity;

    void grow()
    {
        int newCap = capacity * 2;
        string* bigger = new string[newCap];
        for (int i = 0; i < count; ++i) bigger[i] = songs[i];
        delete[] songs;
        songs = bigger;
        capacity = newCap;
    }

public:
    explicit Playlist(const string& n) : name(n), songs(new string[2]), count(0), capacity(2) {}
    ~Playlist() { delete[] songs; }

    // TODO 1: Playlist(const Playlist& other)
    // TODO 2: Playlist& operator=(const Playlist& other)

    void add(const string& title)
    {
        if (count == capacity) grow();
        songs[count++] = title;
    }
    void rename(const string& n) { name = n; }
    int  size() const { return count; }
    string at(int i) const { return (i >= 0 && i < count) ? songs[i] : ""; }

    void print() const
    {
        cout << name << " (" << count << "):";
        for (int i = 0; i < count; ++i) cout << " [" << songs[i] << ']';
        cout << '\n';
    }
};

// ----------------------------- test driver -----------------------------
void check(const string& label, bool ok) { cout << (ok ? "PASS  " : "FAIL  ") << label << '\n'; }

int main()
{
    /*  Uncomment AFTER adding TODO 1 and TODO 2 (it compiles without them, but misbehaves)
    Playlist road("Road Trip");
    road.add("Song A"); road.add("Song B"); road.add("Song C");

    Playlist copy = road;               // copy constructor
    copy.rename("Road Trip (copy)");
    copy.add("Song D");
    check("original unchanged (3)", road.size() == 3);
    check("copy has 4",             copy.size() == 4);

    Playlist gym("Gym");
    gym.add("Pump");
    gym = road;                          // copy assignment
    road.add("Song E");
    check("gym is independent (3)", gym.size() == 3 && gym.at(2) == "Song C");

    gym = gym;                           // self-assignment must be safe
    check("self-assign safe",       gym.size() == 3 && gym.at(0) == "Song A");

    road.print(); copy.print(); gym.print();
    */
    return 0;
}
