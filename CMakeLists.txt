cmake_minimum_required(VERSION 3.4)
project(sensors)

# Import external libraries
list(APPEND CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake")

# Enable ExternalProject CMake module
include(ExternalProject)

find_package(Threads REQUIRED)

# Download and install GTest
ExternalProject_Add(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG "release-1.7.0"
  PREFIX ${CMAKE_CURRENT_BINARY_DIR}/gtest
  INSTALL_COMMAND   ""
)

# Create a libgtest target to be used as a dependency by test programs
add_library(libgtest IMPORTED STATIC GLOBAL)
add_dependencies(libgtest googletest)

ExternalProject_Get_Property(googletest source_dir binary_dir)
set_target_properties(libgtest PROPERTIES
    "IMPORTED_LOCATION" "${binary_dir}/libgtest.a"
    "IMPORTED_LINK_INTERFACE_LIBRARIES" "${CMAKE_THREAD_LIBS_INIT}"
#    "INTERFACE_INCLUDE_DIRECTORIES" "${source_dir}/include"
)
# I couldn't make it work with INTERFACE_INCLUDE_DIRECTORIES
include_directories("${source_dir}/include")

# Find eigen
find_package(Eigen REQUIRED)
include_directories(
  ${EIGEN_INCLUDE_DIRS}
)

# Add local includes to path
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

add_library(sensors src/feature.cc)

enable_testing()
add_executable(feature_test src/feature_test.cc)
target_link_libraries(feature_test sensors libgtest)
add_test( feature_test feature_test)
