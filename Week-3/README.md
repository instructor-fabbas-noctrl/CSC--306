# Week 3 — Arrays, Pointers & References, Strings, Structs — Bridge into OOP

**CSCE 306 · Object-Oriented Software Development · Fall 2026**
Professor Faisal Abbas · North Central College
**Dates:** Wed 9/9 (no class Mon 9/7, Labor Day) · **Readings:** Gaddis Ch. 7, 9, 10, 11

Arrays and `std::vector`, pointers and pointer arithmetic, references, dynamic memory, C-strings and `std::string`, and structs — ending with the struct-to-class bridge into Week 4. The five lab parts together make up **Lab 1 (arrays & pointers), due Wed 9/9**.

## Folder layout

```
week03-arrays-pointers-structs/
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
| `01_arrays_basics.cpp` | Arrays -- declaration, initialization, range-for (Ch. 7) |
| `02_arrays_and_functions.cpp` | Passing arrays to functions (Ch. 7) |
| `03_two_dimensional_arrays.cpp` | Two-dimensional arrays (Ch. 7) |
| `04_vector_intro.cpp` | std::vector -- the array you should usually reach for (Ch. 7) |
| `05_pointers_basics.cpp` | Pointer basics -- &, *, nullptr (Ch. 9) |
| `06_pointer_arithmetic.cpp` | Pointers and arrays, pointer arithmetic (Ch. 9) |
| `07_pointers_vs_references.cpp` | Pointers vs references as parameters (Ch. 6, 9) |
| `08_dynamic_memory.cpp` | Dynamic memory -- new / delete / delete[] (Ch. 9) |
| `09_cstrings_and_string.cpp` | Characters, C-strings, and std::string (Ch. 10) |
| `10_structs.cpp` | Structured data -- struct (Ch. 11) |
| `11_array_of_structs.cpp` | Arrays/vectors of structs (Ch. 11) |
| `12_struct_to_class_bridge.cpp` | Bridge into OOP -- from struct to class (preview of Ch. 13) |

## Lab

| Starter | Solution | Task |
|---------|----------|------|
| `lab1_array_stats.cpp` | `lab1_array_stats_solution.cpp` | Array Statistics |
| `lab2_pointer_tools.cpp` | `lab2_pointer_tools_solution.cpp` | Pointer Tools |
| `lab3_dynamic_array.cpp` | `lab3_dynamic_array_solution.cpp` | Growable Dynamic Array |
| `lab4_string_processing.cpp` | `lab4_string_processing_solution.cpp` | String Processing |
| `lab5_gradebook.cpp` | `lab5_gradebook_solution.cpp` | Gradebook with structs |

## Verification

All examples, starters, and solutions compile with zero warnings under `g++ -std=c++17 -Wall -Wextra`. Every solution was run and passes all of its checks, and the solutions were also run clean under `-fsanitize=address,undefined`.
