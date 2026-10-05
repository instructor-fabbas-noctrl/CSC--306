// CSCE 306 — Object-Oriented Software Development | Fall 2026
// Week 6 • Example 01: From requirements to classes -- noun/verb analysis (OOA)
// Build: g++ -std=c++17 -Wall -Wextra 01_noun_verb_analysis.cpp -o nouns
//
// REQUIREMENTS (problem statement)
//   "A *library* lends *books* to *members*. Each book has a *title*, an *author*,
//    and an *ISBN*. A member can *borrow* up to three books at a time and must
//    *return* them within 14 days. The library *tracks* which member has each book."
//
// STEP 1 -- candidate classes = nouns:   library, book, member, title, author, ISBN, day
// STEP 2 -- filter: title/author/ISBN are ATTRIBUTES of Book (simple values, no behavior);
//                   "day" is an attribute of a loan; library is the system/controller.
// STEP 3 -- responsibilities = verbs:    borrow, return, track
// STEP 4 -- assign each verb to the class that has the information to do it:
//              Member::canBorrow()   (knows how many books it holds)
//              Library::checkOut()   (knows all books and members; coordinates)
//
// UML class diagram (text form):
//   +----------------------+        +---------------------------+
//   | Book                 |        | Member                    |
//   +----------------------+        +---------------------------+
//   | - title : string     |        | - name : string           |
//   | - author : string    |  0..3  | - borrowed : int          |
//   | - isbn : string      |<-------| + MAX_BOOKS : int = 3     |
//   | - borrower : Member* |        +---------------------------+
//   +----------------------+        | + canBorrow() : bool      |
//   | + isAvailable():bool |        +---------------------------+
//   +----------------------+

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Member {
private:
    string name;
    int    borrowed = 0;
public:
    static constexpr int MAX_BOOKS = 3;
    explicit Member(const string& n) : name(n) {}
    bool   canBorrow() const { return borrowed < MAX_BOOKS; }
    void   tookBook()        { ++borrowed; }
    void   gaveBack()        { if (borrowed > 0) --borrowed; }
    string getName() const   { return name; }
};

class Book {
private:
    string  title, author, isbn;
    Member* borrower = nullptr;          // association: who has it right now (0..1)
public:
    Book(const string& t, const string& a, const string& i) : title(t), author(a), isbn(i) {}
    bool    isAvailable() const     { return borrower == nullptr; }
    void    lendTo(Member* m)       { borrower = m; }
    void    giveBack()              { borrower = nullptr; }
    string  getTitle() const        { return title; }
    Member* getBorrower() const     { return borrower; }
};

class Library {
private:
    vector<Book> books;                  // composition: the library owns its catalog
public:
    void add(const Book& b) { books.push_back(b); }
    bool checkOut(const string& title, Member& m)
    {
        if (!m.canBorrow()) return false;
        for (Book& b : books)
            if (b.getTitle() == title && b.isAvailable()) {
                b.lendTo(&m);
                m.tookBook();
                return true;
            }
        return false;
    }
    void report() const
    {
        for (const Book& b : books)
            cout << "  " << b.getTitle() << " -> "
                 << (b.isAvailable() ? "on shelf" : b.getBorrower()->getName()) << '\n';
    }
};

int main()
{
    Library lib;
    lib.add(Book("Design Patterns", "Gamma et al.", "0201633612"));
    lib.add(Book("Clean Code", "Martin", "0132350882"));
    Member ada("Ada");
    cout << boolalpha << "checkOut Clean Code: " << lib.checkOut("Clean Code", ada) << '\n';
    lib.report();
    return 0;
}
