// CSCE 306 | Week 7 • Lab Part 3: Constructor/destructor order -- Vehicle -> Car (SOLUTION)
// Build: g++ -std=c++17 -Wall -Wextra lab3_ctor_dtor_order_solution.cpp -o lab3
//
// Why this order?
//   Construction: base class first (Vehicle), then data members in declaration order
//   (Engine), then the body of the derived constructor (Car). The order you write in
//   the initializer list does NOT change this.
//   Destruction: the exact reverse -- Car's body, then members, then the base.

#include <iostream>
#include <string>
using namespace std;

class Vehicle {
protected:
    string make;
    int    year;
public:
    Vehicle(const string& m, int y) : make(m), year(y)
    {
        cout << "Vehicle(" << make << ' ' << year << ") constructed\n";
    }
    ~Vehicle() { cout << "Vehicle(" << make << ' ' << year << ") destroyed\n"; }
};

class Engine {
    int hp;
public:
    explicit Engine(int h) : hp(h) { cout << "Engine(" << hp << " hp) constructed\n"; }
    ~Engine()                      { cout << "Engine(" << hp << " hp) destroyed\n"; }
    int getHp() const { return hp; }
};

class Car : public Vehicle {
private:
    string model;
    Engine engine;
public:
    Car(const string& make, int year, const string& m, int hp)
        : Vehicle(make, year), model(m), engine(hp)
    {
        cout << "Car(" << model << ") constructed\n";
    }
    ~Car() { cout << "Car(" << model << ") destroyed\n"; }

    void drive() const
    {
        cout << "Driving a " << year << ' ' << make << ' ' << model
             << " with " << engine.getHp() << " hp\n";
    }
};

int main()
{
    Car c("Toyota", 2024, "Camry", 203);
    c.drive();
    return 0;
}
