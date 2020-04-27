# https://github.com/halex2005/CMakeHelpers/blob/master/generate_product_version.cmake

include (CMakeParseArguments)

set (GenerateProductVersionCurrentDir ${CMAKE_CURRENT_LIST_DIR})

# generate_product_version() function
#
# This function uses VersionInfo.in template file and VersionResource.rc file
# to generate WIN32 resource with version information and general resource strings.
#
# Usage:
#   generate_product_version(
#     SomeOutputResourceVariable
#     NAME MyGreatProject
#     ICON ${PATH_TO_APP_ICON}
#   )
# where BUILD_COUNTER and BUILD_REVISION could be values from your CI server.
#
# You can use generated resource for your executable targets:
#   add_executable(target-name ${target-files} ${SomeOutputResourceVariable})
#
# You can specify resource strings in arguments:
#   NAME               - name of executable (no defaults, ex: Microsoft Word)
#   BUNDLE             - bundle (${NAME} is default, ex: Microsoft Office)
#   ICON               - path to application icon (${CMAKE_SOURCE_DIR}/product.ico by default)
#   COMPANY_NAME       - your company name (no defaults)
#   COMPANY_COPYRIGHT  - ${COMPANY_NAME} (C) Copyright ${CURRENT_YEAR} is default
#   COMMENTS           - ${NAME} v${VERSION_MAJOR}.${VERSION_MINOR} is default
#   ORIGINAL_FILENAME  - ${NAME} is default
#   INTERNAL_NAME      - ${NAME} is default
#   FILE_DESCRIPTION   - ${NAME} is default
function(generate_product_version outfiles)
    set (options)
    set (oneValueArgs
        NAME
        BUNDLE
        ICON
        COMPANY_NAME
        COMPANY_COPYRIGHT
        COMMENTS
        ORIGINAL_FILENAME
        INTERNAL_NAME
        FILE_DESCRIPTION)
    set (multiValueArgs)
    cmake_parse_arguments(PRODUCT "${options}" "${oneValueArgs}" "${multiValueArgs}" ${ARGN})
    
    # TODO add support fo CI/CD variable passing for BUILD ID (instead of ugly file)

    find_package(Git)
    if(GIT_FOUND)
      execute_process(
        COMMAND ${GIT_EXECUTABLE} rev-parse HEAD
        WORKING_DIRECTORY "${local_dir}"
        OUTPUT_VARIABLE PRODUCT_VERSION_REVISION
        ERROR_QUIET
        OUTPUT_STRIP_TRAILING_WHITESPACE
      )
      message( STATUS "GIT hash: ${PRODUCT_VERSION_REVISION}")
    else()
        set(PRODUCT_VERSION_REVISION "unknown")
    endif()
 
    set(PRODUCT_VERSION_BUILD_ID "Debug")
    if(EXISTS "${CMAKE_SOURCE_DIR}/build_id.txt")
        file(STRINGS "${CMAKE_SOURCE_DIR}/build_id.txt" PRODUCT_VERSION_BUILD_ID)
    endif()
    
    set(VERSION_TEXT "0.0.0")
    if(EXISTS "${CMAKE_SOURCE_DIR}/version.txt")
        file(STRINGS "${CMAKE_SOURCE_DIR}/version.txt" VERSION_TEXT)
    endif()

    if (NOT PRODUCT_BUNDLE OR "${PRODUCT_BUNDLE}" STREQUAL "")
        set(PRODUCT_BUNDLE "${PRODUCT_NAME}")
    endif()
    if (NOT "${PRODUCT_ICON}" STREQUAL "")
        set(PRODUCT_ICON "${CMAKE_CURRENT_SOURCE_DIR}/${PRODUCT_ICON}")
    endif()

    string(REPLACE "." ";" VERSION_LIST ${VERSION_TEXT})
    list(GET VERSION_LIST 0 PRODUCT_VERSION_MAJOR)
    list(GET VERSION_LIST 1 PRODUCT_VERSION_MINOR)
    list(GET VERSION_LIST 2 PRODUCT_VERSION_PATCH)

    if (NOT PRODUCT_COMPANY_COPYRIGHT OR "${PRODUCT_COMPANY_COPYRIGHT}" STREQUAL "")
        string(TIMESTAMP PRODUCT_CURRENT_YEAR "%Y")
        set(PRODUCT_COMPANY_COPYRIGHT "${PRODUCT_COMPANY_NAME} (C) Copyright ${PRODUCT_CURRENT_YEAR}")
    endif()
    if (NOT PRODUCT_COMMENTS OR "${PRODUCT_COMMENTS}" STREQUAL "")
        set(PRODUCT_COMMENTS "${PRODUCT_NAME} v${PRODUCT_VERSION_MAJOR}.${PRODUCT_VERSION_MINOR}")
    endif()
    if (NOT PRODUCT_ORIGINAL_FILENAME OR "${PRODUCT_ORIGINAL_FILENAME}" STREQUAL "")
        set(PRODUCT_ORIGINAL_FILENAME "${PRODUCT_NAME}")
    endif()
    if (NOT PRODUCT_INTERNAL_NAME OR "${PRODUCT_INTERNAL_NAME}" STREQUAL "")
        set(PRODUCT_INTERNAL_NAME "${PRODUCT_NAME}")
    endif()
    if (NOT PRODUCT_FILE_DESCRIPTION OR "${PRODUCT_FILE_DESCRIPTION}" STREQUAL "")
        set(PRODUCT_FILE_DESCRIPTION "${PRODUCT_NAME}")
    endif()

    set (_VersionInfoFile ${CMAKE_CURRENT_BINARY_DIR}/VersionInfo.h)
    set (_VersionResourceFile ${CMAKE_CURRENT_BINARY_DIR}/VersionResource.rc)
    configure_file(
        ${GenerateProductVersionCurrentDir}/VersionInfo.in
        ${_VersionInfoFile}
        @ONLY)
    configure_file(
        ${GenerateProductVersionCurrentDir}/VersionResource.rc
        ${_VersionResourceFile}
        COPYONLY)
    list(APPEND ${outfiles} ${_VersionInfoFile} ${_VersionResourceFile})
    set (${outfiles} ${${outfiles}} PARENT_SCOPE)
endfunction()
