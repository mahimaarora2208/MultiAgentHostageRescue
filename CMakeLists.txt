cmake_minimum_required(VERSION 3.8)
project(mahr)

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
find_package(turtlebot3_gazebo REQUIRED)


set(THIS_PACKAGE_INCLUDE_DEPENDS
  geometry_msgs
  rclcpp
  nav_msgs
  tf2
  tf2_ros
  std_msgs
  turtlebot3_gazebo
)
include_directories(include)

if(BUILD_TESTING)
find_package(ament_cmake_gtest REQUIRED)
find_package(ament_lint_auto REQUIRED)

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
add_executable(mahr src/swat.cpp)
ament_target_dependencies(mahr rclcpp std_msgs geometry_msgs nav_msgs tf2 tf2_ros turtlebot3_gazebo)
install(TARGETS
  mahr
  DESTINATION lib/${PROJECT_NAME})
ament_package()
