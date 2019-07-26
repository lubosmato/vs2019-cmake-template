cmake_minimum_required (VERSION 3.14)

set(LIB_NAME external_library)

add_library(${LIB_NAME} STATIC IMPORTED GLOBAL)

if(CMAKE_BUILD_TYPE STREQUAL "Debug")
	set_target_properties(${LIB_NAME} PROPERTIES IMPORTED_LOCATION ${CMAKE_CURRENT_SOURCE_DIR}/lib/libraryd.lib)
else()
	set_target_properties(${LIB_NAME} PROPERTIES IMPORTED_LOCATION ${CMAKE_CURRENT_SOURCE_DIR}/lib/library.lib)
endif()

target_include_directories(${LIB_NAME} INTERFACE ./include/)
