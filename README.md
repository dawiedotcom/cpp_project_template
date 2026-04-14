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
```bash
git clone https://github.com/dawiedotcom/cpp_project_template.cpp <my_new_project>
cd <my_new_project>
```
Change the name of the project in the top of `CMakeLists.txt`.
Remove the old `.git` folder and start from a clean slate:
```bash
rm -rf .git
git init
```

Run cmake:
```bash
mkdir build
cmake ..
make
```

[program_options]: https://www.boost.org/doc/libs/latest/doc/html/program_options/overview.html
[clang-tidy]: https://clang.llvm.org/extra/clang-tidy/
[doctest]: https://github.com/doctest/doctest
[doxygen]: https://www.doxygen.nl/
[cmake]: https://cmake.org/

## Unit tests

Unit tests are done with [doctest.h][doctest].
Run the unit tests with: 
```bash
make
ctest
```

Add a new unit test by creating a `.cpp` file like the following in `tests/`
```c++
#include "doctest.h"

TEST_CASE("An example test case") {
  CHECK(1==1);
}
```

Update the `CXX_TEST_SOURCES` in `tests/CMakeLists.txt`:
```cmake
set(TEST_CXX_SOURCES
  # Foundational
  main.cpp
  # Unit tests
  <new_unit_test>.cpp
  # Code under test
  <code_under_test>.cpp
)
```

## Documentation

A `doxygen.conf` file is generated in `docs/` when running CMake.
The `INPUT` variable is updated so that Doxygen will compile everything in the 
`docs/`, `include/` and `src/` directories and use `README.md` as the documentation's
main page.

The docs can be built by running `make docs` and viewed in a browser with 
```bash
python -m http.server ../docs/html
```

## Licence

This is public domain software under [The Unlicensce](LICENCE).
