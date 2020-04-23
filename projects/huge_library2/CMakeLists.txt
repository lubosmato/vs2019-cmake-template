cmake_minimum_required (VERSION 3.14)

get_filename_component(project_name ${CMAKE_CURRENT_SOURCE_DIR} NAME) # directory name is project name

file(GLOB source_files CONFIGURE_DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/source/*)
add_library(${project_name} STATIC ${source_files})
target_include_directories(${project_name} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include/)
