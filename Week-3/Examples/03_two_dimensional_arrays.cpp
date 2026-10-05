// CSCE 306 | Week 3 • Example 03: Two-dimensional arrays (Ch. 7)
// Build: g++ -std=c++17 -Wall -Wextra 03_two_dimensional_arrays.cpp -o grid

#include <iostream>
#include <iomanip>
using namespace std;

constexpr int STUDENTS = 3;
constexpr int EXAMS    = 4;

// For 2-D array parameters, every dimension except the first must be specified.
void printRowAverages(const int grid[][EXAMS], int rows)
{
    for (int r = 0; r < rows; ++r) {
        int sum = 0;
        for (int c = 0; c < EXAMS; ++c) sum += grid[r][c];
        cout << "Student " << r << " average: "
             << fixed << setprecision(1) << static_cast<double>(sum) / EXAMS << '\n';
    }
}

int main()
{
    int scores[STUDENTS][EXAMS] = {
        {90, 85, 77, 93},
        {60, 72, 81, 70},
        {99, 94, 97, 100}
    };

    // Rows then columns
    for (int r = 0; r < STUDENTS; ++r) {
        for (int c = 0; c < EXAMS; ++c) cout << setw(5) << scores[r][c];
        cout << '\n';
    }
    printRowAverages(scores, STUDENTS);
    return 0;
}
