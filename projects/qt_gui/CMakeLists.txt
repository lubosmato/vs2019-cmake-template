cmake_minimum_required (VERSION 3.14)

get_filename_component(projectName ${CMAKE_CURRENT_SOURCE_DIR} NAME) # directory name is project name

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

find_package(Qt REQUIRED)
find_package(Qt5 REQUIRED COMPONENTS Core Gui Widgets)

file(GLOB sourceFiles CONFIGURE_DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/source/*.cpp)
file(GLOB ui_sourceFiles CONFIGURE_DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/source/ui/*)

add_library(${projectName} SHARED ${sourceFiles} ${ui_sourceFiles})

target_include_directories(${projectName} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include/)
target_include_directories(${projectName} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/source/)

target_link_libraries(${projectName} PRIVATE Qt5::Core Qt5::Gui Qt5::Widgets)
