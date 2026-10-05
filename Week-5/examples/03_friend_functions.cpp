// CSCE 306 | Week 5 • Example 03: Friend functions and friend classes (Ch. 14.3)
// Build: g++ -std=c++17 -Wall -Wextra 03_friend_functions.cpp -o friends

#include <iostream>
#include <string>
using namespace std;

class Vault;   // forward declaration

class Auditor {
public:
    void inspect(const Vault& v) const;   // defined after Vault is complete
};

class Vault {
private:
    string label;
    double gold;

public:
    Vault(const string& l, double g) : label(l), gold(g) {}

    // A friend FUNCTION is not a member, but may access private members.
    friend bool sameContents(const Vault& a, const Vault& b);

    // A friend CLASS: every member function of Auditor can see Vault's privates.
    friend class Auditor;
};

bool sameContents(const Vault& a, const Vault& b)
{
    return a.gold == b.gold;              // OK: friend
}

void Auditor::inspect(const Vault& v) const
{
    cout << "Audit " << v.label << ": " << v.gold << " oz\n";
}

int main()
{
    Vault v1("North", 120.5), v2("South", 120.5);
    cout << boolalpha << "same contents? " << sameContents(v1, v2) << '\n';
    Auditor a;
    a.inspect(v1);

    // Friendship is GRANTED by the class, never taken. It is not inherited and not
    // symmetric. Use it sparingly -- mainly for operators like << (see Example 08).
    return 0;
}
