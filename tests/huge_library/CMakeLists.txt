cmake_minimum_required (VERSION 3.14)

get_filename_component(test_name ${CMAKE_CURRENT_SOURCE_DIR} NAME)
set(test_name "test_${test_name}")

file(GLOB test_source_files CONFIGURE_DEPENDS ${test_folder}/test_*)

add_executable(${test_name} ${test_source_files})
target_link_libraries(${test_name} CONAN_PKG::gtest huge_library)

add_test(
	NAME ${test_name}
	WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/bin
	COMMAND ${test_name}
)
