cmake_minimum_required (VERSION 3.14)

get_filename_component(projectName ${CMAKE_CURRENT_SOURCE_DIR} NAME) # directory name is project name

set(CMAKE_CXX_STANDARD 17)

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
target_link_libraries(${projectName} PRIVATE CONAN_PKG::boost)

# OpenCV
find_package(OpenCV REQUIRED)
target_link_libraries(${projectName} PRIVATE ${OpenCV_LIBS})

# Add libraries
target_link_libraries(${projectName} PRIVATE static_library)
target_link_libraries(${projectName} PRIVATE dll_library)
target_link_libraries(${projectName} PRIVATE static_external_library)
target_link_libraries(${projectName} PRIVATE qt_gui)
