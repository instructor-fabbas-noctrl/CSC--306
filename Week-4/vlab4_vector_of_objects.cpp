// CSCE 306 | Week 4 • Vector Lab 4: A vector of objects inside a class -- Playlist (STARTER)
// Name: ____________________   Date: __________
// Build: g++ -std=c++17 -Wall -Wextra vlab4_vector_of_objects.cpp -o vlab4
//
// UML:   Playlist ◆——— 0..* Song        (composition: the Playlist owns its Songs by value)
//
// Song is complete. Implement the Playlist member functions marked TODO. The vector is a
// PRIVATE data member -- outside code can read it through songs() (a const reference) but can
// only change it through Playlist's member functions, which keep the rules (no duplicate titles).

#include <algorithm>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

class Song {
private:
    string title;
    string artist;
    int    seconds;
public:
    Song(const string& t, const string& a, int s) : title(t), artist(a), seconds(s > 0 ? s : 0) {}
    string getTitle() const  { return title; }
    string getArtist() const { return artist; }
    int    getSeconds() const { return seconds; }
};

class Playlist {
private:
    string       name;
    vector<Song> tracks;
public:
    explicit Playlist(const string& n) : name(n) {}

    bool add(const Song& s);                       // false if a song with that title exists
    bool removeByTitle(const string& title);       // false if not found
    const Song* find(const string& title) const;   // nullptr if not found
    int  totalSeconds() const;
    const Song* longest() const;                   // nullptr if empty (first wins ties)
    vector<Song> byArtist(const string& artist) const;   // copies of the matching songs
    void sortByTitle();                            // A..Z
    void sortByLength();                           // shortest first; equal lengths keep order
    string duration() const;                       // total as "m:ss", e.g. "12:05"

    size_t size() const { return tracks.size(); }
    const vector<Song>& songs() const { return tracks; }   // read-only view, no copy
    void print() const;
};

bool Playlist::add(const Song& s)
{
    // TODO: reuse find()
    (void)s; return false;
}

bool Playlist::removeByTitle(const string& title)
{
    // TODO: find the position with a loop or find_if, then tracks.erase(iterator)
    (void)title; return false;
}

const Song* Playlist::find(const string& title) const
{
    // TODO: loop with const Song& and return its address
    (void)title; return nullptr;
}

int Playlist::totalSeconds() const
{
    // TODO
    return 0;
}

const Song* Playlist::longest() const
{
    // TODO
    return nullptr;
}

vector<Song> Playlist::byArtist(const string& artist) const
{
    // TODO: build and return a new vector
    (void)artist; return {};
}

void Playlist::sortByTitle()
{
    // TODO: sort with a lambda comparing getTitle()
}

void Playlist::sortByLength()
{
    // TODO: stable_sort keeps the original order of equal elements
}

string Playlist::duration() const
{
    // TODO: minutes, then seconds padded to 2 digits
    return "";
}

void Playlist::print() const
{
    // TODO: one line per song: title left in width 20, artist left in width 14, then m:ss
}

// ----------------------------- test driver (do not change) -----------------------------
void check(const string& label, bool ok) { cout << (ok ? "PASS  " : "FAIL  ") << label << '\n'; }

int main()
{
    Playlist p("Study Mix");
    check("add 1",                    p.add(Song("Clair de Lune", "Debussy", 302)));
    p.add(Song("Gymnopedie No.1", "Satie", 185));
    p.add(Song("Weightless", "Marconi Union", 485));
    p.add(Song("Arabesque No.1", "Debussy", 240));
    check("duplicate title rejected", !p.add(Song("Weightless", "Someone Else", 100)));
    check("size 4",                   p.size() == 4);
    check("totalSeconds 1212",        p.totalSeconds() == 1212);
    check("duration 20:12",           p.duration() == "20:12");
    check("longest is Weightless",    p.longest() && p.longest()->getTitle() == "Weightless");
    check("find Gymnopedie",          p.find("Gymnopedie No.1") != nullptr);
    check("find missing -> nullptr", p.find("Bolero") == nullptr);
    check("byArtist Debussy == 2",    p.byArtist("Debussy").size() == 2);

    p.sortByTitle();
    check("sortByTitle first",        !p.songs().empty() && p.songs().front().getTitle() == "Arabesque No.1");
    p.sortByLength();
    check("sortByLength order",       p.songs().size() == 4 && p.songs()[0].getSeconds() == 185 && p.songs()[3].getSeconds() == 485);
    check("remove Weightless",        p.removeByTitle("Weightless") && p.size() == 3);
    check("remove missing is false",  !p.removeByTitle("Weightless"));
    p.print();

    Playlist empty("Empty");
    check("empty longest nullptr",    empty.longest() == nullptr && empty.duration() == "0:00");
    return 0;
}
