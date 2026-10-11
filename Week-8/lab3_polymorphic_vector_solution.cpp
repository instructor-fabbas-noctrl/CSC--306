// CSCE 306 - Week 8 - Lab 3: A heterogeneous collection with vector<unique_ptr<Base>>
// Build: g++ -std=c++17 -Wall -Wextra lab3_polymorphic_vector.cpp -o lab3
#include <iostream>
#include <vector>
#include <memory>
#include <string>
#include <iomanip>
using namespace std;

class Employee {
protected:
    string name;
public:
    explicit Employee(const string& n) : name(n) {}
    virtual ~Employee() = default;
    virtual double pay() const = 0;                       // pure virtual
    virtual string title() const { return "Employee"; }   // default behavior
    string getName() const { return name; }
};

class Salaried : public Employee {
    double annual;
public:
    Salaried(const string& n, double a) : Employee(n), annual(a) {}
    double pay() const override { return annual / 52.0; }   // weekly
    string title() const override { return "Salaried"; }
};

class Hourly : public Employee {
    double rate; double hours;
public:
    Hourly(const string& n, double r, double h) : Employee(n), rate(r), hours(h) {}
    //@@BEGIN Step 1: override pay(): time-and-a-half for hours over 40.
    //@@STUB double pay() const override { return 0; }
    double pay() const override {
        if (hours <= 40) return rate * hours;
        return rate * 40 + rate * 1.5 * (hours - 40);
    }
    //@@END
    string title() const override { return "Hourly"; }
};

class Manager : public Salaried {
    double bonus;
public:
    Manager(const string& n, double a, double b) : Salaried(n, a), bonus(b) {}
    //@@BEGIN Step 2: override pay() as Salaried::pay() + bonus, and title() as "Manager"
    //@@STUB double pay() const override { return 0; }
    double pay() const override { return Salaried::pay() + bonus; }
    string title() const override { return "Manager"; }
    //@@END
};

int main() {
    vector<unique_ptr<Employee>> staff;
    //@@BEGIN Step 3: push_back (make_unique<...>) one Salaried, one Hourly (45 hours), one Manager
    staff.push_back(make_unique<Salaried>("Ana", 52000));
    staff.push_back(make_unique<Hourly>("Ben", 20.0, 45));
    staff.push_back(make_unique<Manager>("Cleo", 78000, 500));
    //@@END

    cout << fixed << setprecision(2);
    double total = 0;
    //@@BEGIN Step 4: loop over staff (use `const auto& e`), print title, name, pay; add to total
    //@@STUB for (const auto& e : staff) { (void)e; }
    for (const auto& e : staff) {
        cout << setw(9) << left << e->title() << setw(6) << e->getName() << " $" << e->pay() << "\n";
        total += e->pay();
    }
    //@@END
    cout << "Weekly payroll: $" << total << endl;
    // Step 5 (think): why do we NOT call delete anywhere? What would happen without the virtual destructor?
    return 0;
}
