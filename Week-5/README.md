# Week 5 — More About Classes

**CSCE 306 · Object-Oriented Software Development · Fall 2026**
Professor Faisal Abbas · North Central College
**Dates:** Mon 9/21 & Wed 9/23 · **Readings:** Gaddis Ch. 14

Static members, the `this` pointer, friends, memberwise assignment, copy constructors and the Rule of Three, operator overloading, conversion operators, and aggregation vs. composition. Assignment 2 (class design) is due Wed 9/23.

## Folder layout

```
week05-more-about-classes/
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
| `01_static_members.cpp` | Static member variables and functions (Ch. 14.1) |
| `02_this_pointer_and_chaining.cpp` | The this pointer and method chaining (Ch. 14.5) |
| `03_friend_functions.cpp` | Friend functions and friend classes (Ch. 14.3) |
| `04_memberwise_assignment.cpp` | Memberwise assignment and default copying (Ch. 14.4) |
| `05_copy_constructor_rule_of_three.cpp` | Copy constructor, copy assignment, Rule of Three (Ch. 14.4–14.5) |
| `06_operator_overloading_arithmetic.cpp` | Overloading arithmetic operators -- Money (Ch. 14.5) |
| `07_overloading_comparison_and_stream.cpp` | Overloading ==, <, << and >> (Ch. 14.5) |
| `08_overloading_subscript_increment.cpp` | Overloading [], ++ (prefix/postfix), and () (Ch. 14.5) |
| `09_conversion_operators.cpp` | Object conversion -- converting ctors and conversion operators (Ch. 14.6) |
| `10_aggregation_vs_composition.cpp` | Aggregation vs composition (Ch. 14.7) |

## Lab

| Starter | Solution | Task |
|---------|----------|------|
| `lab1_static_members.cpp` | `lab1_static_members_solution.cpp` | Static members -- Order IDs and a running total |
| `lab2_this_chaining.cpp` | `lab2_this_chaining_solution.cpp` | this and method chaining -- EmailBuilder |
| `lab3_friends.cpp` | `lab3_friends_solution.cpp` | Friend functions -- Thermometer readings |
| `lab4_rule_of_three.cpp` | `lab4_rule_of_three_solution.cpp` | Copy constructor and the Rule of Three -- Playlist |
| `lab5_fraction_operators.cpp` | `lab5_fraction_operators_solution.cpp` | Operator overloading -- Fraction |
| `lab6_aggregation_composition.cpp` | `lab6_aggregation_composition_solution.cpp` | Aggregation vs composition -- Course and Student |

## Verification

All examples, starters, and solutions compile with zero warnings under `g++ -std=c++17 -Wall -Wextra`. Every solution was run and passes all of its checks, and the solutions were also run clean under `-fsanitize=address,undefined`.
