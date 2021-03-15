cmake_minimum_required (VERSION 3.14)

get_filename_component(projectName ${CMAKE_CURRENT_SOURCE_DIR} NAME) # directory name is project name

set(CMAKE_CXX_STANDARD 20)
add_compile_options("/std:c++latest")
add_compile_options("/await")
add_compile_options("/experimental:module")

generate_product_version(productVersionFiles
    NAME main
    ICON "product.ico"
    COMPANY_NAME "My Company"
)

file(GLOB sourceFiles CONFIGURE_DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/source/*)
add_executable(${projectName} ${sourceFiles} ${productVersionFiles})
target_include_directories(${projectName} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include/)

# Add external libraries
# Boost
find_package(Boost 1.73 REQUIRED)
target_link_libraries(${projectName} PRIVATE Boost::boost Boost::system Boost::thread)

# OpenCV
# TODO fix it
# find_package(OpenCV REQUIRED COMPONENTS core imgproc highgui)
# target_link_libraries(${projectName} PRIVATE opencv::opencv)

# Add libraries
target_link_libraries(${projectName} PRIVATE static_library)
target_link_libraries(${projectName} PRIVATE dll_library)
target_link_libraries(${projectName} PRIVATE static_external_library)
target_link_libraries(${projectName} PRIVATE qt_gui)
