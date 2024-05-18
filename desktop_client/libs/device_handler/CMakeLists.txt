CREATE_LIBRARY (SRCS src/device_handler.cpp PUBLIC_HEADERS
                include/${LIBNAME}/device_handler.h)

ADD_SUBDIRECTORY (tests)

IF (${CMAKE_BUILD_TYPE} STREQUAL "Release")
  ADD_SUBDIRECTORY (benchmark)
ENDIF ()

# IF (${CMAKE_BUILD_TYPE} STREQUAL "Debug")

ADD_CUSTOM_COMMAND (
  COMMAND pwd
  COMMAND valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes
          --verbose --log-file=valgrind-${LIBNAME}-out.txt ./device_handler_test
  WORKING_DIRECTORY $<TARGET_FILE_DIR:device_handler_test>
  OUTPUT valgrind-${LIBNAME}-out.txt
  COMMENT "Analying ${LIBNAME}-tesst with valgrind")

# valgrind-${LIBNAME}-analysis
ADD_CUSTOM_TARGET (
  valgrind-${LIBNAME}
  DEPENDS valgrind-${LIBNAME}-out.txt
  COMMAND echo valgrind)

# ENDIF ()
