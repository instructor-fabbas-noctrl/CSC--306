// CSCE 306 | Week 2 • Example 10: Basic file I/O with ofstream / ifstream (Ch. 5)
// Build: g++ -std=c++17 -Wall -Wextra 10_file_io.cpp -o fileio
// Creates scores.txt in the current directory, then reads it back.

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
    // ---- Write ----
    ofstream out("scores.txt");
    if (!out) {                       // ALWAYS check that the file opened
        cerr << "Could not create scores.txt\n";
        return 1;
    }
    out << "Ada 95\n" << "Grace 88\n" << "Alan 91\n";
    out.close();

    // ---- Read: the loop condition is the read itself ----
    ifstream in("scores.txt");
    if (!in) {
        cerr << "Could not open scores.txt\n";
        return 1;
    }
    string name;
    int score = 0, total = 0, count = 0;
    while (in >> name >> score) {     // stops at end-of-file or bad data
        cout << name << " scored " << score << '\n';
        total += score;
        ++count;
    }
    in.close();

    if (count > 0)
        cout << "Average: " << static_cast<double>(total) / count << '\n';
    return 0;
}
