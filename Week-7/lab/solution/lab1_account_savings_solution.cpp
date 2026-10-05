// CSCE 306 | Week 7 • Lab Part 1: Account -> SavingsAccount (SOLUTION)
// Build: g++ -std=c++17 -Wall -Wextra lab1_account_savings_solution.cpp -o lab1

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

class SavingsAccount : public Account {
private:
    double rate;
public:
    SavingsAccount(const string& owner, double opening, double r)
        : Account(owner, opening), rate(r) {}

    // balance is PRIVATE in Account, so we go through the public interface
    double addMonthlyInterest()
    {
        double interest = getBalance() * rate / 12.0;
        deposit(interest);
        return interest;
    }
    double getRate() const { return rate; }
};

// ----------------------------- test driver -----------------------------
void check(const string& label, bool ok) { cout << (ok ? "PASS  " : "FAIL  ") << label << '\n'; }

int main()
{
    SavingsAccount s("Ada", 1200.0, 0.05);
    check("inherited getOwner",   s.getOwner() == "Ada");
    check("opening balance 1200", s.getBalance() == 1200.0);
    double earned = s.addMonthlyInterest();
    check("interest 5.00",        fabs(earned - 5.0) < 1e-9);
    check("balance 1205",         fabs(s.getBalance() - 1205.0) < 1e-9);
    check("inherited withdraw",   s.withdraw(205) && fabs(s.getBalance() - 1000.0) < 1e-9);
    const Account& asBase = s;
    check("usable as Account",    fabs(asBase.getBalance() - 1000.0) < 1e-9);
    return 0;
}
