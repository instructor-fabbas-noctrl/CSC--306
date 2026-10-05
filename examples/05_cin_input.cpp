// CSCE 306 | Week 1 • Example 05: Reading input with cin and getline
// Build: g++ -std=c++17 -Wall -Wextra 05_cin_input.cpp -o input
// Try:   printf "Ada Lovelace\n36\n5.5\n" | ./input

#include <iostream>
#include <string>
using namespace std;

int main()
{
    string fullName;
    int age = 0;
    double height = 0.0;

    cout << "Full name: ";
    getline(cin, fullName);          // reads the WHOLE line, spaces included

    cout << "Age: ";
    cin >> age;                      // >> stops at whitespace

    cout << "Height (ft): ";
    cin >> height;

    // Pitfall: after cin >> x, the '\n' is still in the buffer.
    // If you call getline next, use cin.ignore() first:
    //     cin.ignore(numeric_limits<streamsize>::max(), '\n');

    if (!cin) {                      // stream enters a fail state on bad input
        cout << "\nInput error -- expected a number.\n";
        return 1;
    }

    cout << "\nHello, " << fullName << "! In 10 years you will be "
         << age + 10 << " and still " << height << " ft tall.\n";
    return 0;
}
