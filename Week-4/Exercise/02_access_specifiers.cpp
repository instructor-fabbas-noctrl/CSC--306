// CSCE 306 | Week 4 • Example 02: public vs private, struct vs class (Ch. 13.2)
// Build: g++ -std=c++17 -Wall -Wextra 02_access_specifiers.cpp -o access

#include <iostream>
#include <string>
using namespace std;

struct PointS { int x; int y; };          // struct: members are PUBLIC by default
class  PointC { int x = 0; int y = 0; };  // class:  members are PRIVATE by default

class Thermostat {
public:
    void setTarget(double f)
    {
        if (f < MIN_F || f > MAX_F) {
            cout << "  rejected " << f << " (allowed " << MIN_F << "-" << MAX_F << ")\n";
            return;
        }
        target = f;
    }
    double getTarget() const { return target; }

private:
    // Constants and data hidden from users of the class
    static constexpr double MIN_F = 50.0;
    static constexpr double MAX_F = 90.0;
    double target = 68.0;
};

int main()
{
    PointS p{3, 4};
    cout << "struct point: " << p.x << ',' << p.y << '\n';

    PointC q;
    (void)q;   // q.x would not compile -- private by default

    Thermostat t;
    t.setTarget(72);
    t.setTarget(120);
    cout << "Target: " << t.getTarget() << '\n';

    // Convention in this course: use struct for plain passive data,
    // use class whenever there are rules (invariants) to protect.
    return 0;
}
