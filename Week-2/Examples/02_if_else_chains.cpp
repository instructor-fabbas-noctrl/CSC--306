// CSCE 306 | Week 2 • Example 02: if / else if / else (Ch. 4)
// Build: g++ -std=c++17 -Wall -Wextra 02_if_else_chains.cpp -o ifelse

#include <iostream>
using namespace std;

char letterFor(double score)
{
    // Order matters: test the highest threshold first.
    if (score >= 90)      return 'A';
    else if (score >= 80) return 'B';
    else if (score >= 70) return 'C';
    else if (score >= 60) return 'D';
    else                  return 'F';
}

int main()
{
    double scores[] = {95.5, 82.0, 70.0, 59.9, 100.0};
    for (double s : scores)
        cout << s << " -> " << letterFor(s) << '\n';

    // Common bug: = vs ==
    int x = 0;
    if (x == 0) cout << "x is zero (correct: ==)\n";
    // if (x = 0) ...   // assigns 0, condition is false -- compiler warns with -Wall

    // Floating point equality: compare with a tolerance, not ==
    double sum = 0.1 + 0.2;
    if (sum == 0.3) cout << "equal\n";
    else            cout << "0.1 + 0.2 != 0.3 exactly (floating point!)\n";
    return 0;
}
