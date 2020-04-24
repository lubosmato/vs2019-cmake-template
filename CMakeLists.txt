cmake_minimum_required (VERSION 3.14)

project("template")

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin)

include(${PROJECT_SOURCE_DIR}/build/conanbuildinfo_multi.cmake)
conan_basic_setup(TARGETS)

# Add subdirectories in ./projects/
file(GLOB project_folders CONFIGURE_DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/projects/*)
foreach(project_folder ${project_folders})
	if(IS_DIRECTORY ${project_folder})
		add_subdirectory(${project_folder})
	endif()
endforeach()

add_subdirectory(tests)
