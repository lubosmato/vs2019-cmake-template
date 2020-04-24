cmake_minimum_required (VERSION 3.14)

get_filename_component(project_name ${CMAKE_CURRENT_SOURCE_DIR} NAME) # directory name is project name

set(CMAKE_CXX_STANDARD 17)

file(GLOB source_files CONFIGURE_DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/source/*)
add_executable(${project_name} ${source_files})
target_include_directories(${project_name} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include/)

# Add external libraries
# Boost
target_link_libraries(${project_name} PRIVATE CONAN_PKG::boost)

# OpenCV
find_package(OpenCV REQUIRED)
target_link_libraries(${project_name} PRIVATE ${OpenCV_LIBS})

# Add libraries
target_link_libraries(${project_name} PRIVATE huge_library2)
target_link_libraries(${project_name} PRIVATE huge_library)
target_link_libraries(${project_name} PRIVATE dll_library)
target_link_libraries(${project_name} PRIVATE external_library)
target_link_libraries(${project_name} PRIVATE qt_gui)
