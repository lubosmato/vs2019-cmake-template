cmake_minimum_required (VERSION 3.14)

get_filename_component(projectName ${CMAKE_CURRENT_SOURCE_DIR} NAME) # directory name is project name

file(GLOB sourceFiles CONFIGURE_DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/source/*)
add_library(${projectName} SHARED ${sourceFiles})
target_include_directories(${projectName} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include/)
