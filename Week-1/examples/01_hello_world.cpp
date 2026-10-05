// CSCE 306 — Object-Oriented Software Development | Fall 2026
// Professor Faisal Abbas • North Central College
// Week 1 • Example 01: Anatomy of a C++ program
// Build: g++ -std=c++17 -Wall -Wextra 01_hello_world.cpp -o hello

#include <iostream>   // preprocessor directive: pulls in std::cout / std::cin

// Every C++ program starts executing at main().
// The int return value is reported to the operating system (0 = success).
int main()
{
    std::cout << "Hello, CSCE 306!" << std::endl;   // endl = newline + flush
    std::cout << "Welcome to Object-Oriented Software Development.\n";  // '\n' = newline only
    return 0;
}
