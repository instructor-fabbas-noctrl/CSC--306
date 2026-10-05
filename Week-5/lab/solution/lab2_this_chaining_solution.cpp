// CSCE 306 | Week 5 • Lab Part 2: this and method chaining -- EmailBuilder (SOLUTION)
// Build: g++ -std=c++17 -Wall -Wextra lab2_this_chaining_solution.cpp -o lab2

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class EmailBuilder {
private:
    vector<string> recipients;
    string         subjectText;
    string         body_;

public:
    EmailBuilder& to(const string& to)
    {
        recipients.push_back(to);
        return *this;
    }
    EmailBuilder& subject(const string& subject)
    {
        subjectText = subject;
        return *this;
    }
    EmailBuilder& body(const string& body)
    {
        this->body_ = body;          // 'this->' makes the target explicit
        return *this;
    }
    bool isReady() const { return !recipients.empty() && !subjectText.empty(); }

    string build() const
    {
        string result = "To: ";
        for (size_t i = 0; i < recipients.size(); ++i)
            result += (i > 0 ? ", " : "") + recipients[i];
        result += "\nSubject: " + subjectText + "\n\n" + body_;
        return result;
    }
};

// ----------------------------- test driver -----------------------------
void check(const string& label, bool ok) { cout << (ok ? "PASS  " : "FAIL  ") << label << '\n'; }

int main()
{
    EmailBuilder e;
    check("not ready when empty", !e.isReady());
    e.to("ada@noctrl.edu").to("grace@noctrl.edu").subject("Lab 2").body("See attached.");
    check("ready after chain", e.isReady());
    string expected = "To: ada@noctrl.edu, grace@noctrl.edu\nSubject: Lab 2\n\nSee attached.";
    check("build() format", e.build() == expected);
    cout << '\n' << e.build() << '\n';
    return 0;
}
