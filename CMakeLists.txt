cmake_minimum_required(VERSION 2.8)
project(APIToolkit)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${PROJECT_SOURCE_DIR}/CMake")

option(COVERALLS "Generate coveralls data" OFF)

if (COVERALLS)
    include(Coveralls)
    coveralls_turn_on_coverage()
endif()

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
set(API_TOOLKIT_HEADERS_FOLDER "${CMAKE_CURRENT_SOURCE_DIR}/Headers")
set(API_TOOLKIT_IMPL_FOLDER "${CMAKE_CURRENT_SOURCE_DIR}/Implementations")

file(GLOB_RECURSE HEADERS Headers/*.h)
add_custom_target(OSSIAToolkitHeaders SOURCES ${HEADERS})
add_library(OSSIAToolkitHeadersLib INTERFACE)

target_include_directories(OSSIAToolkitHeadersLib INTERFACE "${API_TOOLKIT_HEADERS_FOLDER}")
include_directories(Headers)

add_subdirectory(Implementations)
#if(NOT OSSIA_NO_EXAMPLES)
    add_subdirectory(Documentation/Examples)
#endif()

if(NOT OSSIA_NO_TESTS)
    add_subdirectory(Tests)
endif()
