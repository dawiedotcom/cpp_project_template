cmake_minimum_required(VERSION 3.30)

### Project definition
project(
  cpp_project_template
  VERSION 0.1
  LANGUAGES CXX
)

# Define the main executable name
set(TARGET "main")
# Define header file location
set(INCLUDE_DIR "include/")
# List sources files
set(CXX_SOURCES
  src/main.cpp
)


### Configure compiler options
set(CMAKE_CXX_STANDARD 23)
add_compile_options("-Wunicode" "-Wall" "-Wextra")

### Make the include directory
make_directory("${CMAKE_SOURCE_DIR}/${INCLUDE_DIR}")

### Configure linting
option(ENABLE_LINTING "Enable linting with clang-tidy" ON)

if(CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME AND ENABLE_LINTING)
  set(CMAKE_CXX_CLANG_TIDY 
    clang-tidy;
    -header-filter=${INCLUDE_DIR};
    -checks=clang-diagnostic-*,clang-analyzer-*,*,-altera*,-fuchsia*,-llvmlibc-restrict-system-libc-headers,-llvmlibc-implementation-in-namespace,-llvmlibc-callee-namespace,-modernize-use-trailing-return-type;
  )
endif()


### Find dependancies
# Boost
set(Boost_USE_STATIC_LIBS OFF) 
set(Boost_USE_MULTITHREADED ON)  
set(Boost_USE_STATIC_RUNTIME OFF) 
find_package(Boost 1.87.0 COMPONENTS program_options REQUIRED)

### Configure the main executable
add_executable(${TARGET} ${CXX_SOURCES})
target_include_directories(
  ${TARGET}
  PUBLIC
  ${INCLUDE_DIR}
  ${Boost_INCLUDE_DIRS}
)
target_link_libraries(
  ${TARGET}
  ${Boost_LIBRARIES}
)

### Setup Unit tests
option(ENABLE_TESTING "Enable unit tests in test/" ON)

if(CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME AND ENABLE_TESTING)
  enable_testing()
  add_subdirectory(tests)
endif()

### Setup docs
option(BUILD_DOC "Build documentation" ON)

if(CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME AND BUILD_DOC)
  add_subdirectory(docs)
endif()
