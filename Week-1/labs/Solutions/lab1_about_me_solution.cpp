// CSCE 306 | Week 1 • Lab 1: About Me (SOLUTION)
// Build: g++ -std=c++17 -Wall -Wextra lab1_about_me_solution.cpp -o lab1

#include <iostream>
#include <string>
using namespace std;

int main()
{
    string name     = "Ada Lovelace";
    string major    = "Computer Science";
    int    gradYear = 2028;
    int    courses  = 2;
    bool   usedGit  = true;

    cout << "+------------------------------+\n";
    cout << "| Name:      " << name     << '\n';
    cout << "| Major:     " << major    << '\n';
    cout << "| Grad year: " << gradYear << '\n';
    cout << "| Courses:   " << courses  << '\n';
    cout << "| Used Git?  " << (usedGit ? "yes" : "no") << '\n';  // conditional operator
    cout << "+------------------------------+\n";
    return 0;
}
