// CSCE 306 | Week 5 • Lab Part 4: Copy constructor and the Rule of Three -- Playlist (SOLUTION)
// Build: g++ -std=c++17 -Wall -Wextra -fsanitize=address lab4_rule_of_three_solution.cpp -o lab4

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

    // Deep copy: our own array, same contents
    Playlist(const Playlist& other)
        : name(other.name), songs(new string[other.capacity]),
          count(other.count), capacity(other.capacity)
    {
        for (int i = 0; i < count; ++i) songs[i] = other.songs[i];
    }

    Playlist& operator=(const Playlist& other)
    {
        if (this == &other) return *this;               // self-assignment guard
        string* fresh = new string[other.capacity];     // allocate before releasing
        for (int i = 0; i < other.count; ++i) fresh[i] = other.songs[i];
        delete[] songs;
        songs    = fresh;
        name     = other.name;
        count    = other.count;
        capacity = other.capacity;
        return *this;
    }

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
    Playlist road("Road Trip");
    road.add("Song A"); road.add("Song B"); road.add("Song C");

    Playlist copy = road;
    copy.rename("Road Trip (copy)");
    copy.add("Song D");
    check("original unchanged (3)", road.size() == 3);
    check("copy has 4",             copy.size() == 4);

    Playlist gym("Gym");
    gym.add("Pump");
    gym = road;
    road.add("Song E");
    check("gym is independent (3)", gym.size() == 3 && gym.at(2) == "Song C");

    gym = gym;
    check("self-assign safe",       gym.size() == 3 && gym.at(0) == "Song A");

    road.print(); copy.print(); gym.print();
    return 0;
}
