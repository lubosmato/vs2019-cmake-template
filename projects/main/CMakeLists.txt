cmake_minimum_required (VERSION 3.14)

set(EXE_NAME main)

set(Boost_USE_STATIC_LIBS ON)
set(Boost_USE_MULTITHREADED ON)
set(Boost_USE_STATIC_RUNTIME OFF)

file(GLOB SOURCE_FILES ./source/*)
add_executable(${EXE_NAME} ${SOURCE_FILES})
target_include_directories(${EXE_NAME} PRIVATE ./include/)

# Add external libraries
# Boost
find_package(Boost 1.70 EXACT REQUIRED COMPONENTS date_time)
target_link_libraries(${EXE_NAME} PRIVATE ${Boost_LIBRARIES})
target_include_directories(${EXE_NAME} PRIVATE ${Boost_INCLUDE_DIRS})

# OpenCV
find_package(OpenCV REQUIRED)
target_include_directories(${EXE_NAME} PRIVATE ${OpenCV_INCLUDE_DIRS})
target_link_libraries(${EXE_NAME} PRIVATE ${OpenCV_LIBS})

# Add libraries
target_link_libraries(${EXE_NAME} PRIVATE huge_library)
target_link_libraries(${EXE_NAME} PRIVATE dll_library)
