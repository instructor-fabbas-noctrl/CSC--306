// CSCE 306 - Week 8 - Lab 5: override, final, dynamic_cast, typeid
// Build: g++ -std=c++17 -Wall -Wextra lab5_override_final_dynamic_cast.cpp -o lab5
#include <iostream>
#include <vector>
#include <memory>
#include <typeinfo>
using namespace std;

class Vehicle {
public:
    virtual ~Vehicle() = default;
    virtual string kind() const { return "Vehicle"; }
    virtual int wheels() const = 0;
};

class Car : public Vehicle {
public:
    string kind() const override { return "Car"; }
    int wheels() const override { return 4; }
    void honk() const { cout << "  Beep beep!\n"; }
};

class Truck final : public Vehicle {          // 'final' class: nobody may derive from Truck
public:
    string kind() const override { return "Truck"; }
    int wheels() const override { return 6; }
    void load(int tons) const { cout << "  Loaded " << tons << " tons\n"; }
};

class Bike : public Vehicle {
public:
    //@@BEGIN Step 1: add `override` to wheels(). Then misspell it (wheel) and read the compiler error. Fix it.
    //@@STUB int wheels() const { return 2; }
    int wheels() const override { return 2; }
    //@@END
};

int main() {
    vector<unique_ptr<Vehicle>> v;
    v.push_back(make_unique<Car>());
    v.push_back(make_unique<Truck>());
    v.push_back(make_unique<Bike>());

    for (const auto& p : v) {
        cout << p->kind() << " has " << p->wheels() << " wheels, dynamic type: " << typeid(*p).name() << "\n";
        //@@BEGIN Step 2: use dynamic_cast<const Car*>(p.get()) and call honk() only if the cast succeeds; do the same for Truck::load(5)
        if (auto c = dynamic_cast<const Car*>(p.get())) c->honk();
        if (auto t = dynamic_cast<const Truck*>(p.get())) t->load(5);
        //@@END
    }
    // Step 3 (think): is dynamic_cast a sign of good design? When would a virtual function be better?
    return 0;
}
