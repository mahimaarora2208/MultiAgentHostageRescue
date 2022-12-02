cmake_minimum_required(VERSION 3.8)
project(MultiAgentHostageRescue)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
# uncomment the following section in order to fill in
# further dependencies manually.
# find_package(<dependency> REQUIRED)

if(BUILD_TESTING)
find_package(ament_cmake_gtest REQUIRED)
find_package(ament_lint_auto REQUIRED)

# the following lines skip linters
set(ament_cmake_cppcheck_FOUND TRUE)
set(ament_cmake_copyright_FOUND TRUE)
set(ament_cmake_cpplint_FOUND TRUE)
set(ament_cmake_flake8_FOUND TRUE)
set(ament_cmake_uncrustify_FOUND TRUE)
ament_lint_auto_find_test_dependencies()

# Run all lint tests in package.xml except those listed above
ament_lint_auto_find_test_dependencies()

# Add a gtest executable
set(TESTFILES
  test/test.cpp)
ament_add_gtest(${PROJECT_NAME}_test ${TESTFILES})
ament_target_dependencies(${PROJECT_NAME}_test ${THIS_PACKAGE_INCLUDE_DEPENDS})
endif()

if (COVERAGE)
    include(CodeCoverage)
    set(LCOV_REMOVE_EXTRA "'*vendor/*'")
    setup_target_for_coverage(code_coverage test/cpp-test coverage)
    set(COVERAGE_SRCS base.hpp) 

    SET(CMAKE_CXX_FLAGS "-g -O0 -fprofile-arcs -ftest-coverage")
    SET(CMAKE_C_FLAGS "-g -O0 -fprofile-arcs -ftest-coverage")
    SET(CMAKE_EXE_LINKER_FLAGS "-fprofile-arcs -ftest-coverage")
else()
    set(CMAKE_CXX_FLAGS "-Wall -Wextra -Wpedantic -g")
endif()

ament_package()
