About the development environment:
- Windows 11 Home 64-bit as main OS. Unix and Linux will be target in the future;
- GCC toolchain. Windows port via [MSYS2](https://www.msys2.org/);
- VSC and Code::Blocks IDEs;
- Check all warnings and treat them as errors during development;
- No optimizations during development;
- C++20 standard.

# GCC Command Options
The [GCC documentation](https://gcc.gnu.org/onlinedocs/gcc-13.2.0/gcc/Invoking-GCC.html) says:
> Most of the command-line options that you can use with GCC are useful for C programs; when an option is only useful with another language (usually C++), the explanation says so explicitly. If the description for a particular option does not mention a source language, you can use that option with all supported languages.
> 
> The usual way to run GCC is to run the executable called `gcc` [...]. When you compile C++ programs, you should invoke GCC as `g++` instead.

Based in the [Compiling C++ Programs](https://gcc.gnu.org/onlinedocs/gcc-13.2.0/gcc/Invoking-G_002b_002b.html) section, the differences between `gcc` and `g++` are:
1. `gcc` doesn't link the C++ libraries by default;
2. `g++` treats .c, .h, and .i files as being C++ files, unless explicit told not to using the -x option;
3. `g++` is useful for precompiling C header files to use in C++ compilations.

In the GCC documentation there is a [Option Summary](https://gcc.gnu.org/onlinedocs/gcc-13.2.0/gcc/Option-Summary.html) that groups all the options based on its types.

# Useful links
- [GCC docs](https://gcc.gnu.org/onlinedocs/), mainly [GCC command options](https://gcc.gnu.org/onlinedocs/gcc-13.2.0/gcc/Invoking-GCC.html);
- [Sections 0.5 to 0.12 of Learn C++](https://www.learncpp.com/cpp-tutorial/introduction-to-the-compiler-linker-and-libraries/);
- [Getting Started section of MIT 6.S096](https://ocw.mit.edu/courses/6-s096-effective-programming-in-c-and-c-january-iap-2014/pages/getting-started/).
