cmake_minimum_required(VERSION 3.16)
project(CodeSnippetForCPP)

set(CMAKE_CXX_STANDARD_REQUIRED on)
set(CMAKE_CTEST_ARGUMENTS ${CMAKE_CTEST_ARGUMENTS} --verbose) # require cmake 3.17
set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake")

include(TestFunctions)

enable_testing()

add_subdirectory(src)
