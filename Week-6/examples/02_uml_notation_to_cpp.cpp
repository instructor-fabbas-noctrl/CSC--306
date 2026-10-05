// CSCE 306 | Week 6 • Example 02: Reading a UML class box and writing the C++ (Appendix E)
// Build: g++ -std=c++17 -Wall -Wextra 02_uml_notation_to_cpp.cpp -o umlbox
//
//   +--------------------------------------------+
//   | BankAccount                                |
//   +--------------------------------------------+
//   | - owner : string                           |   -  private
//   | - balance : double = 0.0                   |   =  default value
//   | # accountType : string                     |   #  protected (Week 7)
//   | - _count : int_  (underlined = static)     |
//   +--------------------------------------------+
//   | + BankAccount(owner : string, amt : double)|   constructor
//   | + deposit(amt : double) : bool             |   +  public
//   | + getBalance() : double {query}            |   {query} -> const member function
//   | + _getCount() : int_  (underlined)         |   static member function
//   | - isValid(amt : double) : bool             |   private helper
//   +--------------------------------------------+
//
// Mapping rules:   name : Type   ->   Type name;
//                  op(p : T) : R ->   R op(T p);
//                  {query}       ->   const
//                  underlined    ->   static

#include <iostream>
#include <string>
using namespace std;

class BankAccount {
private:
    string owner;
    double balance = 0.0;
    static int count;
    bool isValid(double amt) const { return amt > 0; }

protected:
    string accountType = "basic";

public:
    BankAccount(const string& owner, double amt) : owner(owner) { deposit(amt); ++count; }
    ~BankAccount() { --count; }

    bool deposit(double amt)
    {
        if (!isValid(amt)) return false;
        balance += amt;
        return true;
    }
    double getBalance() const { return balance; }
    static int getCount()     { return count; }
};

int BankAccount::count = 0;

int main()
{
    BankAccount a("Ada", 100), b("Grace", -5);
    cout << "a: " << a.getBalance() << ", b: " << b.getBalance()
         << ", accounts: " << BankAccount::getCount() << '\n';
    return 0;
}
