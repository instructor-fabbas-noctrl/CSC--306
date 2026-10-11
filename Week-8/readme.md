**CSCE 306 OO Software Development · North Central College (noctrl.edu) · Fall 2026**
**Sessions:** Mon Oct 12 and Wed Oct 14, 2026 · **Reading:** Gaddis, *Starting Out with C++*, Ch. 15 (15.7–end)

These labs are done **in class**: clone the repo, open a `*_starter.cpp`, and code along with the instructor. Each lab has a starter (with `TODO` markers) and a solution. Try the starter yourself before you look at the solution.

---

## 1. Learning Objectives

By the end of these labs you can:

- Explain static vs. dynamic binding and predict which function runs.
- Use `virtual`, `override` and `final` correctly.
- Declare an abstract class with pure virtual functions, and know when a derived class is still abstract.
- Explain why a polymorphic base class needs a **virtual destructor**.
- Store mixed objects in `vector<unique_ptr<Base>>` and process them through the base interface.
- Use `dynamic_cast` for type-specific operations, and recognize when it is a design smell.

## 2. Prerequisites

| Need | Details |
|---|---|
| Compiler | g++ / Clang / MSVC with **C++17** support (`g++ --version`; GCC 9+ recommended) |
| Editor | VS Code (set up in Week 1) |
| Git | `git --version`; GitHub account (used with our GitHub Classroom org) |
| Background | Week 7 inheritance: base/derived classes, `protected`, constructor chaining, redefining functions |

## 3. Folder Structure

```
week08-polymorphism/
├── README.md                 <- week overview
├── lab/                      <- YOU ARE HERE
│   ├── README.md
│   ├── lab1_dynamic_binding_starter.cpp / _solution.cpp
│   ├── lab2_abstract_shapes_starter.cpp / _solution.cpp
│   ├── lab3_polymorphic_vector_starter.cpp / _solution.cpp
│   ├── lab4_virtual_destructor_starter.cpp / _solution.cpp
│   ├── lab5_override_final_dynamic_cast_starter.cpp / _solution.cpp
│   └── lab6_payroll_mini_project_starter.cpp / _solution.cpp   (take-home)

```

Every lab is a **single self-contained `.cpp` file** (no shared headers), so each one compiles on its own.

## 4. Getting the Code

```bash
# first time
git clone <course-repo-url>
cd <course-repo>/week08-polymorphism/lab

# every later class
git pull
```

Work in your own copy: copy a starter to a new name (e.g. `cp lab1_dynamic_binding_starter.cpp my_lab1.cpp`) or work on a branch, so `git pull` never conflicts with your edits.

## 5. Build and Run

**Standard command** (always use these warning flags):

```bash
g++ -std=c++17 -Wall -Wextra lab1_dynamic_binding_starter.cpp -o lab1
./lab1            # Windows: lab1.exe
```

Compile and run every starter in a loop (Linux/macOS/Git Bash):

```bash
for f in lab*_starter.cpp; do g++ -std=c++17 -Wall -Wextra "$f" -o "${f%.cpp}" && echo "built $f"; done
```

Starters are written to **compile as-is** (with the `TODO` parts missing or wrong), so you can run them first and watch the behavior change as you complete each step.

## 6. Lab Schedule

| # | File prefix | Topic | Day | Time | Core? |
|---|---|---|---|---|---|
| 1 | `lab1_dynamic_binding` | Static vs. dynamic binding, `virtual` | Mon | ~15 min | Core |
| 5 | `lab5_override_final_dynamic_cast` | `override`, `final`, `dynamic_cast`, `typeid` | Mon (start) / Wed | ~10 min | Core |
| 4 | `lab4_virtual_destructor` | Virtual destructors, memory leak | Wed | ~10 min | Core |
| 2 | `lab2_abstract_shapes` | Abstract base class, pure virtual | Wed | ~15 min | Core |
| 3 | `lab3_polymorphic_vector` | `vector<unique_ptr<Base>>` payroll | Wed | ~15 min | Core |
| 6 | `lab6_payroll_mini_project` | Sink/Logger plug-in system | Take-home | 30–45 min | Stretch |

(Numbering follows the topic order in the lecture notes; the labs are run in the order shown in the Day column.)

---

## Lab 1 — Static vs. Dynamic Binding

**File:** `lab1_dynamic_binding_starter.cpp` · **Concepts:** `virtual`, base pointer/reference, virtual destructor, `override` · **Slides:** 6–13

**Goal:** see why a base-class pointer calls the base version unless the function is `virtual`.

**Steps**

1. Predict the output of the starter, then run it. Note that line 2 (base pointer) prints the *Account* version.
2. Make `Account::describe()` `virtual`.
3. Add `virtual ~Account() = default;`.
4. In `SavingsAccount`, redefine `describe()` and mark it `override` (show owner, balance and rate).
5. Create a `SavingsAccount` with `new`, keep it in an `Account*`, call `describe()`, then `delete` it.

**Expected output (solution)**

```
1) Direct objects:
  Account[Ada] $100.000000
  Savings[Grace] $2500.000000 @ 3.000000%
2) Base pointer -> derived object:
  Savings[Grace] $2500.000000 @ 3.000000%
3) Base reference parameter:
  show(): Account[Ada] $100.000000
  show(): Savings[Grace] $2500.000000 @ 3.000000%
4) Heap object via base pointer:
  Savings[Linus] $40.000000 @ 1.000000%
```

**Think about it:** Which output line changes when you add `virtual`? Why does line 1 (direct objects) behave the same either way?

---

## Lab 5 — `override`, `final`, `dynamic_cast`

**File:** `lab5_override_final_dynamic_cast_starter.cpp` · **Concepts:** `override` safety, `final` classes, `dynamic_cast`, `typeid` · **Slides:** 14–15, 42

**Goal:** let the compiler check your overrides, and test the real type at run time.

**Steps**

1. Add `override` to `Bike::wheels()`. Then misspell it (`wheel`) and read the compiler error. Fix it.
2. Try `class Monster : public Truck {};` — read the error caused by `final`, then delete the line.
3. In the loop, use `dynamic_cast<const Car*>(p.get())` and call `honk()` only if the cast succeeds. Do the same for `Truck::load(5)`.
4. Discuss: is `dynamic_cast` a sign of good design? When would a virtual function be better?

**Expected output (solution)** — `typeid` names are compiler-specific (shown here for GCC/Clang):

```
Car has 4 wheels, dynamic type: 3Car
  Beep beep!
Truck has 6 wheels, dynamic type: 5Truck
  Loaded 5 tons
Vehicle has 2 wheels, dynamic type: 4Bike
```

> `Bike` does not override `kind()`, so it reports `Vehicle` — that is the inherited default.

---

## Lab 4 — Virtual Destructors

**File:** `lab4_virtual_destructor_starter.cpp` · **Concepts:** destruction through a base pointer, memory leaks · **Slides:** 27–30

**Goal:** see what goes wrong when you `delete` through a base pointer and the destructor is not virtual.

**Steps**

1. Run the starter as-is. Note which destructor messages print.
2. Make `~Resource()` `virtual` and run again. Compare the output.
3. (Optional) Detect the leak with AddressSanitizer: `g++ -std=c++17 -g -fsanitize=address lab4_virtual_destructor_starter.cpp -o lab4_asan && ./lab4_asan`
4. Create a `Buffer` on the stack (no pointer). Does `virtual` matter here? Why or why not?

**Expected output — starter (non-virtual destructor):** `Buffer freed` is **missing** (the derived destructor never runs → leak):

```
Deleting Buffer through Resource*:
  Resource acquired
  Buffer allocated 1000 ints
  Resource released
Done.
```

**Expected output — solution (virtual destructor):**

```
Deleting Buffer through Resource*:
  Resource acquired
  Buffer allocated 1000 ints
  Buffer freed
  Resource released
Done.
```

**Rule to remember:** any class with virtual functions gets a **virtual destructor**.

---

## Lab 2 — Abstract Classes and Pure Virtual Functions

**File:** `lab2_abstract_shapes_starter.cpp` · **Concepts:** `= 0`, abstract base class, concrete derived classes · **Slides:** 31–36

**Goal:** build a `Shape` hierarchy where `Shape` cannot be instantiated.

**Steps**

1. In `Shape`, declare pure virtual `area()` and `perimeter()` (both `const`, returning `double`).
2. Override both in `Circle` (use `M_PI` from `<cmath>`).
3. Override both in `Rectangle`.
4. Fix `Square` (derives from `Rectangle`): pass the side as **both** width and height. Why does it need no new overrides?
5. Uncomment `Shape s("x");` in `main`, read the error, and comment it out again.

> The starter's `Square` has an intentional bug (it passes `1` as the height) — fix it in step 4.
> If `M_PI` is undefined on your compiler (MSVC), add `#define _USE_MATH_DEFINES` before `#include <cmath>`.

**Expected output (solution)**

```
Circle: area=7.06858 perimeter=9.42478
Rectangle: area=12 perimeter=14
Square: area=6.25 perimeter=10
Total area = 25.3186
```

---

## Lab 3 — A Polymorphic Collection

**File:** `lab3_polymorphic_vector_starter.cpp` · **Concepts:** `vector<unique_ptr<Base>>`, `make_unique`, multi-level overriding · **Slides:** 37–41

**Goal:** process Salaried, Hourly and Manager employees uniformly through the `Employee` base class.

**Steps**

1. `Hourly::pay()` — time-and-a-half for hours over 40.
2. `Manager::pay()` — `Salaried::pay() + bonus`; `title()` returns `"Manager"`.
3. Fill the `vector<unique_ptr<Employee>>` with one Salaried (Ana, 52000), one Hourly (Ben, $20/h, 45 h) and one Manager (Cleo, 78000, bonus 500).
4. Loop with `const auto& e`, print title, name and pay, and accumulate the total.
5. Think: why is there no `delete`? What would break without the virtual destructor?

**Expected output (solution)**

```
Salaried Ana    $1000.00
Hourly   Ben    $950.00
Manager  Cleo   $2000.00
Weekly payroll: $3950.00
```

(Ben: 40 × 20 + 5 × 20 × 1.5 = 950. Cleo: 78000 / 52 + 500 = 2000.)

---

## Lab 6 (Take-home / Stretch) — Sink & Logger

**File:** `lab6_payroll_mini_project_starter.cpp` · **Concepts:** interface (all-pure-virtual class), decorator-style wrapper, open–closed principle · **Slides:** 37, 44

> The filename says "payroll" for historical reasons; the project is a **logging plug-in system**.

**Goal:** a `Logger` that writes to any number of `Sink` objects without knowing their concrete types.

**Steps**

1. `BufferSink`: override `write()` to append `msg + '\n'` and count messages; `name()` returns `"buffer"`.
2. `UpperSink`: upper-case every character, forward to the wrapped sink; `name()` returns `"upper->" + next.name()`.
3. Run `main` and verify the output.
4. **Stretch:** add a `CountingSink` or a `FilterSink` (forwards only messages containing a keyword) **without changing `Logger`**.

**Expected output (solution)**

```
  [console] polymorphism is flexible
  [console] POLYMORPHISM IS FLEXIBLE
  [console] add a sink without touching Logger
  [console] ADD A SINK WITHOUT TOUCHING LOGGER
Buffer holds 2 messages:
polymorphism is flexible
add a sink without touching Logger
```

---

## 7. Quick Reference

```cpp
class Base {
public:
    virtual ~Base() = default;               // always, for polymorphic bases
    virtual void f() const;                  // overridable
    virtual double g() const = 0;            // pure virtual -> Base is abstract
};
class Derived final : public Base {          // 'final': no further derivation
public:
    void f() const override;                 // always write override
    double g() const override;
};

vector<unique_ptr<Base>> v;                  // heterogeneous container
v.push_back(make_unique<Derived>());
for (const auto& p : v) p->f();              // dynamic dispatch

if (auto d = dynamic_cast<const Derived*>(p.get())) { /* Derived-only code */ }
```

| Common mistake | Fix |
|---|---|
| Base pointer calls base version | Make the function `virtual` in the base |
| Derived destructor never runs | `virtual ~Base()` |
| `error: cannot declare variable of abstract type` | Instantiate a concrete derived class instead |
| `marked 'override' but does not override` | Check name, parameters, `const`, return type match the base |
| Objects "lose" derived data | Slicing: pass by `const Base&`/pointer, never by value |
| `vector<Shape>` won't compile / slices | Use `vector<unique_ptr<Shape>>` |

## 8. Troubleshooting

- **`M_PI` undeclared** — see the Lab 2 note, or define your own `const double PI = 3.14159265358979;`.
- **`typeid(...).name()` looks odd** (`3Car`) — that is normal for GCC/Clang. MSVC prints `class Car`.
- **`make_unique` not found** — you need `-std=c++14` or newer (use `-std=c++17`) and `#include <memory>`.
- **Linker error: undefined reference to vtable** — a virtual function was declared but never defined (and is not `= 0`).
- **Windows** — run `g++` from MSYS2/MinGW or WSL; run the program as `lab1.exe`.

## 9. Submission

Labs are **not graded** — they prepare you for **Assignment 3 Part 2** (due Wed Oct 21; spec in `../assignments/`). Also remember: **Team Project Phase 2** (design + class skeletons) is due **Wed Oct 14**.

Keep the starters you complete in your own repo/branch for later review before Test 2.

## 10. Next Week

Week 9 (Oct 19 & 21): using class libraries and an introduction to the C++ Standard Library and containers — Gaddis 16.1–16.3.
