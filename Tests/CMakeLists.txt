cmake_minimum_required(VERSION 3.0)
project(APIToolkitTests)

include_directories("${API_TOOLKIT_IMPL_FOLDER}/Main/Sources")

find_package(Qt5 5.4 REQUIRED COMPONENTS Core Test)

set(CMAKE_AUTOMOC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

if (COVERALLS)
    get_property(MAIN_API_SRCS TARGET APIMain PROPERTY SOURCES)
    coveralls_setup("${MAIN_API_SRCS}" ON)
endif()
function(addAPIToolkitQtTest TESTNAME TESTSRCS)
    if(${Main_FOUND})
        add_executable(Main_${TESTNAME} ${TESTSRCS})
        target_link_libraries(Main_${TESTNAME} Qt5::Core Qt5::Test APIToolkitMain)
        add_test(NAME Main_target_${TESTNAME} COMMAND Main_${TESTNAME})
    endif()
endFunction()

addAPIToolkitQtTest(APIProjectTest              "${CMAKE_CURRENT_SOURCE_DIR}/Setup/ProjectTest.cpp")
addAPIToolkitQtTest(APINetworkTest              "${CMAKE_CURRENT_SOURCE_DIR}/Setup/NetworkTest.cpp")
addAPIToolkitQtTest(APIScoreTest              "${CMAKE_CURRENT_SOURCE_DIR}/Setup/ScoreTest.cpp")

include(CTest)
