// CSCE 306 | Week 7 • Lab Part 3: Constructor/destructor order -- Vehicle -> Car (STARTER)
// Name: ____________________   Date: __________
// Build: g++ -std=c++17 -Wall -Wextra lab3_ctor_dtor_order.cpp -o lab3
//
// STEP 1: BEFORE running, write your prediction of the full output in the comment below.
// STEP 2: Finish Car so that:
//           * it has an Engine member (composition) built with the given horsepower
//           * its constructor passes make/year to Vehicle's constructor
//           * every constructor and destructor prints one line (see Vehicle/Engine)
// STEP 3: Run it, compare to your prediction, and explain any differences.
//
// Expected output once Car is complete:
//   Vehicle(Toyota 2024) constructed
//   Engine(203 hp) constructed
//   Car(Camry) constructed
//   Driving a 2024 Toyota Camry with 203 hp
//   Car(Camry) destroyed
//   Engine(203 hp) destroyed
//   Vehicle(Toyota 2024) destroyed
//
// My prediction:
//
// Why this order?
//

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

// TODO: class Car : public Vehicle   -- members: string model; Engine engine;
//       Car(make, year, model, hp); ~Car(); void drive() const;

int main()
{
    /*  Uncomment when ready
    Car c("Toyota", 2024, "Camry", 203);
    c.drive();
    */
    return 0;
}
