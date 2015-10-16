cmake_minimum_required(VERSION 2.8)

project(APIToolkitMainImplementation)

include_directories(${API_TOOLKIT_HEADERS_FOLDER}/Loader)
#include_directories(${API_TOOLKIT_HEADERS_FOLDER}/Unit)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/Includes)

file(GLOB_RECURSE SRCS
    "${CMAKE_CURRENT_SOURCE_DIR}/Sources/Load/*.cpp"
#    "${CMAKE_CURRENT_SOURCE_DIR}/Sources/Unit/*.cpp"
    )

add_library(APIMain ${SRCS})
target_include_directories(APIMain PUBLIC "${API_TOOLKIT_HEADERS_FOLDER}")