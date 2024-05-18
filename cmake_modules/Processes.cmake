IF (${CMAKE_BUILD_TYPE} STREQUAL "Debug")
  ADD_TEST (
    NAME code_coverage
    COMMAND gcovr -r .. --fail-under-line 100 --html --html-details -o
            index.html
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR})
  SET_TESTS_PROPERTIES (code_coverage PROPERTIES FIXTURES_CLEANUP unit_tests)
ENDIF ()

IF (${CMAKE_BUILD_TYPE} STREQUAL "Release")

  # ADD_CUSTOM_TARGET ( benchmark COMMENT "Benchmark target" COMMAND
  # $<TARGET_FILE:device_handler_benchmark> >
  # ${CMAKE_SOURCE_DIR}/benchmark_report.txt)
ENDIF ()

ADD_CUSTOM_TARGET (
  disassemble
  COMMAND /usr/bin/objdump -S $<TARGET_FILE:${DESKTOP_CLIENT_APP_NAME}> >
          ${CMAKE_BINARY_DIR}/${DESKTOP_CLIENT_APP_NAME}.dump
  COMMENT "Disassemble ${DESKTOP_CLIENT_APP_NAME}"
  DEPENDS ${DESKTOP_CLIENT_APP_NAME})

ADD_CUSTOM_TARGET (
  convert_to_assembly
  COMMAND g++ -S
  COMMENT "Convert ${DESKTOP_CLIENT_APP_NAME} to assembly"
  ${CMAKE_SOURCE_DIR}/main.cpp)
