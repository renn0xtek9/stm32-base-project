INCLUDE (CMakeParseArguments)
FUNCTION (create_library)
  CMAKE_PARSE_ARGUMENTS (
    PARSED_ARGS
    "" # List of boolean names
    "" # list of names of mono-valued arguments
    "SRCS;PUBLIC_HEADERS" # list of names of multi-valued arguments (output
                          # variables are lists)
    ${ARGN} # arguments of the function to parse, here we take the all original
            # ones
  )
  IF (NOT PARSED_ARGS_SRCS)
    MESSAGE (FATAL_ERROR "No SRCS specified for ${LIBNAME}")
  ENDIF (NOT PARSED_ARGS_SRCS)

  IF (NOT PARSED_ARGS_PUBLIC_HEADERS)
    MESSAGE (WARNING "No PUBLIC_HEADERS specified for ${LIBNAME}")
  ENDIF (NOT PARSED_ARGS_PUBLIC_HEADERS)

  ADD_LIBRARY (${LIBNAME} SHARED ${PARSED_ARGS_SRCS})

  TARGET_INCLUDE_DIRECTORIES (
    ${LIBNAME} PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include/>
                      $<INSTALL_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>)

  SET_TARGET_PROPERTIES (${LIBNAME} PROPERTIES PUBLIC_HEADER
                                               "${PARSED_ARGS_PUBLIC_HEADERS}")
  INSTALL (
    TARGETS ${LIBNAME}
    PUBLIC_HEADER DESTINATION include/${LIBNAME}
    LIBRARY DESTINATION lib/${LIBNAME} COMPONENT Libraries)

  IF (${CMAKE_BUILD_TYPE} STREQUAL "Debug")

    SET (GCC_COVERAGE_COMPILE_FLAGS -g -O0 -coverage -fprofile-arcs
                                    -ftest-coverage)
    SET (GCC_COVERAGE_LINK_FLAGS -coverage -lgcov -ftest-coverage)

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

    TARGET_COMPILE_OPTIONS (${LIBNAME} PRIVATE ${GCC_COVERAGE_COMPILE_FLAGS}
                                               ${GCC_FLAGS})
    TARGET_COMPILE_DEFINITIONS (${LIBNAME} PRIVATE -DDEBUG)

    TARGET_LINK_OPTIONS (${LIBNAME} PRIVATE ${GCC_COVERAGE_LINK_FLAGS}
                         -fsanitize=address -fsanitize=undefined)
    TARGET_LINK_LIBRARIES (${LIBNAME} PRIVATE --coverage)

  ENDIF ()

ENDFUNCTION ()
