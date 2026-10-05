// CSCE 306 | Week 7 • Example 06: Redefining base class functions (Ch. 15.4)
// Build: g++ -std=c++17 -Wall -Wextra 06_redefining_base_functions.cpp -o redefine

#include <iostream>
#include <string>
using namespace std;

class Account {
protected:
    double balance;
public:
    explicit Account(double b) : balance(b) {}
    bool withdraw(double amt)
    {
        if (amt <= 0 || amt > balance) return false;
        balance -= amt;
        return true;
    }
    double getBalance() const { return balance; }
    string describe() const   { return "Account"; }
};

class CheckingAccount : public Account {
private:
    double fee;
public:
    CheckingAccount(double b, double f) : Account(b), fee(f) {}

    // REDEFINES Account::withdraw -- same name and parameters.
    // Reuse the base version with the scope resolution operator instead of copying it.
    bool withdraw(double amt)
    {
        return Account::withdraw(amt + fee);
    }
    string describe() const { return "Checking (" + Account::describe() + " + fee)"; }
};

void viaBase(Account& a)        // static (compile-time) binding: calls Account::withdraw
{
    a.withdraw(10);
}

int main()
{
    CheckingAccount chk(100.0, 1.50);
    chk.withdraw(10);                       // CheckingAccount::withdraw -> 88.50
    cout << chk.describe() << ": " << chk.getBalance() << '\n';

    chk.Account::withdraw(10);              // explicitly call the base version -> 78.50
    cout << "after base withdraw:  " << chk.getBalance() << '\n';

    viaBase(chk);                           // !!! base version again -> 68.50, NO fee
    cout << "after viaBase(chk):   " << chk.getBalance() << "  <- fee skipped!\n";
    // Through a base reference the compiler picks the BASE function (static binding).
    // 'virtual' fixes this -- see Example 08 and Week 8.
    return 0;
}
