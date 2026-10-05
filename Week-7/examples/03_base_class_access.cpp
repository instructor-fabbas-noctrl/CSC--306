// CSCE 306 | Week 7 • Example 03: Base class access specifiers -- public/protected/private inheritance (Ch. 15.2)
// Build: g++ -std=c++17 -Wall -Wextra 03_base_class_access.cpp -o access
//
//   Base member is ->      public        protected      private
//   class D : public B     public        protected      (inaccessible)
//   class D : protected B  protected     protected      (inaccessible)
//   class D : private B    private       private        (inaccessible)
//
// Only PUBLIC inheritance models "is-a". In this course, always use public
// inheritance unless you have a specific reason not to.

#include <iostream>
using namespace std;

class Base {
public:    int pub  = 1;
protected: int prot = 2;
private:   int priv = 3;
public:    int getPriv() const { return priv; }
};

class PubD  : public Base    { public: int sum() const { return pub + prot; } };
class ProtD : protected Base { public: int sum() const { return pub + prot; } };
class PrivD : private Base   { public: int sum() const { return pub + prot + getPriv(); } };

int main()
{
    PubD a;  ProtD b;  PrivD c;
    cout << "a.pub = " << a.pub << " (still public)\n";
    // cout << b.pub;          // ERROR: pub became protected in ProtD
    // cout << c.pub;          // ERROR: pub became private in PrivD
    cout << "sums: " << a.sum() << ' ' << b.sum() << ' ' << c.sum() << '\n';

    const Base& ok = a;        // fine: a PubD IS-A Base
    // const Base& no = c;     // ERROR: private inheritance hides the is-a relationship
    (void)ok;
    return 0;
}
