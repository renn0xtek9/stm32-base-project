SET (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14 -pthread")
ADD_EXECUTABLE (device_handler_benchmark device_handler_benchmark.cpp)
TARGET_LINK_LIBRARIES (device_handler_benchmark device_handler)
