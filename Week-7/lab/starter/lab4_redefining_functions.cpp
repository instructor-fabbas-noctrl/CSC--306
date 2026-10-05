// CSCE 306 | Week 7 • Lab Part 4: Redefining base functions -- CheckingAccount::withdraw (STARTER)
// Name: ____________________   Date: __________
// Build: g++ -std=c++17 -Wall -Wextra lab4_redefining_functions.cpp -o lab4
//
// CheckingAccount : public BankAccount
//   * every withdrawal costs an extra per-transaction FEE (constructor parameter)
//   * overdraft allowed down to -overdraftLimit (constructor parameter)
//   * REDEFINE  bool withdraw(double amt)   -- reject amt <= 0, or if
//               balance - (amt + fee) < -overdraftLimit
//   * REDEFINE  string summary() const     -- "Checking: " + BankAccount::summary()
//               + " (fee $<fee>)"
//   Reuse the base versions with BankAccount:: wherever possible -- do NOT duplicate code.
//   You'll need a protected way to adjust the balance: add  void adjust(double delta)
//   to BankAccount's protected section.
//
// QUESTION (answer in a comment): the last test calls withdraw through a BankAccount&.
// Which version runs, and why? (Week 8 will change this answer.)

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
    // TODO 1: void adjust(double delta)
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

// TODO 2: class CheckingAccount

// ----------------------------- test driver -----------------------------
void check(const string& label, bool ok) { cout << (ok ? "PASS  " : "FAIL  ") << label << '\n'; }

int main()
{
    /*  Uncomment when ready
    CheckingAccount c(100.0, 2.0, 50.0);           // balance, fee, overdraft limit
    check("withdraw 50 -> 48",       c.withdraw(50) && fabs(c.getBalance() - 48.0) < 1e-9);
    check("overdraft to -50 ok",     c.withdraw(96) && fabs(c.getBalance() + 50.0) < 1e-9);
    check("beyond overdraft blocked", !c.withdraw(1));
    check("summary text",            c.summary() == "Checking: balance $-50.00 (fee $2.00)");
    CheckingAccount d(100.0, 2.0, 50.0);
    BankAccount& base = d;
    base.withdraw(10);                              // which withdraw runs?
    check("via base ref: NO fee",    fabs(d.getBalance() - 90.0) < 1e-9);
    */
    return 0;
}
