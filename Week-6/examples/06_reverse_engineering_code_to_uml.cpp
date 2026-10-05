// CSCE 306 | Week 6 • Example 06: Reverse translation -- read C++, draw the UML
// Build: g++ -std=c++17 -Wall -Wextra 06_reverse_engineering_code_to_uml.cpp -o reverse
//
// Read the classes below FIRST and sketch the diagram yourself. Then compare:
//
//   +-------------------------------+          +----------------------------+
//   | Playlist                      |◆———————— | Song                       |
//   +-------------------------------+ 1    0..*+----------------------------+
//   | - name : string               |          | - title : string           |
//   | - songs : vector<Song>        |          | - seconds : int            |
//   | - _created : int_             |          +----------------------------+
//   +-------------------------------+          | + Song(t : string, s : int)|
//   | + Playlist(n : string)        |          | + getSeconds() : int {query}|
//   | + add(s : Song) : void        |          +----------------------------+
//   | + totalSeconds() : int {query}|
//   | + _created() : int_           |- - - - - > Formatter  (dependency: parameter only)
//   | + show(f : Formatter) {query} |
//   +-------------------------------+
//
// Clues: vector<Song> by VALUE -> composition; a class used only as a parameter ->
// dependency; static -> underline; const member function -> {query}.

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Song {
    string title;
    int    seconds;
public:
    Song(const string& t, int s) : title(t), seconds(s) {}
    int    getSeconds() const { return seconds; }
    string getTitle() const   { return title; }
};

class Formatter {
public:
    string mmss(int secs) const
    {
        return to_string(secs / 60) + ":" + (secs % 60 < 10 ? "0" : "") + to_string(secs % 60);
    }
};

class Playlist {
    string       name;
    vector<Song> songs;
    static int   createdCount;
public:
    explicit Playlist(const string& n) : name(n) { ++createdCount; }
    void add(const Song& s) { songs.push_back(s); }
    int  totalSeconds() const
    {
        int t = 0;
        for (const Song& s : songs) t += s.getSeconds();
        return t;
    }
    static int created() { return createdCount; }
    void show(const Formatter& f) const
    {
        cout << name << " [" << f.mmss(totalSeconds()) << "]\n";
        for (const Song& s : songs) cout << "  " << s.getTitle() << " " << f.mmss(s.getSeconds()) << '\n';
    }
};
int Playlist::createdCount = 0;

int main()
{
    Playlist p("Focus");
    p.add(Song("Track One", 185));
    p.add(Song("Track Two", 247));
    p.show(Formatter());
    cout << "playlists created: " << Playlist::created() << '\n';
    return 0;
}
