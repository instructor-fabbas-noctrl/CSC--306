// CSCE 306 | Week 3 • Example 12: Bridge into OOP -- from struct to class (preview of Ch. 13)
// Build: g++ -std=c++17 -Wall -Wextra 12_struct_to_class_bridge.cpp -o bridge

#include <iostream>
#include <string>
using namespace std;

// ---------- Version 1: plain struct. Anyone can break the rules. ----------
struct AccountStruct {
    string owner;
    double balance;
};

// ---------- Version 2: class. Data is private; behavior guards the rules. ----------
class Account {
private:
    string owner;
    double balance = 0.0;      // invariant: balance is never negative

public:
    Account(const string& name, double opening)
        : owner(name), balance(opening >= 0 ? opening : 0.0) {}

    bool withdraw(double amount)
    {
        if (amount <= 0 || amount > balance) return false;   // rule enforced in ONE place
        balance -= amount;
        return true;
    }
    void deposit(double amount) { if (amount > 0) balance += amount; }
    double getBalance() const   { return balance; }
    string getOwner() const     { return owner; }
};

int main()
{
    AccountStruct s{"Ada", 100.0};
    s.balance = -5000;                        // nothing stops this!
    cout << "struct balance: " << s.balance << "  <- invalid state\n";

    Account a("Grace", 100.0);
    // a.balance = -5000;                     // ERROR: 'balance' is private
    bool ok = a.withdraw(5000);
    cout << "withdraw 5000 ok? " << boolalpha << ok
         << "  balance still " << a.getBalance() << '\n';
    a.deposit(25);
    cout << a.getOwner() << " has " << a.getBalance() << '\n';
    // This idea -- ENCAPSULATION -- is where Week 4 begins.
    return 0;
}
