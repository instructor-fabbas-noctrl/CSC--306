// CSCE 306 | Week 6 • Example 03: The four relationships, side by side
// Build: g++ -std=c++17 -Wall -Wextra 03_relationships_in_code.cpp -o rels
//
//   Dependency   Car - - - -> GasStation   "uses temporarily" (parameter / local)
//   Association  Car ———————> Driver       "knows about"      (pointer/reference member)
//   Aggregation  Fleet ◇————— Car          "has, but does not own" (non-owning container)
//   Composition  Car ◆—————— Engine        "owns; same lifetime"   (value member)
//
// Inheritance (Car ——▷ Vehicle) is the fifth relationship -- Week 7.

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Engine {                                   // part in a composition
private:
    int horsepower;
public:
    explicit Engine(int hp) : horsepower(hp) {}
    int getHorsepower() const { return horsepower; }
};

class Driver {                                   // target of an association
private:
    string name;
public:
    explicit Driver(const string& n) : name(n) {}
    string getName() const { return name; }
};

class GasStation {                               // target of a dependency
public:
    double pricePerGallon() const { return 3.59; }
};

class Car {
private:
    string  model;
    Engine  engine;                              // COMPOSITION: created/destroyed with the Car
    Driver* driver = nullptr;                    // ASSOCIATION: 0..1, may change, not owned
public:
    Car(const string& m, int hp) : model(m), engine(hp) {}
    void assignDriver(Driver* d) { driver = d; }

    // DEPENDENCY: GasStation appears only as a parameter
    double refuel(const GasStation& station, double gallons) const
    {
        return station.pricePerGallon() * gallons;
    }
    void describe() const
    {
        cout << model << " (" << engine.getHorsepower() << " hp), driver: "
             << (driver ? driver->getName() : "none") << '\n';
    }
};

class Fleet {
private:
    vector<Car*> cars;                           // AGGREGATION: Fleet never deletes Cars
public:
    void add(Car* c) { cars.push_back(c); }
    void list() const { for (const Car* c : cars) c->describe(); }
};

int main()
{
    Driver ada("Ada");
    Car sedan("Sedan", 180), van("Van", 220);
    sedan.assignDriver(&ada);

    Fleet campus;
    campus.add(&sedan);
    campus.add(&van);
    campus.list();

    GasStation shell;
    cout << "10 gal costs $" << sedan.refuel(shell, 10) << '\n';
    return 0;
}
