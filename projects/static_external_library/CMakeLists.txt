cmake_minimum_required (VERSION 3.14)

get_filename_component(projectName ${CMAKE_CURRENT_SOURCE_DIR} NAME) # directory name is project name

add_library(${projectName} STATIC IMPORTED GLOBAL)

if(CMAKE_BUILD_TYPE STREQUAL "Debug")
	set_target_properties(${projectName} PROPERTIES IMPORTED_LOCATION ${CMAKE_CURRENT_SOURCE_DIR}/lib/libraryd.lib)
else()
	set_target_properties(${projectName} PROPERTIES IMPORTED_LOCATION ${CMAKE_CURRENT_SOURCE_DIR}/lib/library.lib)
endif()

target_include_directories(${projectName} INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/include/)
