// CSCE 306 | Week 6 • Lab Part 4: Sequence diagram -> code -- ATM withdrawal (STARTER)
// Name: ____________________   Date: __________
// Build: g++ -std=c++17 -Wall -Wextra lab4_sequence_to_code.cpp -o lab4
//
//  :ATM                         :Bank                 :Account            :CashDispenser
//   | withdraw(card,pin,amt)     |                       |                       |
//   |--------------------------->| (ATM is the entry point; caller is the user)  |
//   | verify(card, pin)          |                       |                       |
//   |--------------------------->|                       |                       |
//   |<- - - - - account:Account* |   (nullptr if bad)    |                       |
//   | alt [account == nullptr]   |                       |                       |
//   |   return "DENIED: bad PIN" |                       |                       |
//   | [else]                     |                       |                       |
//   |   hasCash(amt)  ------------------------------------------------------->  |
//   |<- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - ok:bool   |
//   |   alt [!ok]  return "DENIED: ATM out of cash"                              |
//   |   debit(amt) ----------------------------------->|                       |
//   |<- - - - - - - - - - - - - - - - - - - - - ok:bool|                       |
//   |   alt [!ok]  return "DENIED: insufficient funds"                           |
//   |   dispense(amt) -------------------------------------------------------> |
//   |   return "OK: dispensed $<amt>, balance $<balance>"                         |
//
// Every class and the Bank::verify / Account / CashDispenser members are GIVEN.
// TODO: implement ATM::withdraw so the calls happen in EXACTLY the order shown.
// Each collaborator records a trace entry, so the test checks the call order too.

#include <iostream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

vector<string> trace;   // records the message sequence for checking

class Account {
    double balance;
public:
    explicit Account(double b) : balance(b) {}
    bool debit(double amt)
    {
        trace.push_back("Account.debit");
        if (amt <= 0 || amt > balance) return false;
        balance -= amt;
        return true;
    }
    double getBalance() const { return balance; }
};

class Bank {
    string  validCard = "4111", validPin = "1234";
    Account account{500.0};
public:
    Account* verify(const string& card, const string& pin)
    {
        trace.push_back("Bank.verify");
        return (card == validCard && pin == validPin) ? &account : nullptr;
    }
};

class CashDispenser {
    double cash;
public:
    explicit CashDispenser(double c) : cash(c) {}
    bool hasCash(double amt) const { trace.push_back("Dispenser.hasCash"); return amt <= cash; }
    void dispense(double amt)      { trace.push_back("Dispenser.dispense"); cash -= amt; }
};

class ATM {
    Bank&          bank;        // associations to collaborators
    CashDispenser& dispenser;
public:
    ATM(Bank& b, CashDispenser& d) : bank(b), dispenser(d) {}

    string withdraw(const string& card, const string& pin, double amt)
    {
        // TODO: follow the sequence diagram
        (void)card; (void)pin; (void)amt;
        return "";
    }
};

// ----------------------------- test driver -----------------------------
void check(const string& label, bool ok) { cout << (ok ? "PASS  " : "FAIL  ") << label << '\n'; }
string joined() { string s; for (auto& t : trace) s += t + ">"; trace.clear(); return s; }

int main()
{
    Bank bank;
    CashDispenser box(300);
    ATM atm(bank, box);

    check("bad pin",   atm.withdraw("4111", "0000", 20) == "DENIED: bad PIN");
    check("bad pin order", joined() == "Bank.verify>");
    check("no cash",   atm.withdraw("4111", "1234", 400) == "DENIED: ATM out of cash");
    check("no cash order", joined() == "Bank.verify>Dispenser.hasCash>");
    check("ok",        atm.withdraw("4111", "1234", 200) == "OK: dispensed $200, balance $300");
    check("ok order",  joined() == "Bank.verify>Dispenser.hasCash>Account.debit>Dispenser.dispense>");
    CashDispenser full(5000);
    ATM atm2(bank, full);
    check("insufficient", atm2.withdraw("4111", "1234", 1000) == "DENIED: insufficient funds");
    check("insufficient order", joined() == "Bank.verify>Dispenser.hasCash>Account.debit>");
    return 0;
}
