# CMake build script for hepp project.
# Creates 
cmake_minimum_required(VERSION 3.0.0)
project(hepp)


# Build dir
set(BUILD_DIR build)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${BUILD_DIR})

# Compiler flags
set(CMAKE_CXX_FLAGS "--std=c++11 -g -Wall")

# Collect sources
file(GLOB_RECURSE test_sources tests/*.cpp)
file(GLOB_RECURSE lib_sources src/*.cpp)
#file(glob_recurse test_headers tests/*.h)

# add include directories
include_directories(
	vendor/googletest/googletest/include/
	src
	)

message("lib sources : " ${lib_sources})

# googletest
add_subdirectory(
	vendor/googletest
	${BUILD_DIR}
	)

# create test executable
add_executable(
	tests
	${test_sources}
	${lib_sources}
	)

# link googletest
target_link_libraries(
	tests
	gtest
	)




