// CSCE 306 | Week 3 • Example 04: std::vector -- the array you should usually reach for (Ch. 7)
// Build: g++ -std=c++17 -Wall -Wextra 04_vector_intro.cpp -o vec

#include <iostream>
#include <vector>
#include <string>
using namespace std;

void printAll(const vector<string>& names)   // pass by const reference: no copy
{
    for (const string& n : names) cout << "  " << n << '\n';
}

int main()
{
    vector<string> roster = {"Ada", "Grace"};   // knows its own size
    roster.push_back("Alan");                   // grows on demand
    roster.push_back("Barbara");

    cout << "Roster has " << roster.size() << " students:\n";
    printAll(roster);

    roster.pop_back();                          // remove last
    cout << "front=" << roster.front() << " back=" << roster.back() << '\n';

    // .at() IS bounds-checked (throws std::out_of_range); [] is not.
    cout << "roster.at(1) = " << roster.at(1) << '\n';

    vector<int> squares(5);                     // five zeros
    for (size_t i = 0; i < squares.size(); ++i) squares[i] = static_cast<int>(i * i);
    for (int s : squares) cout << s << ' ';
    cout << '\n';
    return 0;
}
