find_package(Doxygen)

if(Doxygen_FOUND)

  set(DOXYGEN_DIR ${CMAKE_SOURCE_DIR}/docs/)
  set(DOXYFILE "${DOXYGEN_DIR}/doxygen.conf")
  set(DOXYGEN_OUT "${CMAKE_CURRENT_BINARY_DIR}/docs")
  set(DOXYGEN_GENERATE_HTML YES)

  if(NOT EXISTS "${DOXYFILE}")
    # Generate a new doxygen.conf
    execute_process(COMMAND doxygen -g ${DOXYFILE})
    # Update the INPUT variable in dogygen's template
    execute_process(COMMAND sed -i -e "s/INPUT\ *=/& ..\\/README.md . ..\\/src ..\\/include/g" ${DOXYFILE})
    # Set the README.md as the main page
    execute_process(COMMAND sed -i -e "s/USE_MDFILE_AS_MAINPAGE\ *=/& ..\\/README.md/g" ${DOXYFILE})
    message(STATUS "A new Doxygen confiruation was generated")
  endif()

  doxygen_add_docs(
    docs 
    ${CMAKE_SOURCE_DIR}/src 
    ${CMAKE_SOURCE_DIR}/${INCLUDE}
    CONFIG_FILE ${DOXYFILE}
  )
else(Doxygen_FOUND)
  message("Configuration for documentation is ON, but it appears that Doxygen is not installed.")
endif()
