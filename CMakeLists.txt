cmake_minimum_required(VERSION 3.8)
project(MultiAgentHostageRescue)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(geometry_msgs REQUIRED)
find_package(nav_msgs REQUIRED)
find_package(tf2 REQUIRED)
find_package(tf2_ros REQUIRED)
# find_package(turtlebot3_gazebo REQUIRED)


set(THIS_PACKAGE_INCLUDE_DEPENDS
  geometry_msgs
  rclcpp
  rclcpp_action
  nav_msgs
  tf2
  tf2_ros
  std_msgs
)
include_directories(include)

if(BUILD_TESTING)
find_package(ament_cmake_gtest REQUIRED)
find_package(ament_lint_auto REQUIRED)

# # the following lines skip linters
# set(ament_cmake_cppcheck_FOUND TRUE)
# set(ament_cmake_copyright_FOUND TRUE)
# set(ament_cmake_cpplint_FOUND TRUE)
# set(ament_cmake_flake8_FOUND TRUE)
# set(ament_cmake_uncrustify_FOUND TRUE)

# # Run all lint tests in package.xml except those listed above
# ament_lint_auto_find_test_dependencies()

# Add a gtest executable
set(TESTFILES
test/test.cpp)
ament_add_gtest(${PROJECT_NAME}_test ${TESTFILES})
ament_target_dependencies(${PROJECT_NAME}_test ${THIS_PACKAGE_INCLUDE_DEPENDS})

endif()


if (COVERAGE)
    set(CMAKE_BUILD_TYPE "Debug")
    set(CMAKE_CXX_FLAGS "--coverage")
    set(CMAKE_CXX_OUTPUT_EXTENSION_REPLACE "ON")
    # setup_target_for_coverage(code_coverage test/cpp-test coverage)
    # set(COVERAGE_SRCS base.hpp) 
    set(ARG_CONFIG_FILE "${PROJECT_SOURCE_DIR}/uncrustify_google_cpp_allman.cfg"
    CACHE STRING "uncrustify config file")
#     SET(CMAKE_CXX_FLAGS "-g -O0 -fprofile-arcs -ftest-coverage")
#     SET(CMAKE_C_FLAGS "-g -O0 -fprofile-arcs -ftest-coverage")
#     SET(CMAKE_EXE_LINKER_FLAGS "-fprofile-arcs -ftest-coverage")
# else()
#     set(CMAKE_CXX_FLAGS "-Wall -Wextra -Wpedantic -g")
endif()


add_executable(mahr src/swat.cpp)
ament_target_dependencies(mahr rclcpp std_msgs geometry_msgs nav_msgs tf2 tf2_ros)

add_executable(threats src/threats.cpp)
ament_target_dependencies(threats rclcpp std_msgs geometry_msgs nav_msgs tf2 tf2_ros)

install(TARGETS
  mahr
  threats
  DESTINATION lib/${PROJECT_NAME})

# install launch files
install(DIRECTORY
  launch
  worlds
  DESTINATION share/${PROJECT_NAME}/
)

## Install some arbitrary executables
install(PROGRAMS      # want to make the file executable (ie. chmod a+x)
  scripts/generate_coverage_report.bash
  DESTINATION lib/${PROJECT_NAME})

ament_export_dependencies(${THIS_PACKAGE_INCLUDE_DEPENDS})
ament_package()