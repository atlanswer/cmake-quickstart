cmake_minimum_required(VERSION 3.7...3.23)

if(${CMAKE_VERSION} VERSION_LESS 3.12)
    cmake_policy(VERSION ${CMAKE_MAJOR_VERSION}.${CMAKE_MINOR_VERSION})
endif()

# Regular expression that matches a define preprocessor.
set(VERSION_REGEX "#define LIBNAME_VERSION[ \t]+\"(.+)\"")

# Read the sourcefile that contains the version info.
file(STRINGS "${CMAKE_CURRENT_SOURCE_DIR}/include/libName/version.hpp"
    VERSION_STR REGEX ${VERSION_REGEX})

# Replace the captured version.
string(REGEX REPLACE ${VERSION_REGEX} "\\1" VERSION_STR "${VERSION_STR}")

project(cmake-quickstart VERSION ${VERSION_STR}
    DESCRIPTION "CMake C++ template"
    LANGUAGES CXX)

# Find packages here.

# set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/bin")

set(default_build_type "Debug")
if(NOT CMAKE_BUILD_TYPE AND NOT CMAKE_CONFIGURATION_TYPES)
    message(STATUS "Setting build type to \"${default_build_type}\" as none was specified.")
    set(CMAKE_BUILD_TYPE "${default_build_type}" CACHE
    STRING "Choose the build type." FORCE)
    set_property(CACHE CMAKE_BUILD_TYPE PROPERTY STRINGS
    "Debug" "Release" "MinSizeRel" "RelWithDebInfo")
else()
    message(STATUS "Build type was specified as CMAKE_BUILD_TYPE=${CMAKE_BUILD_TYPE}")
endif()

# include(CTest)
# enable_testing()
add_library(libName STATIC src/libName.cpp
    include/libName/version.hpp
    include/libName/libName.hpp)
target_include_directories(libName PUBLIC include)
target_compile_features(libName PUBLIC cxx_std_20)

add_executable(cli apps/cli.cpp)
target_compile_features(cli PUBLIC cxx_std_20)
target_link_libraries(cli PUBLIC libName)

# target_sources(${PROJECT_NAME} PUBLIC "${SOURCES}")

# target_include_directories(${PROJECT_NAME}
# PUBLIC
# $<INSTALL_INTERFACE:include>
# $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
# $<BUILD_INTERFACE:${CMAKE_CURRENT_BINARY_DIR}>
# )

# set_target_properties(${PROJECT_NAME} PROPERTIES
# VERSION ${PROJECT_VERSION}
# SOVERSION ${PROJECT_VERSION})

# # add_custom_command(
# #     TARGET ${PROJECT_NAME} POST_BUILD
# #     COMMAND ${CMAKE_COMMAND} -E copy_if_different "${LIB_DIR}/shared.dll" $<TARGET_FILE_DIR:cpptest>
# # )

# set(CPACK_PROJECT_NAME ${PROJECT_NAME})
# set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
# include(CPack)

# find_package(Git QUIET)

# if(GIT_FOUND AND EXISTS "${PROJECT_SOURCE_DIR}/.git")
#     execute_process(COMMAND ${GIT_EXECUTABLE} submodule update --init --recursive
#                     WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
#                     RESULT_VARIABLE GIT_SUBMOD_RESULT)
#     if(NOT GIT_SUBMOD_RESULT EQUAL "0")
#         message(FATAL_ERROR "git submodule update --init --recursive failed with ${GIT_SUBMOD_RESULT}, please checkout submodules")
#     endif()
# endif()
