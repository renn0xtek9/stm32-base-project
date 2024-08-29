CONFIGURE_FILE (${CMAKE_CURRENT_SOURCE_DIR}/index.html.in
                ${CMAKE_CURRENT_BINARY_DIR}/index.html)

ADD_CUSTOM_COMMAND (
    OUTPUT ${CMAKE_CURRENT_BINARY_DIR}/graph-packaging.png
    VERBATIM
    COMMAND make -Bnd packaging | make2graph | dot -T png -o ${CMAKE_CURRENT_BINARY_DIR}/graph-packaging.png
    WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
    COMMENT "Creating build graph for target: packaging")

ADD_CUSTOM_COMMAND (
    OUTPUT ${CMAKE_CURRENT_BINARY_DIR}/graph-documentation.png
    VERBATIM
    COMMAND make -Bnd documentation | make2graph | dot -T png -o ${CMAKE_CURRENT_BINARY_DIR}/graph-documentation.png
    WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
    COMMENT "Creating build graph for target: documentation")

ADD_CUSTOM_TARGET (
  software_build_process_documentation
  COMMENT "Software build process documentation"
  SOURCES ${CMAKE_SOURCE_DIR}/Makefile
  DEPENDS ${CMAKE_CURRENT_BINARY_DIR}/index.html ${CMAKE_CURRENT_BINARY_DIR}/graph-packaging.png ${CMAKE_CURRENT_BINARY_DIR}/graph-documentation.png)
