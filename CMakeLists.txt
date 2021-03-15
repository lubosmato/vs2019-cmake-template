cmake_minimum_required (VERSION 3.14)

project("template")

enable_testing()

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")
list(APPEND CMAKE_PREFIX_PATH "${CMAKE_CURRENT_SOURCE_DIR}/build")

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin)

include(generate_product_version)

# Add subdirectories in ./projects/
file(GLOB project_folders CONFIGURE_DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/projects/*)
foreach(project_folder ${project_folders})
	if(IS_DIRECTORY ${project_folder})
		add_subdirectory(${project_folder})
	endif()
endforeach()

add_subdirectory(tests)
