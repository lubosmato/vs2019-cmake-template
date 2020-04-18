cmake_minimum_required (VERSION 3.14)

set(CMAKE_CXX_STANDARD 17)
set(EXE_NAME main)

set(Boost_USE_STATIC_LIBS ON)
set(Boost_USE_MULTITHREADED ON)
set(Boost_USE_STATIC_RUNTIME OFF)

file(GLOB SOURCE_FILES CONFIGURE_DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/source/*)
add_executable(${EXE_NAME} ${SOURCE_FILES})
target_include_directories(${EXE_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include/)

# Add external libraries
# Boost
find_package(Boost 1.72 EXACT REQUIRED COMPONENTS date_time)
target_include_directories(${EXE_NAME} PRIVATE ${Boost_INCLUDE_DIRS})
target_link_libraries(${EXE_NAME} PRIVATE ${Boost_LIBRARIES})

# OpenCV
find_package(OpenCV 4.1.1 EXACT REQUIRED)
target_include_directories(${EXE_NAME} PRIVATE ${OpenCV_INCLUDE_DIRS})
target_link_libraries(${EXE_NAME} PRIVATE ${OpenCV_LIBS})

# Add libraries
target_link_libraries(${EXE_NAME} PRIVATE huge_library2)
target_link_libraries(${EXE_NAME} PRIVATE huge_library)
target_link_libraries(${EXE_NAME} PRIVATE dll_library)
target_link_libraries(${EXE_NAME} PRIVATE external_library)
target_link_libraries(${EXE_NAME} PRIVATE qt_gui)
