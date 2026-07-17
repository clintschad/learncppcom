# Learn C++ Tutorial Notes

## Bookmark
Continue with section 0.10

## Chapter 0
### Build process
* Compile - build a single source file into an object file. Does not invoke linker or generate executable.
* Build - compile all source files into object files and link them to generate executable
* Clean - remove cached object files and executable
* Rebuild - Clean and Build

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

### I/O Library
* _cout_ stands for _character output_
* `std::endl` is inefficient in that it flushes the buffer. When possible, use `\n`.
* It is possible to read multiple values with one `cin` statement:

```
std::cin >> x >> y; // get two numbers and store in variable x and y respectively
std::cout << "You entered " << x << " and " << y << '\n';
```

* `cin` uses an _input buffer_. Values entered are stored in here. For example, if the program is reading in input from the keyboard, and `5a 3` is entered in, the input buffer will contain `5a 3\n`. The `\n` is the enter from the keyboard. As the program parses through the input buffer, whitespace such as spaces, tabs, and newlines are discarded. If the input buffer is `5a 3\n` and the program is reading in input for two integers, such as `cin >> x >> y;`, `5` will be assigned to `x` and `5` removed from the input buffer. Now the input buffer is `a 3\n`. Next in the buffer is `a`, but since this cannot be assigned to integer `y`, `y` is instead assigned `0`. The input buffer remains at `a 3\n`.
* If `cin` is being used to assign an integer variable, and a number larger than it can hold is entered, the variable will be assigned the max value it can hold. Here, for a 32 bit integer, `2147483647` is the largest positive value is can hold.
* For an input buffer assigning a value to an integer, the `+` sign is valid. For example, if the input buffer is `+5` and it is to assign an integer variable the value, the variable will be assigned the value `5`. This is similar to how the negative sign `-` is also valid for integers.

### Variable Initialization
Three types of initialization:
* Initialized = The object is given a known value at the point of definition.
* Assignment = The object is given a known value beyond the point of definition.
* Uninitialized = The object has not been given a known value yet.

Misc
* Always initialize variables unless there's a specific reason not to.
* Undefined Behavior (UB). In the uninitialization example, this has undefined behavior because the language doesn't have clear rules on how this is handled and thus the behavior is actually undefined.
* Implementation-defined behavior - where the C++ language standard gives freedom to how something should be implemented and the compiler does this. Size of the integer type (2 vs 4 bytes) is an example.
* Avoid both UB and implementation-defined behavior.

### C++ Keywords
* Aka _reserved words_
* 92 keywords as of C++23
* C++ also has special identifiers: override, final, import, and module. They have a specific meaning in certain contexts, but are not reserved otherwise.
* _identifier_ is the name of a function, type, or other kind of item.

#### Identifier naming conventions
* Variable and function names begin with a lower letter
* User-defined types like structs, classes, enums begin with capital letter.
* For multiword identifiers/names, use _snake_case_ or _camelCase_.
* Avoid startning a name with an underscore. Though allowed, this is reserved for OS, library, and/or compiler use.
* Other variable naming guides:
    - An identifier that exists for only a few statements (e.g. in the body of a short function) can have a shorter name.
    - An identifier that is accessible from anywhere might benefit from a longer name.
    - An identifier that represents a non-specific number (e.g. anything the user provides) can have a shorter name.
    - An identifier that represents a specific value (e.g. the length of an inseam in millimeters) should have a longer name.

### Formatting
* Preprocessor directives must go on separate lines.
* C++ is a whitespace-independent language. It does not force restrictions on formatting.
* Consider keeping line lengths to 80 chars or less.

### Literals
* Values that are defined and can be assigned to variables are _literals_. `5` and `hello` are literals. Note they are not the variables themselves and they are constant. In other words, they are values inserted directly inot the source code.

### Operations, operators, and operands
* _Operation_ - process involving input values called _operands_ to produce an output value. The operation is defined by the symbol called the _operator_. In `3 + 2`, `3` and `2` are _operands_ and `+` is the _operator_. The output of an operation is called a _return value_.
* The following are also _operators_: `=`, `<<`, `>>`, `==`, `new`, `delete`, `throw`.
* _Arity_ - number of operands an operator can take as input.
    - _Unary_ - one operand, e.g. negative sign `-` like `-1`.
    - _Binary_ - two operands. For example, in `3 + 4`, the `+` operator is acting on two operands. Other examples are `<<` and `>>` that use `std:cout` or `std:cin` on one side and a string on the other.
    - _Ternary_ - three operands. The only one in C++ is the ternary conditional operator.
    - _Nullary_ - zero operands. The only one in C++ is the `throw` operator.
* Side effect - an effect from an operation that's not the direct output result, e.g. void functions.

### Expressions
* _Expression_ - Non-empty sequence of literals, variables, operators, and function calls that produce a single output value.
* _Evaluation_ is executing an _expression_.
* The _result_ of an _evaluation_ is sometimes called the _return value_.
* Expressions can't standalone and end in a semi-colon. Rather, they can be used in statements. These are called _expression statements_. For example, `int x{2+3};` is an expression statement and `2+3` is an expression.
* _Subexpression_ - expression used as an operand. For example, in `x = 4 + 5`, `x` and `4 + 5` are subexpressions.
* _Full expressions_ - expression that is not a subexpression. `x = 4 + 5` is a full expression.
* _Compound expression_ - expression that contains two or more operators. `x = 4 + 5` is a compound expression due to the `=` and `+` operators.

## Chapter 2
### Functions
* _DRY_ - Acronym for _Don't Repeat Yourself_
* _Function_ - a __reusable__ sequence of statements.
* _User-defined functions_ - functions in application, not defined by library.
* Structure of a function
```
returnType functionName() // This is the function header (tells the compiler about the existence of the function)
{
    // This is the function body (tells the compiler what the function does)
}
```
* Even if function has no input parameters, must include the empty parentheses when it is called, e.g. `doPrint();` not `doPrint;`.
* A function cannot be defined inside another function.
* _Function header_ - initial line of function, containing return type, name, and parameters. Does not end in semicolon (this is the prototype).
* _Return by value_ - return a copied value back to the caller
* Functions with a return type must return a value, otherwise this may result in undefined behavior.
* The only exception is main, which will implicitly return 0 if no return is defined.
* Functions can only return a single value, though there are workarounds to return more data.
* Functions can return status codes to indicate proper/improper operation, calculated values, or nothing. It is good practice to comment what the return is above the function header.
* Best practice is to give a function only one task. For example, rather than a function calculate a value from inputs and print the result, break this into two functions: one to calculate the value and another to print the value.
* _Forward declaration_ - a statement definition for a function's return type, name, and inputs, to allow the function to be used before the body is defined. The body is defined later. Same as _function prototype_.
* Declaration vs definition - declaration tells the compiler the existence of an identifier. Definition implements (for functions and types) or instantiates (for variables).
* You technically don't need the parameter names in the function declaration, just the parameter types. However, it is best practice to include the parameter names for readability and understanding.
* In C++, it is possible to have multiple functions of the same name, as long as the input parameter type list is different (different order or different number). This is [_function overloading_](https://en.wikipedia.org/wiki/Function_overloading).

#### Main
* Must return an `int`
* Program cannot call `main()`
* Main not necessarily the first function to execute. Global variables are initialized before main and can be initialized by a function, so these functions can execute before main.
* Usually returns 0 if program ran normally.
* C++ standard defines status codes `0`, `EXIT_SUCCESS`, and `EXIT_FAILURE`. `0`, `EXIT_SUCCESS` mean the program executed successfully, while `EXIT_FAILURE` means it didn't. These can be used to maximize portability.

#### Function Parameters
* _Argument_ - the actual value instances the caller uses when calling the function.
* _Pass by value_ - value of each arg is copied into the matching parameter.
* A unused function parameter can be softly removed by keeping the parameter type but removing the name, e.g. `void doSomething(int /*count*/)`. Note here the name is present but commented out; this is good practice. This keeps the function call the same, but tells the compiler the parameter is unused in the function. This is sometimes done if the function is changed, but you don't want or can't update all the function calls.

#### Scope and Local Variables
* Local variables are variables defined in a function body.
* Function parameters are also considered local variables.
* _Scope_ - where in the source code the identifier (func/variable) can be seen and used.
* _Local scope_ - also called _block scope_, means the identifier is defined within a set of braces and thus can only be seen between these braces.
* It's best practice to __define local variables as close to their first use__ as reasonable. The old way was to define them at the top of the function. However, it's more difficult to see when a variable is used this way.

### Programs With Multiple Files
* C++ is designed so each source is compiled independently, and thus order of file compilation doesn't matter.
* If identifiers conflict within the same file (e.g. two functions of the same name have different function bodies) a compiler issue will occur. If the functio bodies are within different files, a linker error will occur.

#### Scope and Namespace
* Can have same identifiers (function and variable names) if they're in different namespaces.
* Global scope is also called global namespace
    - okay to have functions in this namespace
    - discouraged to use variables (global variables) in this namespace
* `std` is a non-global namespace.
* In `std::cout`, `::` is called the _scope resolution_ operator. The identifier to the left of `::` identifies the namespace the identifier on the right is a part of. Another way of reading `std::cout` is the `cout` declared in the namespace `std`. Also in this example, `std::` is called the namespace prefix. `cout` is called the _qualified name_.
* The `using` directive allows use of identifiers within a namespace without having to use the namespace prefix. However, this is discouraged and using the namespace prefix is preferred.

### Preprocessor
* After the preprocessor has processed a code file, the result is called a _translation unit_.
* Each translation unit include a single .cpp file and all header files it includes (including recursively included include files since header files can include other header files.)
* _Preprocessor directives_ can also be just called _directives_.
* Macro preprocessor directives should be all uppercase with words separated by underscores.
* Avoid using "object-like macros with substitution text" (e.g. `#define MY_NAME "Clint"`).
* Conditional compilation directives like `#ifdef`, `#ifndef`, `#endif` are okay to use.
* Can use `#if 0` to funtionally comment out code and `#if 1` to re-enable it.
* Try to use #define identifiers outside of functions.
* Remember that directives in one file aren't used in another. For files to use a directive, they should include the same file that contains the directive to be shared.

### Header Files
* While .h is the preferred file extension for C++ header files, .hpp or no extension can be used.
* Header files usually contain related forward declarations.
* Header files are usually paired with the corresponding code file.
* For now, don't put function and variable definitions in header files. This causes the definitions to be defined everywhere the header is included, which will work for compilation but results in definitions in multiple places rather than one place.
* Later, will use inline function, inline variables, types, and templates in header files.
* The corresponding source file (.cpp) should include its paired header file, so errors are caught at compile time and not later at the linking stage.
* When including header files, angled brackets indicate system files located in the include directories as defined by the OS or compiler. Quotes indicate files we've written and indicate the current (or project?) folders.
* `#include` standard library header files without .h extension and user-defined header files with .h extension.
* Do not use relative paths when including header files. If path changes, path needs to be updated or compile won't work. Use IDE (or build system like CMake) build setting. So if folder structure of project ever changes, only a setting in IDE needs adjusting instead of all code files.
* Transitive / recursive header file - try to explicitly include the header files necessary for compilation rather than relying on the include from another header file. If the header file down the chain doesn't include the header file you need, you'll need to explicitly include it anyway.
* Order of including header files:
    - the paired header file for the .cpp file (e.g. include add.h in add.cpp)
    - headers from the same project (e.g. `#include "mymath.h"`)
    - 3rd party library headers (e.g. `#include <boost/tuple/tuple.hpp>`)
    - Standard library headers (.e.g. `#include <iostream>`)
* Best practices:
    - Always include header guards (we’ll cover these next lesson).
    - Do not define variables and functions in header files (for now).
    - Give a header file the same name as the source file it’s associated with (e.g. grades.h is paired with grades.cpp).
    - Each header file should have a specific job, and be as independent as possible. For example, you might put all your declarations related to functionality A in A.h and all your declarations related to functionality B in B.h. That way if you only care about A later, you can just include A.h and not get any of the stuff related to B.
    - Be mindful of which headers you need to explicitly include for the functionality that you are using in your code files, to avoid inadvertent transitive includes.
    - A header file should #include any other headers containing functionality it needs. Such a header should compile successfully when #included into a .cpp file by itself.
    - Only #include what you need (don’t include everything just because you can).
    - Do not #include .cpp files.
    - Prefer putting documentation on what something does or how to use it in the header. It’s more likely to be seen there. Documentation describing how something works should remain in the source files.

#### Header Guards
```
#ifndef SOME_UNIQUE_NAME
#define SOME_UNIQUE_NAME

// Declarations of certain definitions here

#endif
```
* How it works:
    - If `SOME_UNIQUE_NAME` exists, the compiler skips down to `#endif`, not including the file.
    - If `SOME_UNIQUE_NAME` doesn't exist, the compiler defines the name and includes the contents of the file.
* This is to prevent header files from being included multiple times by a cpp, which can result in identifier/naming conflicts. Note that this is per .cpp file. Once a .cpp file is done being compiled, the process is restarted for the next .cpp file.
* Another option to header guards is `#pragma once`.

### Designing the program
* When creating the outline (architecting) the program, functions that are not yet implemented can either be commented out or use empty function bodies (called _stubbing out_).

## Chapter 3 - Debugging
### Debug Print Statements
* [dbg-macro](https://github.com/sharkdp/dbg-macro/tree/master) - header only file that makes it easier to print out debug code and will not compile for release.
* Use `std:cerr` when printing debug code. This prints the buffer immediately, while `std::cout` may not.
* Don't indent debug print code to make it easier to see and revert when done debugging.
* Can enclose debug print statements with preprocessor directives so they can be enabled/disabled, e.g.
```
#ifdef ENABLE_DEBUG
std::cerr << "getUserInput() called\n";
#endif
```
* Using the example above, `#define ENABLE_DEBUG` could be placed in a header file that could be included in any/all source files. Then commenting/uncommenting that line in that header file would enable/disable all debug print statements throughout all the source files using this method.

### Debug Logger
* Places print statements with timestamps and line numbers in a log file.
* Can use C++ `std::clog`, but it is recommended to use a third party logging tool, such as [plog](https://github.com/SergiusTheBest/plog).
* Easy to enable/disable plog.
* Can use [spdlog](https://github.com/SergiusTheBest/plog) for larger or performance-sensitive projects.

### Debugger
* Step out - executes all remaining code in the function and returns to the caller.
* Step back - not many debuggers have this feature.
* Set next statement - also called _jump to cursor_ in VSCode. This is different from _run to cursor_ in that it skips running the code from the current line to the target line.
    - _set next statement_ can be useful in jumping over code you would normally comment out.
    - It can also be used to jump back to re-execute and watch certain code run again. Be aware that unlike a _step back_ where the program's state is rewound (variables revert back to their previous state before execution), this does not occur in _set next statement_ or _jump to cursor_, so results may become incorrect. __Use judicously__.
* Can inspect variables in a _variable_ window and also by hovering cursor over the variable. Can also use a _watch window_ of preselected variables to monitor these variables.
* Can break on variable in watch window changing.
* Can run small expressions (like x + 2) in the watch window
* Can highlight expressions in code and add to watch window which will evaluate and show the result
* _Call stack window_ - all active functions that have been called to get to the current point of execution.
    - contains each line of code that will be returned to when the function returns.
    - is useful to know which functions were called to get to the current place of execution.

### Catching issues early before they get worse
* This is making structural changes to the code without affecting its behavior.
* Functions that take up more than a vertical screen's worth of lines should be broken up to multiple shorter functions.
* Can use `assert` and `static assert` which will be discussed in more detail in section 9.6.
* Static analysis tools - analyze code without executing it.
    - compiler
    - linter
    - [Wikipedia list of C++ static analysis tools](https://en.wikipedia.org/wiki/List_of_tools_for_static_code_analysis#C,_C++)
    - some free ones are
        - [clang-tidy](https://clang.llvm.org/extra/clang-tidy/)
        - [cpplint](https://github.com/cpplint/cpplint)
        - [cppcheck](https://cppcheck.sourceforge.io/) (integrated into Code::Blocks)
        - [SonarLint](https://www.sonarsource.com/open-source-editions/)
*  Static analysis tools are highly recommended for larger complex programs. 

## Chapter 4 - Data Types
* Primitive types - default data types of the language. Also called _fundamental data types_ or _basic types_. Some examples are below:
    - wchar_t
    - chart_t, char16_t, char32_t
    - std::nullptr
* The `_t` suffix usually designates _type_, though this isn't always applied, such as the fundamental types, e.g. `int`.
* While permitted, avoid using void in function parameter list:
```
int getValue(void) // C way. Avoid in C++.
{
    // do stuff
}
int getValue()     // C++ way. Preferred.
{
    // do stuff
}
```
* Can use `static_assert` to check the minimum size of a data type, e.g. that `int` is at least 4 bytes. Compile will fail if not true.
* Can also use the `sizeof` operator on a data type directly, e.g. `sizeof(int)`, to check data type size on machine. However, `sizeof` does not work on `void` or dynamically allocated memory used by an object.
* `sizeof` also works on variables.
* Use `short` instead of `short int` and `long` instead of `long int`. Use shorthand types that don't use the `int` suffix or `signed` prefix.
* Range of signed data type is $-2^{n-1}$ to $2^{n-1}-1$.
* Range of unsigned data type is $0$ to $2^{n}-1$.
* Behavior is undefined if assigning a variable a value that is out of range, e.g. 258 to a uint8. This case specifically is called _overflow_.
* For integer division, the fractional part is dropped, e.g. 8/5 = 1.
* The result of unsigned integer overflow is the value % sizeof(data_type), e.g. 257 = 257 % 256 = 1. This can be thought of wrapping around from the greatest bound to the smallest bound.
* Wrap around can also occur the other way. For example, `uint8 x{-1};` results in x having the value -1.

### Issues using signed and unsigned values together
* When an unsigned and signed variable are in a operation (arithmetic or comparison), the signed variable is converted to unsigned and the result is unsigned.

### C++ Fixed width integers
* Since C++ only guarantees the minimum number of bytes a data type is (e.g. `int` is at least 2 bytes but could be 4), there are _fixed width_ integers that are part of the standard library that guarantee the number of bytes. Example: `std::int32_t` is always 4 bytes. Need to `#include <cstdint>`.
    - However and unfortunately, C++ treats `std:int8_t` and `std::uint8_t` like chars.
    - Not all architectures support these fixed-width integers.
* On some systems, sometimes smaller width types are slower to process (e.g. 16 bit) than a wider type (e.g. 32 bit). For this, C++ has _fast_ and _least_ data types, such as `std::int_least32_t` and `std::int_fast32_t`.
    - `std::int_least32_t` means it's guaranteed to be at least 32 bit, but might not be the fastest implementation
    - `std::int_fast32_t` means it's guaranteed to be the fastest data type that has at least 32 bits. For example, if the system can process 64 bit values faster, this might actually be a 64 bit value.
    - The downside to this is possibly more memory usage.
* In general, avoid _fast_ and _least_ integral types.
* The return type of the `sizeof` function is `std::size_t`. On most systems, this is the memory-address width, so 32 on 32 bit systems and 64 on 64 bit systems.

### Scientific notation
* For large numbers, scientific notation can be used. For example, the mass of Earth is $5.9722 \cdot 10^{24}$ kg. In code, this would be `5.9722e24` kg. Similarly, the mass of an electron is $9.1093837 \cdot 10^{-31}$ kg, and in code this is `9.1093837e-31` kg.
* The more digits in the significand, the more precise the value, e.g. `3.14159e0` is more precise than `3.14e0`. The first has 6 significant figures, while the latter has 3.

### Floating point numbers
* `float`, `double`, and `long double`.
* Avoid using `long double` since the number of bytes can vary between platforms.
* For nearly all processors, `float` uses the 4-byte IEEE 754 single-precision format, and `double` uses the 8-byte IEEE 754 double-precision format.
* `long double`, however, does [not follow a single standard convention](https://en.wikipedia.org/wiki/Long_double). For example, `long double` can use [x87 extended-precision](https://en.wikipedia.org/wiki/X87) (80 bit) or [IEEE 754 quadruple-precision](https://en.wikipedia.org/wiki/Quadruple-precision_floating-point_format#IEEE_754_quadruple-precision_binary_floating-point_format:_binary128) (128 bit).
* When using floating point literals, always include at least one decimal place, even if the decimal is 0 to inform the compiler that the number if floating point and not an integer.

```
int a { 5 };      // 5 means integer
double b { 5.0 }; // 5.0 is a floating point literal (no suffix means double type by default)
float c { 5.0f }; // 5.0 is a floating point literal, f suffix means float type

int d { 0 };      // 0 is an integer
double e { 0.0 }; // 0.0 is a double
```

* Floating point literals usually default to type `double`. Use the `f` suffix to denote type `float`. For example, `0.0` is type `double`, but `0.0f` is type `float`.

* Print floating values with `cout`:
    - By default, prints floating point literals as integers, e.g. `5.0` will print out as `5`. To print the decimal places, use the `f` suffix, e.g. `5.0f` will print out as `5.0`.
    - By default, prints with a precision of 6, i.e. shows 6 significant figures, e.g. `9.87654321f` when printed out is `9.87654`. Can use _output manipulators_ from `<iomanip>` such as `std::setprecision()` or `std::setw` to force `cout` to print the number of desired significant figures.
    - Use `double` when possible to avoid rounding errors with `float`.

* Rounding errors will occur when doing math operations with float and doubles since certain values can't be stored exactly and have a rounding error to begin with (e.g. 0.1 in binary). Need to be careful with doing comparisons as well.

* IEEE 754 has additional values: Inf, NaN, and signed 0 (+0.0 and -0.0).

### Boolean values
* `bool` by default initializes to false, e.g. `bool myFlag{};` will initialize `myFlag` to `false`.
* Boolean values print out as `0` or `1` instead of `true` or `false`.
    - Can use `std::boolalpha` to print boolean values as `true` or `false`.
* Can use `0` or `1` to initialized boolean variables, but should prefer to use `true` and `false`. Using a value greater than `1` may cause compiler errors.
* Assigning values greater than `1` to a boolean varaible is equivalent to assigning `true` though this is discouraged.
* Be careful assigning boolean variables using `std::cin`. For example, if user input is `3` and is assigned to a boolean, the boolean will be assigned `true` but `std::cin` will enter _failure mode_ (see section 9.5). If non-numeric values are entered, these will be interpreted as `false` and `std::cin` will enter _failure mode_ as well.
    - Can use `std:boolalpha` to enter `true` or `false` for `std:cin`. Can turn this off using `std:noboolalpha`.

### If statements
* While early returns in functions were historically frowned upon, this is more accepted in modern programming if this makes the function simpler. Discussed more in section 8.11.

### Chars
* While chars can be initialized with integer literals, e.g. `char myChar{97};` this should be avoided.
* When using `std::cin` to assign a value to a char, it will extract only one char from the input buffer. For example, if the user inputs `abcd` into the input buffer, the next call to `std::cin >> myChar` will extract `a` from  `abcd`, with `myChar` equal to `a` and the input buffer equal to `bcd`. If `std::cin >> myChar2` is called after this, the process would repeat, with `b` assigned to `myChar2` and the input buffer equal to `cd`.
    - Leading white space is skipped and not extracted. For example, if the input buffer is `a b` and there are 2 successive `std::cin << ` calls assigning values to `char` variables, the first call will extract and assign `a` and the next call will skip the space, extract, and assign `b` the the second char variable.
    - To also extract whitespace, use `std::cin.get()`
* If more than one character needs to be read at a time, use a `string` type of variable.
* There are various _escape sequence_ characters that assist in printing values, such as `\n` for a new line.
* While allowed, avoid the following
    - double quotes around single characters, e.g. `"\n"` `"\t"`
    - multicharacter literals, e.g. `'56'`
        - Easy to make this mistake. For example `std::cout << "The value of x is " << x << '!\n';` Here, `'!\n'` contains two literal characters, `!` and `\n` and this will cause the output to print out the incorrect numeric value. Can use double quotes here to fix the issue.

### Type conversion and static_cast
* An _okay_ implicit type conversion example: `print(5);` when the function prototype is `void print(double x);`. The integer literal `5` is implicitly converted to the float `5.0`. 
* An unsafe implicit type conversion example: `print(5.5);` when the function prototype is `void print(int x);`. The float literal `5.5` is implicitly converted to the integer `5`, dropping the fractional part. Compilers will usually warn about possible loss of data.
* To perform an _explicit type conversion_ or _type cast_, use the `static_cast` operator. An example of this expression is `static_cast<int>(x)`
* Angled brackets `< >` in C++ indicate something needs a parameterizable type.
* Most compilers treat `int8_t` and `uint8_t` as `char` and will `cout` them as ASCII characters. Use `static_cast` to force the compiler to treat and print as integer.
* Using `cin` for these types can also be problem. For example, if the input buffer is `35` and `cin` is used to assign value to an `int8_t` or `uint8_t` variable, it will only extract the `3` and assign this to the variable. `3` in ASCII is numerically `51`, so the variable will equal `51` instead of the expected `35`.

## Chapter 5 - Constants and Strings
### Constant variables
* Declaring const variables
```
const double gravity { 9.8 };  // preferred use of const before type
int const sidesInSquare { 4 }; // "east const" style, okay but not preferred
```
* Variable type includes `const` qualifier, so `const double gravity` is of type `const double`.
* `const` variables must be initialized.
* `const` can be used as a function parameter to guarantee that the function doesn't change that variable being passed in as a parameter. However, this is not preferred in modern C++ since the value is copied in anyway. When passing in parameters by reference or address, however, `const` may be used.
* When returning objects by value, don't use `const`, e.g. don't use `const` in the return type of a function.
* When possible, make variables `const`. This reduces bugs, allows compiler to optimize the program, and helps in debugging.
* Prefer `const` over using preprocessor macros since macros don't follow scope rules and can't be seen in debugger.
* `const` and `volatile` are the only _type qualifiers_ in C++.

### Section 5.2 - Literals
* A `literal` is an actual value, e.g. `5`, `true`, `3.4`, `"Hello, world!"`, etc
* The literal `5` is interpreted as type `int`. If necessary to be interpreted as another type, can use a suffix like `f`, e.g `5f` will be interpreted as type `float` instead of `double`.
* Most suffixes are not case sensitive, though there are exceptions like `s` (string) and `sv` (string view).
* C-style string literals are const objects that are created at the start of the program and exist for the entirety of the program. However, `std::string` and `std::string_view` are temporary objects that can be created and destroyed while the program is running.

### Section 5.3 - Numeral systems (binary and hexadecimal)
* Use prefix `0b` for binary literals (C++14 and newer). Can also use `'` as binary separator to make reading easier.
* Use `std::hex` in conjunction with `std::cout` to print hex values.
* The `std::bitset` type for binary variables can be used to print binary values using `std::cout`. However, with C++20, `std::format` can be used; with C++23, `std:println` can be used. 

### Section 5.4 - The as-if rule and compile-time optimization
* Profiler - can be used to see how long parts of program take to run.
* Compile time evaluation (optimization here):
    - _constant folding_: replacing constant operands with the single equivalent constant operand
    - _constant propagation_: replace variables that are always constant with the constant value
    - _dead code eliminatin_: code that is executed but has no effect on the rest of the program
* Use `const` to help the optimizer to determine when to use constant propagation.
* Certain expressions must be able to be evaluated at compile time
    - `constexpr` initilization
    - non-type template argument
    - length of `std::array` or C-style array
* Fundamental _compile-time_ programming C++ features:
    - `constexpr` variables and functions
    - templates
    - static_assert
* Examples of _constant expressions_ that can be evaluated at compile-time:
    - literals (e.g. `5`, `1.2`)
    - operators with constant expression operands (e.g. `3+4`, `2*sizeof(int)`)
    - const integer variables with a constant expression initializer (e.g. `const int x{5}`)
    - constexpr variables
    - constexpr function calls with constant expression arguments
    - non-type template parameters (section 11.9)
    - enumerators (section 13.2)
    - type traits
    - constexpr lambda expressions (section 20.6)
* Examples of expressions that _cannot_ be used in constant expressions:
    - non-const variables
    - const non-integer variables, e.g. `const double d{1.2}`. Instead, define as a `constexpr` variable.
    - return values of non-constexpr functions (even if value inside function is const)
    - function parameters
    - operators with operands that are not constant expressions (e.g. anything using `std::cout` since `std::cout` is not a constant expression)
    - operators `new`, `delete`, `throw`, `typeid`, and `,` (comma operator)
* Compiler is only _required_ to evaluate constant expressions at compile-time in contexts that _require_ a constant expression.
* `constexpr` - like `const` but unlike `const`, can use it for decimal values, e.g. `constexpr double gravity{9.8};`. Not usually, but possible to use with function return values. See lesson _F.1 -- Constexpr functions_.
* `const` vs `constexpr`
    - once initialized, cannot be changed (applies to both types)
    - `const` can be initialized at compile-time or run-time
    - `constexpr` _must_ be initialized at compile-time
* `constexpr` functions evaluate at compile-time. This type of function can initialize `constexpr` and `const` objects. `constexpr` cannot be initialized by a non-`constexpr` type function, whereas `const` can since it can be initilized at run-time.
* Prefer using `constexpr` and `constexpr` functions over macros, with the exception of header guards, build configurations, etc.
* Avoid using `const` in pass-by-value function parameters and for function return values.

### Section 5.7: Introduction to std::string
* While C-style strings can be used in C++, `std::string` and `std::stringview` are preferred because they're safer and easier to work with.
* `std::string` can vary in size which makes it easier to work with (can dynamically assign strings of different lengths) but also makes its usage slower.
* When using `std::cin` with `std::string`, `cin` extracts characters up to the first white space. Use `std::getline()` to get multiple words separated by white space.
* Use `std::ws` to ignore leading white space in the in put buffer. This is useful if `std::cin` is reading '`n'` from a previous keyboard entry where the input buffer now begins with `\n`. Note that `std::ws` is not preserved across calls, so this needs to be called everywhere it's needed.
* The `>>` operator ignores leading whitespace but `std::getline` does not. Thus if `>>` is used before a `std::getline`, `std::ws` must be used with `std::getline` to force it to ignore the leading whitespace.
* Use the string object's _member function_ `length` to get the length of a `std::string` object. Note that the null character is not included. Note that `std::string::length()` returns an unsigned value, but `std::ssize()` returns signed. Use `static_cast<int>` with `std::string::length()` to cast its return value to `int` if needed.
* Initializing a `std::string` is expensive (HOW?)
* Do not pass `std::string` by value, since it makes a copy. Use `std::string_view` instead.
* A function should only return a `std::string` by value for a few reasons (since this makes an expensive copy); otherwise prefer `std::string_view` instead.
* Use the `s` suffix and `std::string_literals` namespace for `std::string` literals; otherwise C-style string literals are made.
```
    using namespace std::string_literals; // easy access to the s suffix

    std::cout << "foo\n";   // no suffix is a C-style string literal
    std::cout << "goo\n"s;  // s suffix is a std::string literal
```
* `constexpr` doesn't usually support `std::string`, especially in earlier C++ versions. Use `std::string_view` instead.

### Section 5.8 - std::string_view
* Initializing and copying strings are expensive, probably since they're ultimately char arrays. Passing a string by value to a function creates a copy of the string (or char array), which is expensive. If possible for any "read only" use of a string, use `std::string_view` since this prevents expensive string copying.
* C-style and `string` will implicitly convert to `string_view` if function parameter is `string_view`. For example, for a function with a `string_view` parameter, if the function is called with a C-style string as the parameter, it will implicitly convert to `string_view`.
* However, `string_view` will not implicitly convert to `string`. Can `static_cast` or initialize a `string` with a `string_view`.
* To create `string_view` literals, append the `sv` suffix:
```
std::cout << "foo\n";   // no suffix is a C-style string literal
std::cout << "goo\n"s;  // s suffix is a std::string literal
std::cout << "moo\n"sv; // sv suffix is a std::string_view literal
```
* It's not necessary to initialize `string_view` objects with `string_view` literals, though this is fine. Initializing `string_view` objects with C-style strings is fine. Since C-style strings exist for the entirety of the program, you typically don't have to worry about the object that `string_view` is "looking at" being destroyed and thus resulting in undefined behavior.
* Can use `constexpr` with `string_view` to create a true constant compile-time string.

### Section 5.9 - std::string_view part 2
* Be aware that the original object that `string_view` was initialized to can be changed and `string_view` won't be automatically updated. This invalidates the `string_view` object and _will_ result in undefined and unexpected behavior. This is why `string_view` is sometimes called a _dangling_ view.
* If the `string` that `string_view` was initialized to has changed, `string_view` can be revalidated by setting it to the string object again.
* Generally avoid using `string_view` as return type except if
    - function returns a C-style string, since C-style strings exist for the entirety of the program.
    - function is returning a `string_view` parameter that's being passed in.
* Can modify the view of a `string_view` object. Note that the `string` that `string_view` is viewing is not modified, just `string_view`.
    - `remove_prefix()` and `remove_suffix()` removes characters from the left side and from the right side respectively.
    - To undo these affects on the `string_view` object, it will need to reassign it to the original `string` object.
    - This is useful if just a substring of a string is needed.
    - Because a `string_view` can view a substring of a null-terminated `string`, a `string_view` may not be null terminated.
    - If for some reason a `string_view` that's not null-terminated needs to be null-terminated, convert it to a `string`.
* Many useful reference notes at the end of this section on when to use `string` vs `string_view`.

## Chapter 6 - Operators
### Section 6.1 - Operator Precedence and Associativity
* If multiple operators are of the same level and near each other, they are grouped left to right, e.g. `7-4-1 ` becomes `(7-4)-1`.
* See predecence/associativity chart in this section for reference when necessary.
* Order of evaluating function arguments depends on the compiler. For example for `myFunc(x, y, z)`, Clang will evaluate `x`, `y`, and `z`. However, GCC will evaluate `z`, `x`, and `y`. This isn't an issue in this example, but suppose x, y, and z were function calls; then this could be an issue. In this case, explicitly assign the function calls (x, y, and z) before the larger `myFunc` function call, and place `x, y`, and z` in `myFunc`. See another example below.
```
printCalculation(getValue(), getValue(), getValue()); // this line is ambiguous

int a{ getValue() }; // will execute first
    int b{ getValue() }; // will execute second
    int c{ getValue() }; // will execute third

    printCalculation(a, b, c); // this line is now unambiguous
```
* The result of dividing two integers results in itself an integer with no fractional part, e.g. `7/4 = 1`.
* To get a fractional division result, cast one or both operands as a floating type (`double` or `float`).

### Section 6.4 - Increment and Decrement Operators 
* prefix, e.g. `++x` or `--x`, are pretty straightforward: the `++` or `--` is evaluated.
* postfix, e.g. `x++` or `x--`, can be trickier. The original copy of x is evaluated (e.g. if used in a function or initialization, the original value is used). Then, after that line, x has the updated value.
* Prefix has better performance than postfix. Since prefix is simpler and more efficient, it is preferred to use prefix when possible.
* Avoid statements where the variable is used and its modified form, e.g. ` x+ ++x`. Exceptions are `x += y`.

### Section 6.5 - The Comma Operator
* Has the lowest precedence of all operators.
* Allows evaluation of multiple expressions where a single expression is allowed. The example below prints out `3`.
```
int x{ 1 };
int y{ 2 };

std::cout << (++x, ++y) << '\n'; // increment x and y, evaluates to the right operand
```
* However, due to how tricky and easy it is to make mistakes with this operator, it is preferred only to use the comma operator with `for` loops.

### Section 6.6 - The Ternary/Conditional Operator
* Can use the ternary operator to initialize constant expressions if the operands are constant.
* Be careful with the operator order precedence of the ternary operator and operator near it, as this could cause the code to not work as you expect. Wrap the ternary expression with parentheses if in doubt.
* The second and third operands of the ternary operator must match in type if it's not a fundamental type (okay to mix signed and unsigned values?). The compiler may try to do this for you, but it may have unexpected results.
* Can throw exceptions with the second or third operand of the ternary operator.
* If the first operand is a `constexpr`, use `if constexpr` instead of `(x ? y : z)`. `if constexpr` covered in section 8.4.
* Avoid the ternary operator in complicated expressions.

### Section 6.7 - Relational operators and floating point comparisons
* Since floating point operations have some residual error, avoid using `==` and `!=` for comparing floating point variables that have undergone some mathematical process.
* It is generally not safe to compare different types of float, e.g. `float` vs `double`.
* This section has a decent algorithm for compariing floating type value as "close enough" using relative and absolute epsilons.

### Section 6.8 - Logical Operators
* Short circuit evaluation (when only the left operand in a conditional expression is evaluated) may cause the right operand to not be evaluated.
    - Note that short circuit evaluation always occurs left to right and is an exception to the rule that operands may operate in any order.
    - Only the built-in versions of the logical operators perform short-circuit evaluation. If these operators are overloaded to work with your own type, your overloaded operator will not perform short-circuit evaluation.
* Be aware that logical operator AND has higher precedence than OR.
    - Due to this, to avoid confusion, use explicit parentheses around AND expressions next to ORs to be more clear.
* No logical exclusive or (XOR) in C++. Can use `!=` instead.
* There are alternative keyword names for certain logical operators, such as those listed below. HOWEVER, use of these is discouraged.
    - `and` for `&&`
    - `or` for `||`
    - `not` for `!`

## Optional Chapter - Bit Manipulation
### Section O.1 - Bit flags adn bit manipulation via std::bitset
* `std::bitset` is fast for bit manipulation at the cost of memory. The size of a `std::bitset` is usually 32 bits on 32 bit machines or 64 bits on 64 bit machines.
* Below are some useful member functions of std::bitset
    - size() - number of bits
    - count() - number of bits set
    - all() - boolean for all bits set
    - any() - boolean if any bits set
    - none() - boolean for no bits set

### Section O.2 - Bitwise operators
* Use unsigned integer types or `std::bitset` type when doing bit manipulation. Do not perform bit manipulation on signed integer types.
* Below is an example of operator loading of the bitshift `<<` operator:
```
std::cout << x << 1 << '\n'; // print value of x (0110), then 1
std::cout << (x << 1) << '\n'; // print x left shifted by 1 (1100)
```
* Type promotion (increasing from a smaller type to a large type, e.g. from uint8 to uint16). If operands of a bitwise operator (`>>`, `<<`, `&`, `|`, `^`) are `unsigned short`, the operands will be promoted to `int` or `unsigned int`, including the result.
* Be careful if using `std::bitset<x>` on `std::bitset<y>` when x and y are different sizes. Why would you even want to do this?

### Section O.3 - Bit manipulation with bitwise operators and bit masks
* Check if bit on/off using AND with appropriate bitmask.
* Set bit on/off using OR with appropriate bitmask.
* To clear a bit (set to 0), use AND and NOT together.
* Flip/toggle a bit using XOR with appropriate bitmask.
* To set, clear, or flip multiple bits, OR bitmasks together.
* Instead of passing a long list of boolean parameters into a function, can use a single variable, where each bit is one of the boolean parameters. Can then use OR'd bitmasks to pass in only the boolean valuables we want.
* Use `std::hex` to read in a input stream value as a hex value.

## Chapter 7 - Scope, Duration, and Linkage
### Section 7.2 - User-defined namespaces and the scope resolution operator
* Newer and preferred naming convention for namespaces is to start with a capital letter.
* `::` is the _scope resolution_ operator.
* If the scope resolution operator `::` is used with nothing in front of it, the global namespace is used. This is commonly used inside a namespace to refer to the global namespace outside.
* If an identifier (e.g. variable or function) is used without the scope resolution operator inside a namespace and no matching name is found, the compiler will search the containing (up one level) namespace. The compiler will keep going up each level until it finally searches the highest level, the global namespace.
* Remember that function declarations and definitions for a given namespace must be declared and defined in both. For example, if the function declaration is in a header file and the function definition is in a source file, then both files need to have the namespace encapsulate the declaration. In this case, the namespace would be in both header and source files.
    - This shows you can encapsulate variables and functions from different files in the same namespace as long as the same namespace name is used.
* Nested namespaces
    - Can have a namespace inside another namespace
    ```
    namespace Foo
    {
        namespace Goo // Goo is a namespace inside the Foo namespace
        {
            int add(int x, int y)
            {
                return x + y;
            }
        }
    }
    ```
     `Foo::Bar` is then used to access the `Bar` namespace.
    - Using C++17 and newer, nested namespaces can be declared this way:
    ```
    namespace Foo::Bar // Bar is a namespace inside the Foo namespace (C++17 style)
    {
        int add(int x, int y)
        {
            return x + y;
        }
    }
    ```
    This is equivalent to the example above.
    - To add declarations only to the `Foo` namespace, use the `Foo` namespace namespace only:
    ```
    namespace Foo::Goo // Goo is a namespace inside the Foo namespace (C++17 style)
    {
        int add(int x, int y)
        {
            return x + y;
        }
    }

    namespace Foo
    {
        void someFcn() {} // This function is in Foo only
    }
    ```
* Namespace aliases - useful for replacing a long nested namespace reference
```
namespace Active = Foo::Goo; // Active now refers to Foo::Goo
```
* Another use for namespace aliases is to change which namespace it is pointing to. For example, our namespace alias `Active` can be updated to point to `Bee::Gee` namespace. Using `Active` now refers to `Bee::Gee` instead of `Foo::Goo`.
* Use at least a top level namespace if distributing code.
* Below are some examples of how to organize namespaces if working with others
    - Project or library :: module (e.g. `Foologger::Lang`)
    - Project or library :: module (e.g. `Foologger::Lang`)Company or org :: project or library (e.g. `Foosoft::Foologger`)
    - Project or library :: module (e.g. `Foologger::Lang`)Company or org :: project or library :: module (e.g. `Foosoft::Foologger::Lang`)
* Use namespaces for reusable code like math and physics equations.
* My note: use namespaces for libraries. For example, at the top of the main code, you can use an alias (or `using namespace ___`) to select which versions of functions you want to use, and then the main code below doesn't need to change. For example, if I need to use a sensor, but the sensor option may change at runtime, I can set the namespace to the appropriate sensor, but I can keep the sensor function calls the same in the main code below.
* Avoid deeply nested namespaces (more than 3 levels).

### 7.3 — Local variables
* Limit the scope of variables as much as possible. If a variable is only needed in a nested block, declare it in that block so it can't be used outside the block.

### 7.4 - Introduction to global variables
* Variables defined outside a function are global variables.
* Global variables have _global scope_ or _file scope_ where they can be used up until the end of the file they were declared in.
    - My note: this is what my work would label and call a _module_ variable, i.e. its scope is the module or the file it's in.
* It's best practice to define global variables inside a namespace (even if the namespace is global) than directly to the global namespace.
* Variables declared in a namespace are global variables.
* Global variables are _static_ variables.
    - These variables have _static duration_: they're created before `main()` starts and destroyed when `main()` ends.

Continue with 7.4: Naming global variables


