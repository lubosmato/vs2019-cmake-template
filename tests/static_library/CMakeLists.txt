cmake_minimum_required (VERSION 3.14)

get_filename_component(test_name ${CMAKE_CURRENT_SOURCE_DIR} NAME)
set(test_name "test_${test_name}")

file(GLOB testSourceFiles CONFIGURE_DEPENDS ${test_folder}/test_*)

find_package(GTest CONFIG REQUIRED)

add_executable(${test_name} ${testSourceFiles})
add_test(
	NAME ${test_name}
	WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/bin
	COMMAND ${test_name}
)

target_link_libraries(${test_name} PRIVATE GTest::gmock GTest::gtest GTest::gtest_main static_library)
