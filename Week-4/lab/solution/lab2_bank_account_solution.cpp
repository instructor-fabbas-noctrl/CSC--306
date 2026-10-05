// CSCE 306 | Week 4 • Lab Part 2: BankAccount -- constructors and destructor (SOLUTION)
// Build: g++ -std=c++17 -Wall -Wextra lab2_bank_account_solution.cpp -o lab2

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

class BankAccount {
private:
    string owner;
    int    accountNumber;
    double balance;

public:
    BankAccount() : owner("Unknown"), accountNumber(0), balance(0.0)
    {
        cout << "Opened #" << accountNumber << " for " << owner << '\n';
    }

    BankAccount(const string& who, int number, double opening = 0.0)
        : owner(who), accountNumber(number), balance(opening < 0 ? 0.0 : opening)
    {
        cout << "Opened #" << accountNumber << " for " << owner << '\n';
    }

    ~BankAccount()
    {
        cout << "Closed #" << accountNumber << " (final balance $" << balance << ")\n";
    }

    bool deposit(double amount)
    {
        if (amount <= 0) return false;
        balance += amount;
        return true;
    }

    bool withdraw(double amount)
    {
        if (amount <= 0 || amount > balance) return false;
        balance -= amount;
        return true;
    }

    string getOwner() const         { return owner; }
    int    getAccountNumber() const { return accountNumber; }
    double getBalance() const       { return balance; }
};

int main()
{
    cout << fixed << setprecision(2);
    BankAccount blank;
    BankAccount ada("Ada", 1001, 100.0);
    BankAccount grace("Grace", 1002, -50.0);
    {
        cout << "-- inner scope --\n";
        BankAccount temp("Temp", 2001, 5.0);
    }
    cout << "-- back in main --\n";
    ada.deposit(50);
    grace.deposit(-10);
    cout << ada.getOwner() << ": " << ada.getBalance()
         << "  " << grace.getOwner() << ": " << grace.getBalance() << '\n';
    cout << "withdraw 500 from Ada -> " << (ada.withdraw(500) ? "ok" : "rejected") << '\n';
    (void)blank;
    return 0;
}
