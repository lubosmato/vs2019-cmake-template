cmake_minimum_required (VERSION 3.14)

project("tests")

# Add subdirectories in /tests/
file(GLOB test_folders CONFIGURE_DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/*)
foreach(test_folder ${test_folders})
	if(IS_DIRECTORY ${test_folder})
		add_subdirectory(${test_folder})
	endif()
endforeach()
