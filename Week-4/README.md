# Week 4 — Introduction to Classes

**CSCE 306 · Object-Oriented Software Development · Fall 2026**
Professor Faisal Abbas · North Central College
**Dates:** Mon 9/14 & Wed 9/16 · **Readings:** Gaddis Ch. 13

Encapsulation, member functions, access specifiers, `const` accessors, constructors and destructors, private helpers, arrays of objects, passing/returning objects, composition, and interface vs. implementation (header + source files).

## Folder layout

```
week04-intro-classes/
├── README.md
├── Makefile
├── examples/          in-class demo programs (one concept per file)
├── lab/               class labs
│   ├── starter/       what students start from (contains TODOs)
│   └── solution/      completed reference solutions
└── lab-vectors/       std::vector labs (standalone vectors -> vectors inside classes)
    ├── starter/
    └── solution/
```

## Building

Every `.cpp` file is a standalone program unless noted. Compile any one of them with:

```bash
g++ -std=c++17 -Wall -Wextra <file>.cpp -o <name>
./<name>
```

Or build everything at once (Linux, macOS, or Windows with MinGW `make`):

```bash
make            # outputs go to build/
make clean
```

The multi-file example builds differently — compile both source files, never the header:

```bash
cd examples/12_separate_files
g++ -std=c++17 -Wall -Wextra main.cpp Rectangle.cpp -o rect
```

Most lab files end with a small test driver that prints `PASS`/`FAIL` per check. In several starters the driver is commented out (`/* Uncomment when ready ... */`) so the starter compiles cleanly before the class exists — uncomment it once your code is in place.

## Examples

| File | Concept |
|------|---------|
| `01_first_class.cpp` | Your first class -- Rectangle (Ch. 13.1–13.3) |
| `02_access_specifiers.cpp` | public vs private, struct vs class (Ch. 13.2) |
| `03_accessors_mutators_const.cpp` | Accessors, mutators, and const member functions (Ch. 13.3) |
| `04_defining_members_outside.cpp` | Defining member functions outside the class (Ch. 13.3–13.4) |
| `05_constructors.cpp` | Constructors (Ch. 13.6–13.8) |
| `06_destructors.cpp` | Destructors and object lifetime (Ch. 13.9) |
| `07_private_member_functions.cpp` | Private member functions (helpers) (Ch. 13.10) |
| `08_arrays_of_objects.cpp` | Arrays and vectors of objects (Ch. 13.12) |
| `09_passing_and_returning_objects.cpp` | Passing objects to and returning objects from functions (Ch. 13) |
| `10_constructor_pitfalls.cpp` | Constructor pitfalls -- default ctor, explicit, init order |
| `11_composition.cpp` | Composition -- objects as members ("has-a") (Ch. 13.15 preview of 14) |
| `12_separate_files/` (`Rectangle.h`, `Rectangle.cpp`, `main.cpp`) | Interface vs. implementation — a class split across header and source files (Ch. 13.5) |

## Lab

| Starter | Solution | Task |
|---------|----------|------|
| `lab1_rectangle_class.cpp` | `lab1_rectangle_class_solution.cpp` | Rectangle class skeleton |
| `lab2_bank_account.cpp` | `lab2_bank_account_solution.cpp` | BankAccount -- constructors and destructor |
| `lab3_private_helper.cpp` | `lab3_private_helper_solution.cpp` | Private helper functions -- Duration |
| `lab4_passing_objects.cpp` | `lab4_passing_objects_solution.cpp` | Passing and returning objects -- Point2D |
| `lab5_student_address.cpp` | `lab5_student_address_solution.cpp` | Composition -- Student has an Address and a Date |

## Vector labs (`lab-vectors/`)

Six labs that move from `std::vector` on its own to vectors as private data members of classes, the pattern used in every class from here on. Each starter **compiles and runs** as given: unfinished functions return placeholder values, so the test driver prints `FAIL` until you implement them. Delete each `(void)...` placeholder line as you write the real code.

| Starter | Solution | Task | Key skills |
|---------|----------|------|------------|
| `vlab1_vector_basics.cpp` | `vlab1_vector_basics_solution.cpp` | Temperature Log | `push_back`, `size`/`empty`, `at` vs `[]`, `front`/`back`, `pop_back`, `insert`, `erase`, range-for by value vs by reference, `const&` parameters |
| `vlab2_vector_algorithms.cpp` | `vlab2_vector_algorithms_solution.cpp` | Quiz Score Processor | `sort`, `find`, `count_if`, `min_element`/`max_element`, `accumulate`, `unique`, erase-remove idiom, lambdas with captures |
| `vlab3_2d_vectors.cpp` | `vlab3_2d_vectors_solution.cpp` | Gradebook Grid | `vector<vector<int>>`, building grids, row/column traversal, jagged rows, transpose, modifying through references |
| `vlab4_vector_of_objects.cpp` | `vlab4_vector_of_objects_solution.cpp` | Playlist | private `vector<Song>` member (composition), enforcing rules in `add`, returning `const Song*`, read-only `const vector<Song>&` accessor, sorting objects with lambdas, `stable_sort` |
| `vlab5_course_roster.cpp` | `vlab5_course_roster_solution.cpp` | Course Roster | vectors inside objects inside a vector, `emplace_back`, const/non-const `find` overloads, returning new vectors of results, pointer invalidation |
| `vlab6_inventory_challenge.cpp` | `vlab6_inventory_challenge_solution.cpp` | Inventory (challenge) | erasing while iterating (`it = v.erase(it)`), `copy_if` + `back_inserter`, `enum class` + `switch` choosing lambdas, encapsulated filtered views |

Suggested pacing: Labs 1–3 in class (~60 min); 4–5 as the bridge into this week's class material; 6 as homework or extra practice.

## Verification

All examples, starters, and solutions (including `lab-vectors/`) compile with zero warnings under `g++ -std=c++17 -Wall -Wextra`. Every solution was run and passes all of its checks, and the solutions were also run clean under `-fsanitize=address,undefined`.
