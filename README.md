# A template for C++/CMake projects

## Introduction

A template to quickly get new C++ projects and experiments up and running.
The template includes:

 * `src/main.cpp` a Hello World program that uses [Boost::program_options][program_options] to parse command line
   arguments.
 * `include/header_template.h` that can be copy/pasted for new header files
 * `CMakeLists.txt` to build the project with [CMake][cmake].
 * Integration with [`clang-tidy`][clang-tidy] for linting.
 * `tests/` to build unit tests with [`doctest.h`][doctest] and integrated with cmake/ctest.
 * `docs/` to build API documentation with [Doxygen][doxygen].

## Start a new project

Clone the repository, 

change the name of the project in the top of `CMakeLists.txt`.

Run cmake
```bash
mkdir build
cmake ..
make
```

remove the old git folder and start from a clean slate:
```bash
rm -rf .git
git init
git add -a
```

[program_options]: https://www.boost.org/doc/libs/latest/doc/html/program_options/overview.html
[clang-tidy]: https://clang.llvm.org/extra/clang-tidy/
[doctest]: https://github.com/doctest/doctest
[doxygen]: https://www.doxygen.nl/
[cmake]: https://cmake.org/

## Licence

This is public domain software under [The Unlicensce](LICENCE).
