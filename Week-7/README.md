# Week 7 — Inheritance

**CSCE 306 · Object-Oriented Software Development · Fall 2026**
Professor Faisal Abbas · North Central College
**Dates:** Mon 10/5 (Test 1) & Wed 10/7 · **Readings:** Gaddis Ch. 15.1–15.6

Base and derived classes, the is-a relationship, `protected` access, base-class access specifiers, constructor/destructor order and passing arguments to base constructors, redefining base functions, class hierarchies, and a preview of `virtual` functions. **Test 1 is Monday 10/5**; the inheritance material runs Wednesday 10/7.

## Folder layout

```
week07-inheritance/
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
| `01_is_a_relationship.cpp` | Inheritance and the is-a relationship (Ch. 15.1) |
| `02_protected_members.cpp` | protected members (Ch. 15.2) |
| `03_base_class_access.cpp` | Base class access specifiers -- public/protected/private inheritance (Ch. 15.2) |
| `04_constructor_destructor_order.cpp` | Constructor and destructor order in hierarchies (Ch. 15.3) |
| `05_passing_args_to_base_ctor.cpp` | Passing arguments to base class constructors (Ch. 15.3) |
| `06_redefining_base_functions.cpp` | Redefining base class functions (Ch. 15.4) |
| `07_class_hierarchies.cpp` | Class hierarchies -- multi-level inheritance (Ch. 15.5) |
| `08_polymorphism_preview.cpp` | Polymorphism preview -- virtual, override, slicing (Ch. 15.6) |
| `09_inheriting_constructors.cpp` | Inheriting constructors and final (C++11) |

## Lab

| Starter | Solution | Task |
|---------|----------|------|
| `lab1_account_savings.cpp` | `lab1_account_savings_solution.cpp` | Account -> SavingsAccount |
| `lab2_protected_vs_private.cpp` | `lab2_protected_vs_private_solution.cpp` | protected vs private -- Employee -> Manager |
| `lab3_ctor_dtor_order.cpp` | `lab3_ctor_dtor_order_solution.cpp` | Constructor/destructor order -- Vehicle -> Car |
| `lab4_redefining_functions.cpp` | `lab4_redefining_functions_solution.cpp` | Redefining base functions -- CheckingAccount::withdraw |
| `lab5_shape_hierarchy.cpp` | `lab5_shape_hierarchy_solution.cpp` | Class hierarchy -- Shape -> Rectangle -> Square, Shape -> Circle |
| `lab6_polymorphism_preview.cpp` | `lab6_polymorphism_preview_solution.cpp` | Polymorphism preview -- virtual, override, slicing |

## Verification

All examples, starters, and solutions compile with zero warnings under `g++ -std=c++17 -Wall -Wextra`. Every solution was run and passes all of its checks, and the solutions were also run clean under `-fsanitize=address,undefined`.
