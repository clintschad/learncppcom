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


