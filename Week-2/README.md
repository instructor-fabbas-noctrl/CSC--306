# Week 2 — C++ Overview: Expressions, Decisions, Loops, Functions, File I/O

**CSCE 306 · Object-Oriented Software Development · Fall 2026**
Professor Faisal Abbas · North Central College
**Dates:** Mon 8/31 & Wed 9/2 · **Readings:** Gaddis Ch. 3–6

Operators and precedence, `if`/`switch`, `while`/`do-while`/`for`, functions (value vs reference parameters, overloading, default arguments, scope), and basic file I/O. Assignment 1 is due Wed 9/2.

## Folder layout

```
week02-cpp-overview/
├── README.md
├── Makefile
├── examples/          in-class demo programs (one concept per file)
└── lab/
    ├── starter/       what students start from (contains TODOs)
    └── solution/      completed reference solutions
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

Most lab files end with a small test driver that prints `PASS`/`FAIL` per check. In several starters the driver is commented out (`/* Uncomment when ready ... */`) so the starter compiles cleanly before the class exists — uncomment it once your code is in place.

## Examples

| File | Concept |
|------|---------|
| `01_operators_precedence.cpp` | Operators and precedence (Ch. 3) |
| `02_if_else_chains.cpp` | if / else if / else (Ch. 4) |
| `03_switch_menu.cpp` | switch statement (Ch. 4) |
| `04_while_and_do_while.cpp` | while, do-while, and input validation (Ch. 5) |
| `05_for_loops_and_nesting.cpp` | for loops, nested loops, break/continue (Ch. 5) |
| `06_functions_basics.cpp` | Functions -- prototypes, parameters, return values (Ch. 6) |
| `07_pass_by_value_vs_reference.cpp` | Pass by value vs pass by reference (Ch. 6) |
| `08_overloading_and_defaults.cpp` | Function overloading and default arguments (Ch. 6) |
| `09_scope_and_static_locals.cpp` | Scope, lifetime, and static local variables (Ch. 6) |
| `10_file_io.cpp` | Basic file I/O with ofstream / ifstream (Ch. 5) |

## Lab

| Starter | Solution | Task |
|---------|----------|------|
| `lab1_shipping.cpp` | `lab1_shipping_solution.cpp` | Shipping Calculator -- decisions |
| `lab2_number_stats.cpp` | `lab2_number_stats_solution.cpp` | Number Statistics -- loops |
| `lab3_function_toolkit.cpp` | `lab3_function_toolkit_solution.cpp` | Function Toolkit |
| `lab4_sales_report.cpp` | `lab4_sales_report_solution.cpp` | Sales Report -- file I/O + functions |

Lab 4 reads `lab/data/sales.txt`. Run it from inside `lab/` as `./lab4 data/sales.txt`; it writes `report.txt` to the current folder.

## Verification

All examples, starters, and solutions compile with zero warnings under `g++ -std=c++17 -Wall -Wextra`. Every solution was run and passes all of its checks, and the solutions were also run clean under `-fsanitize=address,undefined`.
