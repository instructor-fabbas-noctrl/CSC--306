// CSCE 306 | Week 2 • Lab 4: Sales Report -- file I/O + functions (SOLUTION)
// Build: g++ -std=c++17 -Wall -Wextra lab4_sales_report_solution.cpp -o lab4
// Run from the lab/ folder:   ./lab4 data/sales.txt

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
using namespace std;

// Works for cout AND ofstream, because both are ostreams.
void printLine(ostream& out, const string& label, double value)
{
    out << fixed << setprecision(2)
        << left << setw(10) << label << right << setw(11) << value << '\n';
}

void printRule(ostream& out) { out << string(21, '-') << '\n'; }

int main(int argc, char* argv[])
{
    string path = (argc > 1) ? argv[1] : "sales.txt";

    ifstream in(path);
    if (!in) {
        cerr << "Error: cannot open " << path << '\n';
        return 1;
    }
    ofstream report("report.txt");
    if (!report) {
        cerr << "Error: cannot create report.txt\n";
        return 1;
    }

    for (ostream* out : {static_cast<ostream*>(&cout), static_cast<ostream*>(&report)}) {
        *out << left << setw(10) << "Region" << right << setw(11) << "Sales" << '\n';
        printRule(*out);
    }

    string region, bestRegion;
    double amount = 0.0, total = 0.0, bestAmount = 0.0;
    int count = 0;

    while (in >> region >> amount) {
        printLine(cout, region, amount);
        printLine(report, region, amount);
        total += amount;
        if (count == 0 || amount > bestAmount) {
            bestAmount = amount;
            bestRegion = region;
        }
        ++count;
    }

    double average = (count > 0) ? total / count : 0.0;
    for (ostream* out : {static_cast<ostream*>(&cout), static_cast<ostream*>(&report)}) {
        printRule(*out);
        printLine(*out, "Total", total);
        printLine(*out, "Average", average);
        *out << "Best region: " << (count > 0 ? bestRegion : "n/a") << '\n';
    }
    return 0;
}
