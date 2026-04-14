find_package(Doxygen)

if(Doxygen_FOUND)

  set(DOXYGEN_DIR ${CMAKE_SOURCE_DIR}/docs/)
  set(DOXYFILE "${DOXYGEN_DIR}/doxygen.conf")
  set(DOXYGEN_OUT "${CMAKE_CURRENT_BINARY_DIR}/docs")
  set(DOXYGEN_GENERATE_HTML YES)

  if(NOT EXISTS "${DOXYFILE}")
    execute_process(COMMAND doxygen -g ${DOXYFILE})
    message("A new Doxygen confiruation was generated")
  endif()

  doxygen_add_docs(
    docs 
    ${CMAKE_SOURCE_DIR}/src 
    ${CMAKE_SOURCE_DIR}/${INCLUDE}
    WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}/docs
    CONFIG_FILE ${DOXYFILE}
  )
else(Doxygen_FOUND)
  message("Configuration for documentation is ON, but it appears that Doxygen is not installed.")
endif()
