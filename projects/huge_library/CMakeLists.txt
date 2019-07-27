cmake_minimum_required (VERSION 3.14)

set(LIB_NAME huge_library)

file(GLOB SOURCE_FILES ${CMAKE_CURRENT_SOURCE_DIR}/source/*)
add_library(${LIB_NAME} STATIC ${SOURCE_FILES})
target_include_directories(${LIB_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include/)
