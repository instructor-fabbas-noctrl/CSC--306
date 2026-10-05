// CSCE 306 | Week 4 • Lab Part 2: BankAccount -- constructors and destructor (STARTER)
// Name: ____________________   Date: __________
// Build: g++ -std=c++17 -Wall -Wextra lab2_bank_account.cpp -o lab2
//
// Requirements
//  * Members: owner (string), accountNumber (int), balance (double)
//  * Default constructor: owner "Unknown", accountNumber 0, balance 0.0
//  * Constructor (owner, accountNumber, openingBalance = 0.0) using a MEMBER
//    INITIALIZER LIST. A negative opening balance is stored as 0.0.
//  * Both constructors print:  "Opened #<num> for <owner>"
//  * Destructor prints:         "Closed #<num> (final balance $<balance>)"
//  * deposit(amount)  -> bool   (reject amount <= 0)
//  * withdraw(amount) -> bool   (reject amount <= 0 or amount > balance)
//  * const accessors: getOwner, getAccountNumber, getBalance
//
// Expected output of the provided main():
//   Opened #0 for Unknown
//   Opened #1001 for Ada
//   Opened #1002 for Grace
//   -- inner scope --
//   Opened #2001 for Temp
//   Closed #2001 (final balance $5.00)
//   -- back in main --
//   Ada: 150.00  Grace: 0.00
//   withdraw 500 from Ada -> rejected
//   Closed #1002 (final balance $0.00)
//   Closed #1001 (final balance $150.00)
//   Closed #0 (final balance $0.00)

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

class BankAccount {
    // TODO: data members, constructors, destructor, member functions
};

int main()
{
    /*  Uncomment when your class is complete
    cout << fixed << setprecision(2);
    BankAccount blank;
    BankAccount ada("Ada", 1001, 100.0);
    BankAccount grace("Grace", 1002, -50.0);     // negative -> 0.0
    {
        cout << "-- inner scope --\n";
        BankAccount temp("Temp", 2001, 5.0);
    }
    cout << "-- back in main --\n";
    ada.deposit(50);
    grace.deposit(-10);                           // rejected silently
    cout << ada.getOwner() << ": " << ada.getBalance()
         << "  " << grace.getOwner() << ": " << grace.getBalance() << '\n';
    cout << "withdraw 500 from Ada -> " << (ada.withdraw(500) ? "ok" : "rejected") << '\n';
    (void)blank;
    */
    return 0;
}
