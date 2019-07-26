cmake_minimum_required (VERSION 3.14)

project("template")

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin/)

# Add subdirectories in ./projects/ 
file(GLOB project_folders ${CMAKE_CURRENT_SOURCE_DIR}/projects/*)
foreach(project_folder ${project_folders})
	if(IS_DIRECTORY ${project_folder})
		add_subdirectory(${project_folder})
	endif()
endforeach()
