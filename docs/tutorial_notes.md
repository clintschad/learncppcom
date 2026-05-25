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

### Variable Assignment
* `=` is the assignment operator
* `==` is the comparison operator

### Variable Initialization
There are a few ways to initialize variables in C++:

```
int a;         // default-initialization (no initializer)

// Traditional initialization forms:
int b = 5;     // copy-initialization (initial value after equals sign)
int c ( 6 );   // direct-initialization (initial value in parenthesis)

// Modern initialization forms (preferred):
int d { 7 };   // direct-list-initialization (initial value in braces)
int e {};      // value-initialization (empty braces)
```

* For default-initialization, such as `int a;`, a will have an indeterminate value, e.g. a garbage value.

* List-initialization is the preferred modern method of initialization: `int a {3};`. The advantage with this method is that it can be also used to initialize objects with a list of values.

* List-initialization prevents _narrowing conversions_. For example,

```
int w1 { 4.5 }; // compile error: list-init does not allow narrowing conversion
int w2 = 4.5;   // compiles: w2 copy-initialized to value 4
int w3 (4.5);   // compiles: w3 direct-initialized to value 4
```

* Default-initialization can be used to initialize the value to zero: `int a {}`. Here a = 0. For class types, this method can be used to initialize the object to predefined default values.

* Use direct-list-initialization with explicit value 0 `int a{0}` when immediately using 0 afterward. Use `int a{}` when `a` will be assigned another value later.

* _Instantiation_ means the variable has been create/allocated and initialized. Often used with objects.

* Avoid initializing variables on the same line. If needed, rememember that each variable needs it own initializer, e.g.

```
int a = 5, b = 6;          // copy-initialization
int c ( 7 ), d ( 8 );      // direct-initialization
int e { 9 }, f { 10 };     // direct-list-initialization
int i {}, j {};            // value-initialization
```
```
int a, b = 5;              // wrong: a is not initialized to 5!
int a = 5, b = 5;          // correct: a and b are initialized to 5
```

* Use [[maybe_unused]] to tell compiler variable might not be used so compiler doesn't generate warnings or errors.

