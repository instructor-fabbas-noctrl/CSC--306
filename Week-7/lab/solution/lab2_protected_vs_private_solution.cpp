// CSCE 306 | Week 7 • Lab Part 2: protected vs private -- Employee -> Manager (SOLUTION)
// Build: g++ -std=c++17 -Wall -Wextra lab2_protected_vs_private_solution.cpp -o lab2
//
// Compiler error from Step 1 (g++):
//   error: 'double Employee::salary' is private within this context
// Fix kept: (b) private data + protected read-only accessor.
//   * Manager can READ the salary but cannot bypass raise()'s validation by writing it.
//   * Employee can change how salary is stored without breaking derived classes.
//   (a) also compiles, but lets every derived class set salary to anything.

#include <iostream>
#include <string>
#include <cmath>
using namespace std;

class Employee {
private:
    string name;
    double salary;
protected:
    double baseSalary() const { return salary; }   // derived classes may read, not write
public:
    Employee(const string& n, double s) : name(n), salary(s > 0 ? s : 0) {}
    bool raise(double pct)
    {
        if (pct < 0) return false;
        salary *= (1.0 + pct / 100.0);
        return true;
    }
    string getName() const { return name; }
};

class Manager : public Employee {
private:
    int reports;
public:
    static constexpr double PER_REPORT = 1000.0;
    Manager(const string& n, double s, int r) : Employee(n, s), reports(r > 0 ? r : 0) {}
    double annualPay() const { return baseSalary() + PER_REPORT * reports; }
};

// ----------------------------- test driver -----------------------------
void check(const string& label, bool ok) { cout << (ok ? "PASS  " : "FAIL  ") << label << '\n'; }

int main()
{
    Manager m("Grace", 80000, 4);
    check("annualPay 84000",       fabs(m.annualPay() - 84000) < 1e-6);
    check("negative raise blocked", !m.raise(-10));
    check("10% raise",             m.raise(10) && fabs(m.annualPay() - 92000) < 1e-6);
    check("inherited getName",     m.getName() == "Grace");
    return 0;
}
