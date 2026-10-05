// CSCE 306 | Week 2 • Lab 4: Sales Report -- file I/O + functions (STARTER)
// Name: ____________________   Date: __________
// Build: g++ -std=c++17 -Wall -Wextra lab4_sales_report.cpp -o lab4
// Run from the lab/ folder:   ./lab4 data/sales.txt
//
// Input file: one record per line ->  <region> <amount>
// Write report.txt containing an aligned table plus total, average,
// and the best region. Also echo the report to the screen.
//
// Expected report for data/sales.txt:
//   Region          Sales
//   ---------------------
//   North         1250.50
//   South          980.00
//   East          1432.75
//   West           760.25
//   Central       1105.00
//   ---------------------
//   Total         5528.50
//   Average       1105.70
//   Best region: East
//
// HINT: write one helper that prints to ANY ostream (cout or a file):
//         void printLine(ostream& out, const string& label, double value)

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
using namespace std;

// TODO 1: void printLine(ostream& out, const string& label, double value)

int main(int argc, char* argv[])
{
    string path = (argc > 1) ? argv[1] : "sales.txt";

    ifstream in(path);
    // TODO 2: if the file failed to open, print an error to cerr and return 1

    ofstream report("report.txt");
    // TODO 3: check report opened

    // TODO 4: print header to BOTH cout and report

    // TODO 5: read records in a loop: track total, count, best region/amount;
    //         print each row to BOTH streams

    // TODO 6: print footer lines (total, average, best region)

    return 0;
}
