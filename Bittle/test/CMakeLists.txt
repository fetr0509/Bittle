include_directories ("${PROJECT_SOURCE_DIR}/src")
add_executable(test_bittle test_bittle.c)
add_dependencies(bittle bittle)

ADD_TEST(ctest_build_test_code "${CMAKE_COMMAND}" --build ${CMAKE_BINARY_DIR} --target test_bittle)
ADD_TEST(bittleTest test_bittle)
SET_TESTS_PROPERTIES ( bittleTest PROPERTIES DEPENDS ctest_build_test_code)

target_link_libraries(test_bittle bittle cmocka)