cmake_minimum_required(VERSION 2.8)

project(APIToolkitMainImplementation)

include_directories(${API_TOOLKIT_HEADERS_FOLDER}/Debug)
include_directories(${API_TOOLKIT_HEADERS_FOLDER}/Setup)  
#include_directories(${API_TOOLKIT_HEADERS_FOLDER}/Units)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/Includes)

file(GLOB_RECURSE SRCS
	"${CMAKE_CURRENT_SOURCE_DIR}/Includes/Debug/*.h"
	"${CMAKE_CURRENT_SOURCE_DIR}/Includes/Setup/*.h"
#	"${CMAKE_CURRENT_SOURCE_DIR}/Includes/Units/*.h"
    "${CMAKE_CURRENT_SOURCE_DIR}/Sources/Debug/*.cpp"
	"${CMAKE_CURRENT_SOURCE_DIR}/Sources/Setup/*.cpp" 
#    "${CMAKE_CURRENT_SOURCE_DIR}/Sources/Units/*.cpp"
    )

add_library(APIMain ${SRCS})
target_include_directories(APIMain PUBLIC "${API_TOOLKIT_HEADERS_FOLDER}")