// CSCE 306 | Week 7 • Lab Part 1: Account -> SavingsAccount (STARTER)
// Name: ____________________   Date: __________
// Build: g++ -std=c++17 -Wall -Wextra lab1_account_savings.cpp -o lab1
//
// UML:   Account <|—— SavingsAccount
//
// Account is GIVEN. Write SavingsAccount, which publicly inherits from Account and adds:
//   - rate : double                   annual interest rate, e.g. 0.04
//   + SavingsAccount(owner, opening, rate)    -- pass owner/opening to Account's ctor
//   + addMonthlyInterest() : double           -- deposits balance * rate / 12, returns it
//   + getRate() : double {query}

#include <iostream>
#include <string>
#include <cmath>
using namespace std;

class Account {
private:
    string owner;
    double balance;
public:
    Account(const string& o, double opening) : owner(o), balance(opening > 0 ? opening : 0) {}
    bool deposit(double amt)  { if (amt <= 0) return false; balance += amt; return true; }
    bool withdraw(double amt) { if (amt <= 0 || amt > balance) return false; balance -= amt; return true; }
    double getBalance() const { return balance; }
    string getOwner() const   { return owner; }
};

// TODO: class SavingsAccount : public Account { ... };

// ----------------------------- test driver -----------------------------
void check(const string& label, bool ok) { cout << (ok ? "PASS  " : "FAIL  ") << label << '\n'; }

int main()
{
    /*  Uncomment when ready
    SavingsAccount s("Ada", 1200.0, 0.05);
    check("inherited getOwner",   s.getOwner() == "Ada");
    check("opening balance 1200", s.getBalance() == 1200.0);
    double earned = s.addMonthlyInterest();
    check("interest 5.00",        fabs(earned - 5.0) < 1e-9);
    check("balance 1205",         fabs(s.getBalance() - 1205.0) < 1e-9);
    check("inherited withdraw",   s.withdraw(205) && fabs(s.getBalance() - 1000.0) < 1e-9);
    const Account& asBase = s;    // is-a
    check("usable as Account",    fabs(asBase.getBalance() - 1000.0) < 1e-9);
    */
    return 0;
}
