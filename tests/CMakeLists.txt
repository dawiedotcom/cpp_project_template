### Define unit test variables
set(TEST_TARGET "unit_tests")
set(TEST_INCLUDE "../${INCLUDE}")
set(TEST_CXX_SOURCES
  # Foundational
  main.cpp
  # Unit tests
  # Code under test
)

### Setup doctest

find_package(Git REQUIRED)

include(FetchContent)
FetchContent_Declare(
  doctest
  URL  https://raw.githubusercontent.com/doctest/doctest/v2.4.11/doctest/doctest.h
  DOWNLOAD_NO_EXTRACT TRUE
)

FetchContent_MakeAvailable(doctest)

if (NOT doctest_SOURCE_DIR STREQUAL "")
    message(STATUS "Fetched doctest")
endif()

set(DOCTEST_INCLUDE_DIR ${doctest_SOURCE_DIR} CACHE INTERNAL "Path to include folder for doctest")

### Configure the unit test program
add_executable(
  ${TEST_TARGET}
  ${TEST_CXX_SOURCES}
)
target_include_directories(
  ${TEST_TARGET}
  PUBLIC
  ${TEST_INCLUDE}
  ${DOCTEST_INCLUDE_DIR}
)
target_link_libraries(
  ${TEST_TARGET}
)

### Add the test program to the cmake list of tests
add_test(NAME unit_tests COMMAND ${TEST_TARGET})
