// CSCE 306 | Week 2 • Lab 3: Function Toolkit (STARTER)
// Name: ____________________   Date: __________
// Build: g++ -std=c++17 -Wall -Wextra lab3_function_toolkit.cpp -o lab3
//
// Implement the five functions below. main() is a test driver -- do not change it.
// When everything is correct, every line prints PASS.

#include <iostream>
#include <string>
using namespace std;

// Returns true if n is prime (n < 2 is NOT prime).
bool isPrime(int n)
{
    // TODO
    (void)n;
    return false;
}

// Returns the sum of the digits of n (treat negatives as positive). 4096 -> 19
int digitSum(int n)
{
    // TODO
    (void)n;
    return 0;
}

// Splits totalCents into dollars and cents through reference parameters. 1234 -> 12, 34
void splitMoney(int totalCents, int& dollars, int& cents)
{
    // TODO
    (void)totalCents; dollars = 0; cents = 0;
}

// Returns text reversed. "OOP!" -> "!POO"
string reversed(const string& text)
{
    // TODO
    (void)text;
    return "";
}

// Overload: clamp value into [low, high] for int AND for double (write both).
int clamp(int value, int low, int high)
{
    // TODO
    (void)low; (void)high;
    return value;
}
// TODO: write   double clamp(double value, double low, double high)

// ----------------------------- test driver -----------------------------
void check(const string& label, bool ok)
{
    cout << (ok ? "PASS  " : "FAIL  ") << label << '\n';
}

int main()
{
    check("isPrime(2)",           isPrime(2));
    check("isPrime(97)",          isPrime(97));
    check("!isPrime(1)",          !isPrime(1));
    check("!isPrime(91)",         !isPrime(91));
    check("digitSum(4096)==19",   digitSum(4096) == 19);
    check("digitSum(-305)==8",    digitSum(-305) == 8);
    int d = -1, c = -1;
    splitMoney(1234, d, c);
    check("splitMoney(1234)",     d == 12 && c == 34);
    check("reversed(\"OOP!\")",    reversed("OOP!") == "!POO");
    check("clamp(15,0,10)==10",   clamp(15, 0, 10) == 10);
    check("clamp(-3,0,10)==0",    clamp(-3, 0, 10) == 0);
    check("clamp(2.5,0.0,1.0)",   clamp(2.5, 0.0, 1.0) == 1.0);
    return 0;
}
