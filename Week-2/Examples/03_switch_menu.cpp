// CSCE 306 | Week 2 • Example 03: switch statement (Ch. 4)
// Build: g++ -std=c++17 -Wall -Wextra 03_switch_menu.cpp -o switch
// Try:   echo B | ./switch

#include <iostream>
#include <cctype>
using namespace std;

int main()
{
    cout << "Choose a plan  [A] Basic  [B] Standard  [C] Premium : ";
    char choice = ' ';
    cin >> choice;

    // switch works on integral types (int, char, enum) -- NOT on strings or doubles
    switch (toupper(choice)) {
        case 'A':
            cout << "Basic: $9.99/month\n";
            break;                       // without break, execution FALLS THROUGH
        case 'B':
            cout << "Standard: $14.99/month\n";
            break;
        case 'C':
            cout << "Premium: $19.99/month\n";
            break;
        default:
            cout << "Invalid choice.\n";
    }

    // Deliberate fall-through: several labels sharing one action
    int month = 2;
    switch (month) {
        case 12: case 1: case 2: cout << "Winter\n"; break;
        case 3:  case 4: case 5: cout << "Spring\n"; break;
        default:                 cout << "Some other season\n";
    }
    return 0;
}
