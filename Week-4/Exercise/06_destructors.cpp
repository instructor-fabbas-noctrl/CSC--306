// CSCE 306 | Week 4 • Example 06: Destructors and object lifetime (Ch. 13.9)
// Build: g++ -std=c++17 -Wall -Wextra 06_destructors.cpp -o dtors

#include <iostream>
#include <string>
using namespace std;

class Tracer {
private:
    string name;
public:
    explicit Tracer(const string& n) : name(n) { cout << "  construct " << name << '\n'; }
    ~Tracer()                                  { cout << "  destroy   " << name << '\n'; }
    // A destructor: tilde + class name, no parameters, no return type, cannot be overloaded.
};

// A class that OWNS heap memory must release it in its destructor.
class ScoreList {
private:
    int*   scores;
    int    count;
public:
    explicit ScoreList(int n) : scores(new int[n]{}), count(n)
    {
        cout << "  ScoreList allocated " << count << " ints\n";
    }
    ~ScoreList()
    {
        delete[] scores;
        cout << "  ScoreList freed its memory\n";
    }
    void set(int i, int v) { if (i >= 0 && i < count) scores[i] = v; }
    int  get(int i) const  { return (i >= 0 && i < count) ? scores[i] : 0; }

    // NOTE: copying a ScoreList would be dangerous (two objects, one array).
    // We fix that properly with the Rule of Three in Week 5. For now, forbid copies:
    ScoreList(const ScoreList&) = delete;
    ScoreList& operator=(const ScoreList&) = delete;
};

Tracer global("global");   // constructed before main, destroyed after main

int main()
{
    cout << "main starts\n";
    Tracer a("a");
    {
        Tracer b("b");       // destroyed at the closing brace of this block
        Tracer c("c");       // objects are destroyed in REVERSE order of construction
    }
    Tracer* heap = new Tracer("heap");
    delete heap;             // dynamic objects die only when deleted

    ScoreList list(3);
    list.set(1, 95);
    cout << "  list.get(1) = " << list.get(1) << '\n';
    cout << "main ends\n";
    return 0;
}
