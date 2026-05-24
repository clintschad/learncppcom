# Learn C++ Tutorial Notes

## Bookmark
Continue with section 0.10

## Chapter 0
### Compiler Setup
* To keep compliant with C++ standards, use the `-pedantic-errors` compiler flag and ensure a newline is at the bottom of every code file. If using VSCode, see instructions for that IDE.
* Can vary the warning level of the compiler by using certain compiler flags like `-Wall` or `Wextra`.
* To use C++ 17 compiler, edited `tasks.json` file
    - Called normal Mac `g++` by setting command to `/usr/bin/g++`
    - Added compiler flag to args: `-std=c++17`
    - Before adding this to VSCode, verified I could run `g++ /usr/bin/g++ -std=c++17 hello.cpp` from terminal successfully.
    - I was able to change the C++ version up to 23 using this method, and it worked fine.
    - So I didn't need to install gcc with homebrew to use C++ 17, even though I'd like to use gcc.

## Chapter 1
### Statements
There are various types of statements in C++:
* Declaration statements
* Jump statements
* Expression statements
* Compound statements
* Selection statements (conditionals)
* Iteration statements (loops)
* Try blocks

### Functions
* Name of a function is called its _identifier_
* Control character: usually not seen, but doesn something, like the escape character.

### Preprocessor Directives
* `#include <iostream>`

### Comments
* Double forward slash `//` for single line comments
* `/*` and `*/` for multi line comments. Also called a "C-style comment."
* Commenting levels:
    - At the library, program, or function level, use comments to describe what.
    - Inside the library, program, or function, use comments to describe how.
    - At the statement level, use comments to describe why.

### Data
* Characters, e.g. 'H'
* Text, e.g. "H" (not necessarily a string?)
* Values placed directly in code (not using variables) are called _literals_.

### Variables and memory
* _runtime_ - when a program is loaded into memory and ran
* _definition_ - e.g. `int x;` or `int x = 3;`
* _allocation_ - a variable is assigned or _allocated_ memory when it is defined.
* `int a, b;` is the same as `int a; int b;`
* `int a, int b;` is incorrect.
* Each variable has an identifier/name, type, and value.
