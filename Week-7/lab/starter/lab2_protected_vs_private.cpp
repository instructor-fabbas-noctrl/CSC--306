// CSCE 306 | Week 7 • Lab Part 2: protected vs private -- Employee -> Manager (STARTER)
// Name: ____________________   Date: __________
// Build: g++ -std=c++17 -Wall -Wextra lab2_protected_vs_private.cpp -o lab2
//
// STEP 1: Write Manager : public Employee with
//           - reports : int (number of direct reports)
//           + Manager(name, salary, reports)
//           + annualPay() : double {query}  = salary + 1000 per direct report
//         Try writing annualPay() using 'salary' directly. It FAILS to compile.
//         Record the exact compiler error message in the comment below.
// STEP 2: Fix it TWO ways and keep the better one:
//           (a) change 'salary' to protected in Employee, or
//           (b) keep it private and add a protected accessor  double baseSalary() const
//         Explain your choice in a comment.
// STEP 3: Employee::raise(pct) must still reject negative percentages for Managers too.
//
// Compiler error from Step 1:
//   ______________________________________________________________
// Which fix did you keep, and why?
//   ______________________________________________________________

#include <iostream>
#include <string>
#include <cmath>
using namespace std;

class Employee {
private:
    string name;
    double salary;
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

// TODO: class Manager

// ----------------------------- test driver -----------------------------
void check(const string& label, bool ok) { cout << (ok ? "PASS  " : "FAIL  ") << label << '\n'; }

int main()
{
    /*  Uncomment when ready
    Manager m("Grace", 80000, 4);
    check("annualPay 84000",       fabs(m.annualPay() - 84000) < 1e-6);
    check("negative raise blocked", !m.raise(-10));
    check("10% raise",             m.raise(10) && fabs(m.annualPay() - 92000) < 1e-6);
    check("inherited getName",     m.getName() == "Grace");
    */
    return 0;
}
