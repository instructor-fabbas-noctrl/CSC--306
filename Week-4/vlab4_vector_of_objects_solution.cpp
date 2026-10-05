// CSCE 306 | Week 4 • Vector Lab 4: A vector of objects inside a class -- Playlist (SOLUTION)
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
    if (find(s.getTitle()) != nullptr) return false;
    tracks.push_back(s);
    return true;
}

bool Playlist::removeByTitle(const string& title)
{
    auto it = find_if(tracks.begin(), tracks.end(),
                      [&title](const Song& s) { return s.getTitle() == title; });
    if (it == tracks.end()) return false;
    tracks.erase(it);
    return true;
}

const Song* Playlist::find(const string& title) const
{
    for (const Song& s : tracks)
        if (s.getTitle() == title) return &s;
    return nullptr;
}

int Playlist::totalSeconds() const
{
    int total = 0;
    for (const Song& s : tracks) total += s.getSeconds();
    return total;
}

const Song* Playlist::longest() const
{
    const Song* best = nullptr;
    for (const Song& s : tracks)
        if (best == nullptr || s.getSeconds() > best->getSeconds()) best = &s;
    return best;
}

vector<Song> Playlist::byArtist(const string& artist) const
{
    vector<Song> result;
    for (const Song& s : tracks)
        if (s.getArtist() == artist) result.push_back(s);
    return result;
}

void Playlist::sortByTitle()
{
    sort(tracks.begin(), tracks.end(),
         [](const Song& a, const Song& b) { return a.getTitle() < b.getTitle(); });
}

void Playlist::sortByLength()
{
    stable_sort(tracks.begin(), tracks.end(),
                [](const Song& a, const Song& b) { return a.getSeconds() < b.getSeconds(); });
}

string Playlist::duration() const
{
    int total = totalSeconds();
    ostringstream out;
    out << total / 60 << ':' << setfill('0') << setw(2) << total % 60;
    return out.str();
}

void Playlist::print() const
{
    cout << name << " (" << tracks.size() << " songs, " << duration() << ")\n";
    for (const Song& s : tracks)
        cout << "  " << left << setw(20) << s.getTitle() << setw(14) << s.getArtist() << right
             << s.getSeconds() / 60 << ':' << setfill('0') << setw(2) << s.getSeconds() % 60
             << setfill(' ') << '\n';
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
