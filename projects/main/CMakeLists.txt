cmake_minimum_required (VERSION 3.14)

set(EXE_NAME main)

set(Boost_USE_STATIC_LIBS ON)
set(Boost_USE_MULTITHREADED ON)
set(Boost_USE_STATIC_RUNTIME OFF)

find_package(Boost 1.70 EXACT REQUIRED COMPONENTS date_time)

file(GLOB SOURCE_FILES ./source/*)
add_executable(${EXE_NAME} ${SOURCE_FILES})
target_include_directories(${EXE_NAME} PRIVATE ./include/)

target_link_libraries(${EXE_NAME} PRIVATE ${Boost_LIBRARIES})
target_include_directories(${EXE_NAME} PRIVATE ${Boost_INCLUDE_DIRS})

# Add libraries
target_link_libraries(${EXE_NAME} PRIVATE huge_library)
target_link_libraries(${EXE_NAME} PRIVATE dll_library)
