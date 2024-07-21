MACRO (CreateLatexDocument _name _texsrc _resources _bibliography)
  FIND_PROGRAM (BIBER biber)
  FIND_PROGRAM (PDFLATEX pdflatex)
  FIND_PROGRAM (MAKEINDEX makeindex)

  IF (${BIBER}-NOTFOUND)
    MESSAGE (FATAL_ERROR "biber not found!")
  ENDIF ()
  IF (${PDFLATEX}-NOTFOUND)
    MESSAGE (FATAL_ERROR "pdflatex not found!")
  ENDIF ()
  IF (${MAKEINDEX}-NOTFOUND)
    MESAGE (FATAL_ERROR "pdflatex not found!")
  ENDIF ()
  SET (_output_folder "${CMAKE_CURRENT_BINARY_DIR}/${_name}/")
  FILE (MAKE_DIRECTORY ${_output_folder})

  IF (NOT WIN32)
    STRING (ASCII 27 Esc)
    SET (ColourReset "${Esc}[m")
    SET (ColourBold "${Esc}[1m")
    SET (Red "${Esc}[31m")
    SET (Green "${Esc}[32m")
    SET (Yellow "${Esc}[33m")
    SET (Blue "${Esc}[34m")
    SET (Magenta "${Esc}[35m")
    SET (Cyan "${Esc}[36m")
    SET (White "${Esc}[37m")
    SET (BoldRed "${Esc}[1;31m")
    SET (BoldGreen "${Esc}[1;32m")
    SET (BoldYellow "${Esc}[1;33m")
    SET (BoldBlue "${Esc}[1;34m")
    SET (BoldMagenta "${Esc}[1;35m")
    SET (BoldCyan "${Esc}[1;36m")
    SET (BoldWhite "${Esc}[1;37m")
  ENDIF ()

  ADD_CUSTOM_TARGET (
    ${_name}
    DEPENDS ${_output_folder}/${_name}.pdf
    SOURCES ${_texsrc})

  ADD_CUSTOM_COMMAND (
    OUTPUT ${_output_folder}/${_name}.pdf
    DEPENDS ${_texsrc} ${_resources} ${_bibliography}
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
    COMMENT "Generating ${_name}. See ${CMAKE_CURRENT_BINARY_DIR}/${_name}.log"
    VERBATIM
    COMMAND
      echo ${Magenta}${PDFLATEX} -halt-on-error -interaction nonstopmode
      -output-directory ${_output_folder}
      ${CMAKE_CURRENT_SOURCE_DIR}/${_name}.tex ${ColourReset}
    COMMAND
      ${PDFLATEX} -halt-on-error -interaction nonstopmode -output-directory
      ${_output_folder} ${CMAKE_CURRENT_SOURCE_DIR}/${_name}.tex >
      ${CMAKE_CURRENT_BINARY_DIR}/${_name}.log
    COMMAND echo ${Magenta} ${BIBER} --input-directory ${_output_folder}
            --output-directory ${_output_folder} ${_name}.bcf ${ColourReset}
    COMMAND
      ${BIBER} --input-directory ${_output_folder} --output-directory
      ${_output_folder} ${_name}.bcf >> ${CMAKE_CURRENT_BINARY_DIR}/${_name}.log
    COMMAND
      echo
      "${Magenta}cd ${_output_folder} && ${MAKEINDEX} ${_name}.idx${ColourReset}"
    COMMAND cd ${_output_folder} && ${MAKEINDEX} ${_name}.idx >>
            ${CMAKE_CURRENT_BINARY_DIR}/${_name}.log
    COMMAND
      echo
      "${Magenta}cd ${_output_folder} && ${MAKEINDEX} ${_name}.nlo -s nomencl.ist -o ${_name}.nls ${ColourReset}"
    COMMAND cd ${_output_folder} && ${MAKEINDEX} ${_name}.nlo -s nomencl.ist -o
            ${_name}.nls >> ${CMAKE_CURRENT_BINARY_DIR}/${_name}.log
    COMMAND
      echo
      "${Magenta}cd ${_output_folder} && ${MAKEINDEX} -s ${_name}.ist -t ${_name}.glg -o ${_name}.gls ${_name}.glo ${ColourReset}"
    COMMAND
      cd ${_output_folder} && ${MAKEINDEX} -s ${_name}.ist -t ${_name}.glg -o
      ${_name}.gls ${_name}.glo >> ${CMAKE_CURRENT_BINARY_DIR}/${_name}.log
    COMMAND
      echo
      "${Magenta}cd ${_output_folder} && ${MAKEINDEX} -s ${_name}.ist -t ${_name}.alg -o ${_name}.acr ${_name}.acn ${ColourReset}"
    COMMAND
      cd ${_output_folder} && ${MAKEINDEX} -s ${_name}.ist -t ${_name}.alg -o
      ${_name}.acr ${_name}.acn >> ${CMAKE_CURRENT_BINARY_DIR}/${_name}.log
    COMMAND
      echo
      "${Magenta}${PDFLATEX} -output-directory ${_output_folder} -halt-on-error -interaction nonstopmode ${CMAKE_CURRENT_SOURCE_DIR}/${_name}.tex ${ColourReset}"
    COMMAND
      ${PDFLATEX} -output-directory ${_output_folder} -halt-on-error
      -interaction nonstopmode ${CMAKE_CURRENT_SOURCE_DIR}/${_name}.tex >>
      ${CMAKE_CURRENT_BINARY_DIR}/${_name}.log)

ENDMACRO ()
