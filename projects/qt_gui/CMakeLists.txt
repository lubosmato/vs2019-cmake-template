cmake_minimum_required (VERSION 3.14)

get_filename_component(project_name ${CMAKE_CURRENT_SOURCE_DIR} NAME) # directory name is project name

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

find_package(Qt5 5.12.8 EXACT REQUIRED COMPONENTS Core Gui Widgets)

file(GLOB source_files CONFIGURE_DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/source/*.cpp)
file(GLOB ui_source_files CONFIGURE_DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/source/ui/*)

add_library(${project_name} SHARED ${source_files} ${ui_source_files})

target_include_directories(${project_name} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include/)
target_include_directories(${project_name} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/source/)

target_link_libraries(${project_name} Qt5::Core Qt5::Gui Qt5::Widgets)
