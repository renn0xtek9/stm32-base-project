SET (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14 -pthread")
ADD_EXECUTABLE (device_handler_benchmark device_handler_benchmark.cpp)
TARGET_LINK_LIBRARIES (device_handler_benchmark device_handler)
ADD_TEST (
  NAME device_handler_benchmark
  COMMAND $<TARGET_FILE:device_handler_benchmark>
  WORKING_DIRECTORY ${CMAKE_BINARY_DIR})
SET_TESTS_PROPERTIES (device_handler_benchmark PROPERTIES FIXTURES_REQUIRED
                                                          benchmarking)
