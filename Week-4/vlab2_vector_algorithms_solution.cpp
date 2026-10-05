// CSCE 306 | Week 4 • Vector Lab 2: <algorithm> with vectors -- Quiz Score Processor (SOLUTION)
// Build: g++ -std=c++17 -Wall -Wextra vlab2_vector_algorithms.cpp -o vlab2
//
// The standard library already has loops for the common jobs. Implement each function using
// the algorithm named in its comment instead of writing the loop yourself:
//   sort, reverse, find, count, count_if, min_element, max_element, accumulate (<numeric>),
//   remove_if + erase (the "erase-remove idiom"), unique.
// Lambdas: count_if(v.begin(), v.end(), [](int x) { return x >= 90; })

#include <algorithm>
#include <iostream>
#include <numeric>
#include <string>
#include <vector>
using namespace std;

// accumulate -- sum of all scores (0 when empty)
int total(const vector<int>& scores)
{
    return accumulate(scores.begin(), scores.end(), 0);
}

// min_element / max_element -- returns highest minus lowest (0 when empty)
int spread(const vector<int>& scores)
{
    if (scores.empty()) return 0;
    return *max_element(scores.begin(), scores.end()) - *min_element(scores.begin(), scores.end());
}

// count_if with a lambda -- how many scores are at least cutoff (capture cutoff: [cutoff])
int countAtLeast(const vector<int>& scores, int cutoff)
{
    return static_cast<int>(count_if(scores.begin(), scores.end(), [cutoff](int s) { return s >= cutoff; }));
}

// find -- index of the first occurrence of target, or -1 (iterator - begin() gives the index)
int indexOf(const vector<int>& scores, int target)
{
    auto it = find(scores.begin(), scores.end(), target);
    return it == scores.end() ? -1 : static_cast<int>(it - scores.begin());
}

// sort -- returns a COPY sorted from highest to lowest; the original is unchanged
//         (pass by value on purpose, or copy a const&; use greater<int>() or a lambda)
vector<int> rankedCopy(vector<int> scores)
{
    sort(scores.begin(), scores.end(), greater<int>());
    return scores;
}

// remove_if + erase -- deletes every score below minimum, in place; returns how many were removed
int dropBelow(vector<int>& scores, int minimum)
{
    size_t before = scores.size();
    scores.erase(remove_if(scores.begin(), scores.end(), [minimum](int s) { return s < minimum; }),
                 scores.end());
    return static_cast<int>(before - scores.size());
}

// sort + unique + erase -- the distinct scores in ascending order
vector<int> distinctSorted(vector<int> scores)
{
    sort(scores.begin(), scores.end());
    scores.erase(unique(scores.begin(), scores.end()), scores.end());
    return scores;
}

// Median: sort a copy; middle element for an odd count, average of the two middle values
// for an even count; 0.0 when empty.
double median(vector<int> scores)
{
    if (scores.empty()) return 0.0;
    sort(scores.begin(), scores.end());
    size_t mid = scores.size() / 2;
    if (scores.size() % 2 == 1) return scores[mid];
    return (scores[mid - 1] + scores[mid]) / 2.0;
}

// ----------------------------- test driver (do not change) -----------------------------
void check(const string& label, bool ok) { cout << (ok ? "PASS  " : "FAIL  ") << label << '\n'; }

int main()
{
    const vector<int> quiz = {88, 72, 95, 60, 88, 100, 45, 72, 91};
    check("total == 711",                   total(quiz) == 711);
    check("total of empty == 0",            total({}) == 0);
    check("spread == 55",                   spread(quiz) == 55);
    check("countAtLeast(90) == 3",          countAtLeast(quiz, 90) == 3);
    check("indexOf(88) == 0 (first)",       indexOf(quiz, 88) == 0);
    check("indexOf(50) == -1",              indexOf(quiz, 50) == -1);

    vector<int> ranked = rankedCopy(quiz);
    check("rankedCopy descending",          ranked.front() == 100 && ranked.back() == 45 && ranked[1] == 95);
    check("original unchanged",             quiz[0] == 88 && quiz.back() == 91);

    check("distinctSorted",                 distinctSorted(quiz) == vector<int>({45, 60, 72, 88, 91, 95, 100}));
    check("median odd == 88",               median(quiz) == 88);
    check("median even == 80",              median({60, 72, 88, 100}) == 80);

    vector<int> work = quiz;
    int removed = dropBelow(work, 70);
    check("dropBelow(70) removed 2",        removed == 2);
    check("dropBelow keeps order, size 7",  work.size() == 7 && work[0] == 88 && work[1] == 72 && work[2] == 95);
    check("no score below 70 remains",      countAtLeast(work, 70) == static_cast<int>(work.size()));
    return 0;
}
