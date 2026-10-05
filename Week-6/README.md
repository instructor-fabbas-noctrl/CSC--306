# Week 6 — Object-Oriented Analysis & Design, UML, Test 1 Review

**CSCE 306 · Object-Oriented Software Development · Fall 2026**
Professor Faisal Abbas · North Central College
**Dates:** Mon 9/28 & Wed 9/30 · **Readings:** Gaddis Appendix E; OOA/OOD handout

Noun/verb analysis and CRC cards, reading and writing UML class diagrams, the relationship types (association, aggregation, composition, dependency) and multiplicity, sequence diagrams to code, reverse translation (code to UML), and a Test 1 review program.

## Folder layout

```
week06-ooad-uml/
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
| `01_noun_verb_analysis.cpp` | From requirements to classes -- noun/verb analysis (OOA) |
| `02_uml_notation_to_cpp.cpp` | Reading a UML class box and writing the C++ (Appendix E) |
| `03_relationships_in_code.cpp` | The four relationships, side by side |
| `04_multiplicity.cpp` | Multiplicity -> C++ member types |
| `05_sequence_diagram_to_code.cpp` | Sequence diagram -> code (interaction modeling) |
| `06_reverse_engineering_code_to_uml.cpp` | Reverse translation -- read C++, draw the UML |
| `07_test1_review_tour.cpp` | Test 1 review -- one program, Weeks 1-6 in one place |

## Lab

| Starter | Solution | Task |
|---------|----------|------|
| `lab1_crc_to_classes.cpp` | `lab1_crc_to_classes_solution.cpp` | CRC cards -> class skeletons |
| `lab2_uml_to_cpp.cpp` | `lab2_uml_to_cpp_solution.cpp` | Implement a UML class diagram exactly |
| `lab3_relationship_notation.cpp` | `lab3_relationship_notation_solution.cpp` | Relationship notation -> code |
| `lab4_sequence_to_code.cpp` | `lab4_sequence_to_code_solution.cpp` | Sequence diagram -> code -- ATM withdrawal |
| `lab5_reverse_translation.cpp` | `lab5_reverse_translation_solution.cpp` | Reverse translation -- code -> UML |
| `lab6_course_synthesis.cpp` | `lab6_course_synthesis_solution.cpp` | Synthesis -- design and build a Course system |

## Verification

All examples, starters, and solutions compile with zero warnings under `g++ -std=c++17 -Wall -Wextra`. Every solution was run and passes all of its checks, and the solutions were also run clean under `-fsanitize=address,undefined`.
