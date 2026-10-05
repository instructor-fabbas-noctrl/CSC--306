// CSCE 306 | Week 4 • Vector Lab 3: Two-dimensional vectors -- Gradebook Grid (SOLUTION)
// Build: g++ -std=c++17 -Wall -Wextra vlab3_2d_vectors.cpp -o vlab3
//
// A vector<vector<int>> is a vector whose elements are vectors -- a grid whose rows can be
// built at run time. Here each ROW is one student and each COLUMN is one exam:
//     grid[s][e] = score of student s on exam e
// Unlike a built-in 2-D array, rows may have different lengths ("jagged"), so always use
// grid[r].size() for the column count of row r.

#include <iomanip>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

using Grid = vector<vector<int>>;     // type alias keeps signatures readable

// Builds a rows x cols grid filled with value  (hint: vector<vector<int>>(rows, vector<int>(cols, value)))
Grid makeGrid(int rows, int cols, int value)
{
    return Grid(rows, vector<int>(cols, value));
}

// Sum of one row (one student's total). Returns 0 for an invalid row index.
int rowTotal(const Grid& g, size_t row)
{
    if (row >= g.size()) return 0;
    int sum = 0;
    for (int x : g[row]) sum += x;
    return sum;
}

// Average of one column (one exam) over the rows that HAVE that column (jagged-safe).
// Returns 0.0 if no row has that column.
double columnAverage(const Grid& g, size_t col)
{
    int sum = 0, count = 0;
    for (const vector<int>& row : g)
        if (col < row.size()) { sum += row[col]; ++count; }
    return count == 0 ? 0.0 : static_cast<double>(sum) / count;
}

// Index of the row with the largest total (first one wins ties); -1 if the grid is empty.
int bestRow(const Grid& g)
{
    if (g.empty()) return -1;
    size_t best = 0;
    for (size_t r = 1; r < g.size(); ++r)
        if (rowTotal(g, r) > rowTotal(g, best)) best = r;
    return static_cast<int>(best);
}

// Transpose of a RECTANGULAR grid: result[c][r] == g[r][c].  Empty grid -> empty result.
Grid transpose(const Grid& g)
{
    if (g.empty()) return {};
    Grid t(g[0].size(), vector<int>(g.size()));
    for (size_t r = 0; r < g.size(); ++r)
        for (size_t c = 0; c < g[r].size(); ++c) t[c][r] = g[r][c];
    return t;
}

// Adds bonus points to every score in column col (rows that have it), capping at 100.
void curveExam(Grid& g, size_t col, int bonus)
{
    for (vector<int>& row : g)
        if (col < row.size()) row[col] = min(100, row[col] + bonus);
}

// Prints the grid, each value in a field of width 5, one row per line.
void printGrid(const Grid& g)
{
    for (const vector<int>& row : g) {
        for (int x : row) cout << setw(5) << x;
        cout << '\n';
    }
}

// ----------------------------- test driver (do not change) -----------------------------
void check(const string& label, bool ok) { cout << (ok ? "PASS  " : "FAIL  ") << label << '\n'; }

int main()
{
    Grid z = makeGrid(2, 3, 7);
    check("makeGrid 2x3 of 7",            z.size() == 2 && z[0].size() == 3 && z[1][2] == 7);

    Grid scores = {
        {90, 85, 77},       // student 0
        {60, 72, 98},       // student 1
        {95, 93, 88},       // student 2
    };
    printGrid(scores);
    check("rowTotal(1) == 230",           rowTotal(scores, 1) == 230);
    check("rowTotal(9) == 0",             rowTotal(scores, 9) == 0);
    check("columnAverage(0) == 81.6667",  columnAverage(scores, 0) > 81.66 && columnAverage(scores, 0) < 81.67);
    check("bestRow == 2",                 bestRow(scores) == 2);
    check("bestRow(empty) == -1",         bestRow({}) == -1);

    Grid t = transpose(scores);
    check("transpose: t[2][1] == 98",     t.size() == 3 && t[2][1] == 98 && t[0][2] == 95);

    curveExam(scores, 2, 5);
    check("curve: 77->82, 98->100 cap",   scores[0][2] == 82 && scores[1][2] == 100 && scores[2][2] == 93);

    Grid jagged = {{80}, {70, 90}, {}};   // late enrollees took fewer exams
    jagged[2].push_back(100);              // rows grow independently
    check("jagged columnAverage(1) == 90", columnAverage(jagged, 1) == 90.0);
    check("jagged columnAverage(0) == 83.33", columnAverage(jagged, 0) > 83.33 && columnAverage(jagged, 0) < 83.34);
    return 0;
}
