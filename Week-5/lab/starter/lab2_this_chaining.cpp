// CSCE 306 | Week 5 • Lab Part 2: this and method chaining -- EmailBuilder (STARTER)
// Name: ____________________   Date: __________
// Build: g++ -std=c++17 -Wall -Wextra lab2_this_chaining.cpp -o lab2
//
// Each setter takes a parameter with the SAME NAME as the member (use this->)
// and returns EmailBuilder& so calls can be chained.
//   to(const string& to)          -- appends a recipient (several allowed)
//   subject(const string& subject)
//   body(const string& body)
//   build() const -> string, formatted exactly:
//       To: a@x.edu, b@x.edu
//       Subject: <subject>
//
//       <body>
//   isReady() const -> bool : at least one recipient AND a non-empty subject

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class EmailBuilder {
private:
    vector<string> recipients;
    string         subjectText;
    string         body_;
    // Note: a member function named body() and a member variable named body cannot
    // coexist, so the data members use different names. Inside body(const string& body)
    // the PARAMETER hides nothing here -- but practice writing this->body_ anyway.

public:
    // TODO: to, subject, body (each returns EmailBuilder&), build, isReady
};

// ----------------------------- test driver -----------------------------
void check(const string& label, bool ok) { cout << (ok ? "PASS  " : "FAIL  ") << label << '\n'; }

int main()
{
    /*  Uncomment when ready
    EmailBuilder e;
    check("not ready when empty", !e.isReady());
    e.to("ada@noctrl.edu").to("grace@noctrl.edu").subject("Lab 2").body("See attached.");
    check("ready after chain", e.isReady());
    string expected = "To: ada@noctrl.edu, grace@noctrl.edu\nSubject: Lab 2\n\nSee attached.";
    check("build() format", e.build() == expected);
    cout << '\n' << e.build() << '\n';
    */
    return 0;
}
