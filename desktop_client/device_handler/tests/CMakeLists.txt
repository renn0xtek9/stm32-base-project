FIND_PACKAGE (GTest REQUIRED)
INCLUDE_DIRECTORIES (${GTEST_INCLUDE_DIRS})
ADD_EXECUTABLE (device_handler_test unit_test.cpp)
TARGET_LINK_LIBRARIES (device_handler_test device_handler
                       ${GTEST_BOTH_LIBRARIES})
ADD_TEST (NAME device_handler_test COMMAND device_handler_test)
SET_TESTS_PROPERTIES (device_handler_test PROPERTIES FIXTURES_REQUIRED
                                                     unit_tests)
