// CSCE 306 | Week 7 • Example 02: protected members (Ch. 15.2)
// Build: g++ -std=c++17 -Wall -Wextra 02_protected_members.cpp -o protected
//
//   private    -> only the class itself
//   protected  -> the class AND its derived classes      (UML symbol: #)
//   public     -> everyone

#include <iostream>
#include <string>
using namespace std;

class Employee {
private:
    string ssnLast4;                 // derived classes cannot touch this
protected:
    string name;                     // derived classes CAN use these directly
    double baseSalary;
public:
    Employee(const string& n, double s, const string& ssn)
        : ssnLast4(ssn), name(n), baseSalary(s) {}
    string getName() const { return name; }
    string maskedId() const { return "***-**-" + ssnLast4; }
};

class Manager : public Employee {
private:
    double bonusRate;
public:
    Manager(const string& n, double s, const string& ssn, double rate)
        : Employee(n, s, ssn), bonusRate(rate) {}

    double totalPay() const
    {
        return baseSalary * (1.0 + bonusRate);   // OK: protected member of the base
        // return ssnLast4.size();               // ERROR: private in Employee
    }
};

int main()
{
    Manager m("Grace", 90000, "4321", 0.15);
    cout << m.getName() << " (" << m.maskedId() << ") earns $" << m.totalPay() << '\n';
    // m.baseSalary = 0;   // ERROR: protected is still hidden from outside code

    // Design note: protected DATA couples derived classes to the base's representation.
    // Many teams prefer private data + protected accessor functions. Lab 2 explores this.
    return 0;
}
