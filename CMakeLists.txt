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
  nav_msgs
  tf2
  tf2_ros
  std_msgs
  # turtlebot3_gazebo
)
include_directories(include)

if(BUILD_TESTING)
find_package(ament_cmake_gtest REQUIRED)
  find_package(ament_lint_auto REQUIRED)
  # the following line skips the linter which checks for copyrights
  # comment the line when a copyright and license is added to all source files
  set(ament_cmake_copyright_FOUND TRUE)
  # the following line skips cpplint (only works in a git repo)
  # comment the line when this package is in a git repo and when
  # a copyright and license is added to all source files
  set(ament_cmake_cpplint_FOUND TRUE)
  # the following lines skip flake8 check
  set(ament_cmake_flake8_FOUND TRUE)
  ament_lint_auto_find_test_dependencies()
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
  DESTINATION share/${PROJECT_NAME}/
)

install(DIRECTORY
  worlds  
  DESTINATION share/${PROJECT_NAME}/
)
ament_package()
