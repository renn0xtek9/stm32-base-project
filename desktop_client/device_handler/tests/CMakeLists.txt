FIND_PACKAGE (GTest REQUIRED)
INCLUDE_DIRECTORIES (${GTEST_INCLUDE_DIRS})
ADD_EXECUTABLE (device_handler_test unit_test.cpp)
TARGET_LINK_LIBRARIES (device_handler_test device_handler
                       ${GTEST_BOTH_LIBRARIES})
ADD_TEST (NAME device_handler_test COMMAND device_handler_test)
SET_TESTS_PROPERTIES (device_handler_test PROPERTIES FIXTURES_REQUIRED
                                                     unit_tests)

ADD_TEST (
  NAME device_handler_test_setup
  WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
  COMMAND test_setup.sh ${CMAKE_CURRENT_BINARY_DIR})
SET_TESTS_PROPERTIES (device_handler_test_setup PROPERTIES FIXTURES_SETUP
                                                           unit_tests)

ADD_TEST (
  NAME device_handler_test_cleanup
  WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
  COMMAND test_cleanup.sh ${CMAKE_CURRENT_BINARY_DIR})
SET_TESTS_PROPERTIES (device_handler_test_cleanup PROPERTIES FIXTURES_CLEANUP
                                                             unit_tests)
