cmake_minimum_required (VERSION 3.14)

set(LIB_NAME dll_library)

file(GLOB SOURCE_FILES ./source/*)
add_library(${LIB_NAME} SHARED ${SOURCE_FILES})
target_include_directories(${LIB_NAME} PUBLIC ./include/)
