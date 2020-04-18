cmake_minimum_required (VERSION 3.14)

set(LIB_NAME qt_gui)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

find_package(Qt5 5.12.5 EXACT REQUIRED COMPONENTS Core Gui Widgets)

file(GLOB SOURCE_FILES CONFIGURE_DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/source/*.cpp)
file(GLOB UI_SOURCE_FILES CONFIGURE_DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/source/ui/*)

add_library(${LIB_NAME} SHARED ${SOURCE_FILES} ${UI_SOURCE_FILES})

target_include_directories(${LIB_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include/)
target_include_directories(${LIB_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/source/)

target_link_libraries(${LIB_NAME} Qt5::Core Qt5::Gui Qt5::Widgets)
