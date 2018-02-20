include_directories ("${PROJECT_SOURCE_DIR}/src"
        "C:/Program\ Files \(x86\)/cmocka/include/"
        "C:/Program\ Files \(x86\)/cmocka/bin/")

add_executable(test_bittle test_bittle.c)
add_dependencies(bittle bittle)

ADD_TEST(ctest_build_tests "${CMAKE_COMMAND}" --build ${CMAKE_BINARY_DIR} --target test_bittle)
ADD_TEST(bittleTest test_bittle)
SET_TESTS_PROPERTIES ( bittleTest PROPERTIES DEPENDS ctest_build_tests)

target_link_libraries(test_bittle bittle cmocka)

add_custom_command(TARGET test_bittle POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory
        "${PROJECT_SOURCE_DIR}/win_incl"
        $<TARGET_FILE_DIR:test_bittle>)

add_custom_target(check COMMAND ${CMAKE_CTEST_COMMAND} --verbose)