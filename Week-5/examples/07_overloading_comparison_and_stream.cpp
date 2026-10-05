// CSCE 306 | Week 5 • Example 07: Overloading ==, <, << and >> (Ch. 14.5)
// Build: g++ -std=c++17 -Wall -Wextra 07_overloading_comparison_and_stream.cpp -o streamops
// Try:   echo "3 7" | ./streamops

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Version {
private:
    int major, minor;
public:
    Version(int ma = 0, int mi = 0) : major(ma), minor(mi) {}

    bool operator==(const Version& o) const { return major == o.major && minor == o.minor; }
    bool operator!=(const Version& o) const { return !(*this == o); }
    bool operator<(const Version& o) const
    {
        return major < o.major || (major == o.major && minor < o.minor);
    }

    // Stream operators MUST be non-members (left operand is the stream).
    // friend gives them access to private data.
    friend ostream& operator<<(ostream& out, const Version& v)
    {
        return out << 'v' << v.major << '.' << v.minor;   // return the stream for chaining
    }
    friend istream& operator>>(istream& in, Version& v)
    {
        return in >> v.major >> v.minor;
    }
};

int main()
{
    vector<Version> releases = {{2, 1}, {1, 9}, {2, 0}, {1, 10}};
    sort(releases.begin(), releases.end());   // std::sort uses our operator<
    for (const Version& v : releases) cout << v << ' ';
    cout << '\n';

    cout << boolalpha << "v2.0 == v2.0 ? " << (Version(2, 0) == Version(2, 0)) << '\n';

    Version mine;
    cout << "Enter major minor: ";
    if (cin >> mine) cout << "\nYou entered " << mine << '\n';
    return 0;
}
