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

# START WITH SECTION 2.8
