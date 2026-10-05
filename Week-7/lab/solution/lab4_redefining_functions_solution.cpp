// CSCE 306 | Week 7 • Lab Part 4: Redefining base functions -- CheckingAccount::withdraw (SOLUTION)
// Build: g++ -std=c++17 -Wall -Wextra lab4_redefining_functions_solution.cpp -o lab4
//
// ANSWER: Through a BankAccount& the compiler binds the call at COMPILE time to
// BankAccount::withdraw, because withdraw is not virtual (static binding). So the fee
// and overdraft rules are skipped. Declaring withdraw 'virtual' in BankAccount (Week 8)
// makes the call bind at run time to CheckingAccount::withdraw.

#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include <cmath>
using namespace std;

class BankAccount {
private:
    double balance;
protected:
    void adjust(double delta) { balance += delta; }   // for trusted derived classes only
public:
    explicit BankAccount(double b) : balance(b) {}
    bool withdraw(double amt)
    {
        if (amt <= 0 || amt > balance) return false;
        balance -= amt;
        return true;
    }
    double getBalance() const { return balance; }
    string summary() const
    {
        ostringstream out;
        out << fixed << setprecision(2) << "balance $" << balance;
        return out.str();
    }
};

class CheckingAccount : public BankAccount {
private:
    double fee;
    double overdraftLimit;
public:
    CheckingAccount(double b, double f, double limit)
        : BankAccount(b), fee(f), overdraftLimit(limit) {}

    bool withdraw(double amt)                          // redefinition
    {
        if (amt <= 0) return false;
        double cost = amt + fee;
        if (getBalance() - cost < -overdraftLimit) return false;
        adjust(-cost);
        return true;
    }

    string summary() const                             // redefinition reusing the base
    {
        ostringstream out;
        out << fixed << setprecision(2)
            << "Checking: " << BankAccount::summary() << " (fee $" << fee << ")";
        return out.str();
    }
};

// ----------------------------- test driver -----------------------------
void check(const string& label, bool ok) { cout << (ok ? "PASS  " : "FAIL  ") << label << '\n'; }

int main()
{
    CheckingAccount c(100.0, 2.0, 50.0);
    check("withdraw 50 -> 48",       c.withdraw(50) && fabs(c.getBalance() - 48.0) < 1e-9);
    check("overdraft to -50 ok",     c.withdraw(96) && fabs(c.getBalance() + 50.0) < 1e-9);
    check("beyond overdraft blocked", !c.withdraw(1));
    check("summary text",            c.summary() == "Checking: balance $-50.00 (fee $2.00)");
    CheckingAccount d(100.0, 2.0, 50.0);
    BankAccount& base = d;
    base.withdraw(10);
    check("via base ref: NO fee",    fabs(d.getBalance() - 90.0) < 1e-9);
    return 0;
}
