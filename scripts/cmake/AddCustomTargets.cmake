macro(AddCustomTargets)
  print("Custom Targets:")

  #_____________________________________________________________________________
  #                                                                          All
  print("  [X] All")
  if (WIN32)
    add_custom_target(All "${CMAKE_COMMAND}" --build "${CMAKE_BINARY_DIR}" --config ${SWITCH_BUILD_TYPE} DEPENDS ${PROJECT_NAME} COMMENT "Installing ${PROJECT_NAME}")
  elseif(XCODE)
    add_custom_target(All "${CMAKE_COMMAND}" --build "${CMAKE_BINARY_DIR}" DEPENDS ${PROJECT_NAME} COMMENT "Installing ${PROJECT_NAME}")
  elseif(UNIX)
    add_custom_target(All "${CMAKE_COMMAND}" --build "${CMAKE_BINARY_DIR}" -- -j 8 DEPENDS ${PROJECT_NAME} COMMENT "Installing ${PROJECT_NAME}")
  endif()

  #_____________________________________________________________________________
  #                                                                        Check
  #print("  [X] Check")
  #configure_file(${CMAKE_CURRENT_SOURCE_DIR}/.cppcheck_false_positive ${CMAKE_CURRENT_BINARY_DIR}/cppcheck_false_positive @ONLY)
  #add_custom_target(Check COMMAND ${CPPCHECK_EXECUTABLE} ${CPPCHECK_ARGS_ALL} COMMENT "running cppcheck" DEPENDS ${CPPCHECK_PROJECT})

  #_____________________________________________________________________________
  #                                                                 Check.Switch
  print("  [X] Check.${PROJECT_NAME}")
  configure_file(${CMAKE_CURRENT_SOURCE_DIR}/.cppcheck_false_positive ${CMAKE_CURRENT_BINARY_DIR}/cppcheck_false_positive @ONLY)
  add_custom_target(Check.${PROJECT_NAME} COMMAND ${CPPCHECK_EXECUTABLE} ${CPPCHECK_ARGS_SWITCH} COMMENT "running cppcheck" DEPENDS ${CPPCHECK_PROJECT})

  #_____________________________________________________________________________
  #                                                            Check.Switch.Core
  print("  [X] Check.${PROJECT_NAME}.Core")
  configure_file(${CMAKE_CURRENT_SOURCE_DIR}/.cppcheck_false_positive ${CMAKE_CURRENT_BINARY_DIR}/cppcheck_false_positive @ONLY)
  add_custom_target(Check.${PROJECT_NAME}.Core COMMAND ${CPPCHECK_EXECUTABLE} ${CPPCHECK_ARGS_SWITCH_CORE} COMMENT "running cppcheck" DEPENDS ${CPPCHECK_PROJECT})

  #_____________________________________________________________________________
  #                                                          Check.Switch.System
  print("  [X] Check.${PROJECT_NAME}.System")
  configure_file(${CMAKE_CURRENT_SOURCE_DIR}/.cppcheck_false_positive ${CMAKE_CURRENT_BINARY_DIR}/cppcheck_false_positive @ONLY)
  add_custom_target(Check.${PROJECT_NAME}.System COMMAND ${CPPCHECK_EXECUTABLE} ${CPPCHECK_ARGS_SWITCH_SYSTEM} COMMENT "running cppcheck" DEPENDS ${CPPCHECK_PROJECT})

  #_____________________________________________________________________________
  #                                                     Check.Switch.System.Core
  print("  [X] Check.${PROJECT_NAME}.System.Core")
  configure_file(${CMAKE_CURRENT_SOURCE_DIR}/.cppcheck_false_positive ${CMAKE_CURRENT_BINARY_DIR}/cppcheck_false_positive @ONLY)
  add_custom_target(Check.${PROJECT_NAME}.System.Core COMMAND ${CPPCHECK_EXECUTABLE} ${CPPCHECK_ARGS_SWITCH_SYSTEM_CORE} COMMENT "running cppcheck" DEPENDS ${CPPCHECK_PROJECT})

  #_____________________________________________________________________________
  #                                                  Check.Switch.System.Drawing
  print("  [X] Check.${PROJECT_NAME}.System.Drawing")
  configure_file(${CMAKE_CURRENT_SOURCE_DIR}/.cppcheck_false_positive ${CMAKE_CURRENT_BINARY_DIR}/cppcheck_false_positive @ONLY)
  add_custom_target(Check.${PROJECT_NAME}.System.Drawing COMMAND ${CPPCHECK_EXECUTABLE} ${CPPCHECK_ARGS_SWITCH_SYSTEM_DRAWING} COMMENT "running cppcheck" DEPENDS ${CPPCHECK_PROJECT})

  #_____________________________________________________________________________
  #                                             Check.Switch.System.ServiceModel
  print("  [X] Check.${PROJECT_NAME}.System.ServiceModel")
  configure_file(${CMAKE_CURRENT_SOURCE_DIR}/.cppcheck_false_positive ${CMAKE_CURRENT_BINARY_DIR}/cppcheck_false_positive @ONLY)
  add_custom_target(Check.${PROJECT_NAME}.System.ServiceModel COMMAND ${CPPCHECK_EXECUTABLE} ${CPPCHECK_ARGS_SWITCH_SYSTEM_SERVICEMODEL} COMMENT "running cppcheck" DEPENDS ${CPPCHECK_PROJECT})

  #_____________________________________________________________________________
  #                                            Check.Switch.System.Windows.Forms
  print("  [X] Check.${PROJECT_NAME}.System.Windows.Forms")
  configure_file(${CMAKE_CURRENT_SOURCE_DIR}/.cppcheck_false_positive ${CMAKE_CURRENT_BINARY_DIR}/cppcheck_false_positive @ONLY)
  add_custom_target(Check.${PROJECT_NAME}.System.Windows.Forms COMMAND ${CPPCHECK_EXECUTABLE} ${CPPCHECK_ARGS_SWITCH_SYSTEM_WINDOWS_FORMS} COMMENT "running cppcheck" DEPENDS ${CPPCHECK_PROJECT})

  #_____________________________________________________________________________
  #                                                      Check.Switch.TUnit.Core
  print("  [X] Check.${PROJECT_NAME}.System.TUnit.Core")
  configure_file(${CMAKE_CURRENT_SOURCE_DIR}/.cppcheck_false_positive ${CMAKE_CURRENT_BINARY_DIR}/cppcheck_false_positive @ONLY)
  add_custom_target(Check.${PROJECT_NAME}.TUnit.Core COMMAND ${CPPCHECK_EXECUTABLE} ${CPPCHECK_ARGS_SWITCH_TUNIT_CORE} COMMENT "running cppcheck" DEPENDS ${CPPCHECK_PROJECT})

  #_____________________________________________________________________________
  #                                                 Check.Switch.TUnit.Framework
  print("  [X] Check.${PROJECT_NAME}.System.TUnit.Framework")
  configure_file(${CMAKE_CURRENT_SOURCE_DIR}/.cppcheck_false_positive ${CMAKE_CURRENT_BINARY_DIR}/cppcheck_false_positive @ONLY)
  add_custom_target(Check.${PROJECT_NAME}.TUnit.Framework COMMAND ${CPPCHECK_EXECUTABLE} ${CPPCHECK_ARGS_SWITCH_TUNIT_FRAMEWORK} COMMENT "running cppcheck" DEPENDS ${CPPCHECK_PROJECT})

  #_____________________________________________________________________________
  #                                                      Check.Switch.TUnit.Main
  print("  [X] Check.${PROJECT_NAME}.System.TUnit.Main")
  configure_file(${CMAKE_CURRENT_SOURCE_DIR}/.cppcheck_false_positive ${CMAKE_CURRENT_BINARY_DIR}/cppcheck_false_positive @ONLY)
  add_custom_target(Check.${PROJECT_NAME}.TUnit.Main COMMAND ${CPPCHECK_EXECUTABLE} ${CPPCHECK_ARGS_SWITCH_TUNIT_MAIN} COMMENT "running cppcheck" DEPENDS ${CPPCHECK_PROJECT})

  #_____________________________________________________________________________
  #                                                                       Format
  print("  [X] Format")
  add_custom_target(Format COMMAND ${ASTYLE_EXECUTABLE} ${ASTYLE_ARGS} COMMENT "running astyle" DEPENDS ${ASTYLE_PROJECT})

  #_____________________________________________________________________________
  #                                                                     Gitcheck
  print("  [X] GitCheck")
  add_custom_target(GitCheck COMMAND git diff --check HEAD^ COMMENT "running git check")

  #_____________________________________________________________________________
  #                                                               Install.Switch
  print("  [X] Install.${PROJECT_NAME}")
  if (WIN32)
    add_custom_target(Install.${PROJECT_NAME} "${CMAKE_COMMAND}" --build "${CMAKE_BINARY_DIR}" --target install --config ${SWITCH_BUILD_TYPE} DEPENDS ${PROJECT_NAME} COMMENT "Installing ${PROJECT_NAME}")
  elseif (XCODE)
    add_custom_target(Install.${PROJECT_NAME} "${CMAKE_COMMAND}" --build "${CMAKE_BINARY_DIR}" --target install DEPENDS ${PROJECT_NAME} COMMENT "Installing ${PROJECT_NAME}")
  elseif (UNIX)
    add_custom_target(Install.${PROJECT_NAME} "${CMAKE_COMMAND}" --build "${CMAKE_BINARY_DIR}" --target install -- -j 8 DEPENDS ${PROJECT_NAME} COMMENT "Installing ${PROJECT_NAME}")
  endif()

  #_____________________________________________________________________________
  #                                                               ReferenceGuide
  print("  [X] ReferenceGuide")
  configure_file(${CMAKE_CURRENT_SOURCE_DIR}/.doxygen.txt ${CMAKE_CURRENT_BINARY_DIR}/doxygen.txt @ONLY)
  file(MAKE_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/ReferenceGuide)
  add_custom_target(ReferenceGuide ${DOXYGEN_EXECUTABLE} ${CMAKE_CURRENT_BINARY_DIR}/doxygen.txt WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/ReferenceGuide COMMENT "Doxygen Reference Guide generation" DEPENDS ${DOXYGEN_PROJECT} VERBATIM)

  #_____________________________________________________________________________
  #                                                                        Tests
  print("  [X] Tests.${PROJECT_NAME}")
  add_custom_target(Tests COMMAND ctest --output-on-failure -C ${SWITCH_BUILD_TYPE} DEPENDS All)
endmacro()
