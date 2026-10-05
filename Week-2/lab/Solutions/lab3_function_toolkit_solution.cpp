// CSCE 306 | Week 2 • Lab 3: Function Toolkit (SOLUTION)
// Build: g++ -std=c++17 -Wall -Wextra lab3_function_toolkit_solution.cpp -o lab3

#include <iostream>
#include <string>
using namespace std;

bool isPrime(int n)
{
    if (n < 2) return false;
    for (int d = 2; d * d <= n; ++d)      // only need to test up to sqrt(n)
        if (n % d == 0) return false;
    return true;
}

int digitSum(int n)
{
    if (n < 0) n = -n;
    int sum = 0;
    while (n > 0) {
        sum += n % 10;   // peel off the last digit
        n /= 10;
    }
    return sum;
}

void splitMoney(int totalCents, int& dollars, int& cents)
{
    dollars = totalCents / 100;
    cents   = totalCents % 100;
}

string reversed(const string& text)
{
    string result;
    for (int i = static_cast<int>(text.size()) - 1; i >= 0; --i)
        result += text[i];
    return result;
}

int clamp(int value, int low, int high)
{
    if (value < low)  return low;
    if (value > high) return high;
    return value;
}

double clamp(double value, double low, double high)
{
    if (value < low)  return low;
    if (value > high) return high;
    return value;
}

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
