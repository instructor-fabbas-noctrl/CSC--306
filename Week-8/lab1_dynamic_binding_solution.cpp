// CSCE 306 - Week 8 - Lab 1: Static vs. dynamic binding
// Goal: see why a base-class pointer needs `virtual` to call the derived version.
// Build: g++ -std=c++17 -Wall -Wextra lab1_dynamic_binding.cpp -o lab1
#include <iostream>
#include <string>
using namespace std;

class Account {
protected:
    string owner;
    double balance;
public:
    Account(const string& o, double b) : owner(o), balance(b) {}
    //@@BEGIN Step 1: make describe() virtual (add the keyword in front of the return type)
    //@@STUB string describe() const { return "Account[" + owner + "] $" + to_string(balance); }
    virtual string describe() const { return "Account[" + owner + "] $" + to_string(balance); }
    //@@END
    //@@BEGIN Step 2: add a virtual destructor:  virtual ~Account() = default;
    virtual ~Account() = default;
    //@@END
    double getBalance() const { return balance; }
};

class SavingsAccount : public Account {
    double rate;
public:
    SavingsAccount(const string& o, double b, double r) : Account(o, b), rate(r) {}
    //@@BEGIN Step 3: redefine describe() here. Mark it `override`. Show owner, balance and rate.
    //@@STUB string describe() const { return "Savings(TODO)"; }
    string describe() const override {
        return "Savings[" + owner + "] $" + to_string(balance) + " @ " + to_string(rate * 100) + "%";
    }
    //@@END
};

// Takes a BASE reference - the dynamic type decides which describe() runs (if virtual).
void show(const Account& a) { cout << "  show(): " << a.describe() << endl; }

int main() {
    Account a("Ada", 100.0);
    SavingsAccount s("Grace", 2500.0, 0.03);

    cout << "1) Direct objects:\n";
    cout << "  " << a.describe() << "\n  " << s.describe() << "\n";

    cout << "2) Base pointer -> derived object:\n";
    Account* p = &s;
    cout << "  " << p->describe() << endl;   // Which version prints? Predict BEFORE you run!

    cout << "3) Base reference parameter:\n";
    show(a);
    show(s);

    //@@BEGIN Step 4: create a SavingsAccount with new, store it in an Account*, call describe(), then delete it.
    //@@END
    Account* heap = new SavingsAccount("Linus", 40.0, 0.01);
    cout << "4) Heap object via base pointer:\n  " << heap->describe() << endl;
    delete heap;
    return 0;
}
