ADD_SUBDIRECTORY (requirements_engineering)

# Doxygen documentation
CONFIGURE_FILE (${CMAKE_CURRENT_SOURCE_DIR}/code_documentation.doxygen.in
                ${CMAKE_CURRENT_BINARY_DIR}/code_documentation.doxygen)
ADD_CUSTOM_COMMAND (
  OUTPUT ${CMAKE_CURRENT_BINARY_DIR}/code_documentation/html/index.html
  DEPENDS ${CMAKE_CURRENT_BINARY_DIR}/code_documentation.doxygen
  VERBATIM
  COMMAND doxygen ${CMAKE_CURRENT_BINARY_DIR}/code_documentation.doxygen
  WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
  COMMENT "Building code documentation")
ADD_CUSTOM_TARGET (
  code_documentation
  SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/code_documentation.doxygen.in
  DEPENDS ${CMAKE_CURRENT_BINARY_DIR}/code_documentation/html/index.html)
