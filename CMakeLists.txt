project(dynclassldr)
cmake_minimum_required(VERSION 2.8)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")

include(CodeCoverage)
include(Coveralls)

if ((COVERALLS OR COVERAGE) AND CMAKE_BUILD_TYPE STREQUAL "Debug")
  message(STATUS "will generate coverage data")
  set(CMAKE_CXX_FLAGS "-g -O0 -Wall -W -fprofile-arcs -ftest-coverage")
  set(CMAKE_C_FLAGS "-g -O0 -Wall -W -fprofile-arcs -ftest-coverage")
  #SET(CMAKE_SHARED_LINKER_FLAGS="-fprofile-arcs -ftest-coverage")
  set(CMAKE_EXE_LINKER_FLAGS "-fprofile-arcs -ftest-coverage")
  
  if (COVERAGE)
    setup_target_for_coverage(coverage dynclassldr)
  endif()
  
  if (COVERALLS)
    setup_target_for_coveralls(coveralls dynclassldr example)
  endif()

endif()

add_subdirectory(example)

