# SET (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14 -pthread")
SET (GCC_COVERAGE_COMPILE_FLAGS
     "-g -O0 -coverage -fprofile-arcs -ftest-coverage")
SET (GCC_COVERAGE_LINK_FLAGS "-coverage -lgcov")

SET (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${GCC_COVERAGE_COMPILE_FLAGS}")
SET (CMAKE_EXE_LINKER_FLAGS
     "${CMAKE_EXE_LINKER_FLAGS} ${GCC_COVERAGE_LINK_FLAGS}")
FIND_PACKAGE (GTest REQUIRED)
INCLUDE_DIRECTORIES (${GTEST_INCLUDE_DIRS})
ADD_EXECUTABLE (device_handler_test unit_test.cpp)
TARGET_LINK_LIBRARIES (device_handler_test device_handler
                       ${GTEST_BOTH_LIBRARIES} --coverage)
ADD_TEST (NAME device_handler_test COMMAND device_handler_test)
SET_TESTS_PROPERTIES (device_handler_test PROPERTIES FIXTURES_REQUIRED
                                                     unit_tests)
SET (PROBE_BENCHMARKDIR ${CMAKE_CURRENT_BINARY_DIR})
