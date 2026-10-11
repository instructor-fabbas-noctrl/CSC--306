// CSCE 306 - Week 8 - Lab 6 (take-home / stretch): Mini plug-in system - a polymorphic Logger
// Combine everything: abstract base, virtual dtor, override, vector<unique_ptr<>>, polymorphic loop.
// Build: g++ -std=c++17 -Wall -Wextra lab6_payroll_mini_project.cpp -o lab6
#include <iostream>
#include <memory>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

class Sink {                                     // abstract "output destination"
public:
    virtual ~Sink() = default;
    virtual void write(const string& msg) = 0;
    virtual string name() const = 0;
};

class ConsoleSink : public Sink {
public:
    void write(const string& msg) override { cout << "  [console] " << msg << "\n"; }
    string name() const override { return "console"; }
};

class BufferSink : public Sink {                 // collects messages in memory (stand-in for a file)
    ostringstream buf; int count = 0;
public:
    //@@BEGIN Step 1: override write() to append msg + '\n' to buf and increment count; override name() to return "buffer"
    //@@STUB void write(const string&) override {}
    //@@STUB string name() const override { return "buffer"; }
    void write(const string& msg) override { buf << msg << '\n'; ++count; }
    string name() const override { return "buffer"; }
    //@@END
    string contents() const { return buf.str(); }
    int size() const { return count; }
};

class UpperSink : public Sink {                  // decorator-ish: upper-cases then forwards
    Sink& next;
public:
    explicit UpperSink(Sink& n) : next(n) {}
    //@@BEGIN Step 2: override write(): upper-case every char of msg (toupper from <cctype>), forward to next.write(); name() returns "upper->" + next.name()
    //@@STUB void write(const string&) override {}
    //@@STUB string name() const override { return "upper"; }
    void write(const string& msg) override {
        string up = msg;
        for (char& c : up) c = static_cast<char>(toupper(static_cast<unsigned char>(c)));
        next.write(up);
    }
    string name() const override { return "upper->" + next.name(); }
    //@@END
};

class Logger {
    vector<Sink*> sinks;                         // non-owning pointers
public:
    void add(Sink& s) { sinks.push_back(&s); }
    void log(const string& msg) { for (Sink* s : sinks) s->write(msg); }
};

int main() {
    ConsoleSink con;
    BufferSink buf;
    UpperSink shout(con);
    Logger log;
    log.add(con); log.add(buf); log.add(shout);
    log.log("polymorphism is flexible");
    log.log("add a sink without touching Logger");
    cout << "Buffer holds " << buf.size() << " messages:\n" << buf.contents();
    // Stretch: write a CountingSink or a FilterSink (only forwards messages containing a keyword).
    return 0;
}
