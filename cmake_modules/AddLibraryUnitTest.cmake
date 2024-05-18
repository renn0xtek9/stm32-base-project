INCLUDE (CMakeParseArguments)
FUNCTION (add_library_unit_test)
  CMAKE_PARSE_ARGUMENTS (
    PARSED_ARGS # prefix of output variables
    "" # list of names of the boolean arguments (only defined ones will be true)
    "NAME" # list of names of mono-valued arguments
    "SRCS;DEPS" # list of names of multi-valued arguments (output variables are
                # lists)
    ${ARGN} # arguments of the function to parse, here we take the all original
            # ones
  )
  IF (NOT PARSED_ARGS_SRCS)
    MESSAGE (FATAL_ERROR "You must provide unit test sources for ${LIBNAME}")
  ENDIF (NOT PARSED_ARGS_SRCS)

  FIND_PACKAGE (GTest REQUIRED)
  INCLUDE_DIRECTORIES (${GTEST_INCLUDE_DIRS})
  ADD_EXECUTABLE (${LIBNAME}_test ${PARSED_ARGS_SRCS})

  SET (
    GCC_FLAGS
    -Werror
    -Wall
    -Wextra
    -Wpedantic
    -Wshadow
    -Wconversion
    -Wformat=2
    -Wnull-dereference
    -Wduplicated-cond
    -Wduplicated-branches
    -Wlogical-op
    -Wuseless-cast
    -fanalyzer
    -fsanitize=address
    -fsanitize=undefined
    -D_FORTIFY_SOURCE=2)
  TARGET_COMPILE_OPTIONS (${LIBNAME}_test PRIVATE ${GCC_FLAGS})

  TARGET_LINK_OPTIONS (${LIBNAME}_test PRIVATE -fsanitize=address
                       -fsanitize=undefined)
  TARGET_LINK_LIBRARIES (${LIBNAME}_test ${LIBNAME} ${GTEST_BOTH_LIBRARIES})
  ADD_TEST (NAME ${LIBNAME}_test COMMAND ${LIBNAME}_test)
  SET_TESTS_PROPERTIES (${LIBNAME}_test PROPERTIES FIXTURES_REQUIRED unit_tests
                                                   LABELS unit_tests)

  ADD_CUSTOM_COMMAND (
    COMMAND
      valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes
      --verbose --log-file=valgrind-${LIBNAME}-out.txt
      $<TARGET_FILE:${LIBNAME}_test>
    WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
    OUTPUT valgrind-${LIBNAME}-out.txt
    COMMENT "Analyze ${LIBNAME}_test with valgrind")

  ADD_CUSTOM_TARGET (valgrind-leak-check-${LIBNAME}
                     DEPENDS valgrind-${LIBNAME}-out.txt)

  ADD_TEST (
    NAME memory_leak_analysis-${LIBNAME}
    COMMAND make valgrind-leak-check-${LIBNAME}
    CONFIGURATIONS Debug)
  SET_TESTS_PROPERTIES (memory_leak_analysis-${LIBNAME}
                        PROPERTIES FIXTURES_REQUIRED quality LABELS quality)

ENDFUNCTION ()
