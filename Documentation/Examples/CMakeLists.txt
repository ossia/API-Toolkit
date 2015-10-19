file(GLOB_RECURSE SRCS *.cpp)

function(addAPIToolkitExample TESTNAME TESTSRCS)
        if(${Main_FOUND})
                add_executable(API_TOOLKIT_${TESTNAME}_example ${TESTSRCS})
                target_link_libraries(API_TOOLKIT_${TESTNAME}_example APIToolkitMain)
        endif()
endFunction()

addAPIToolkitExample(load_setup			"${CMAKE_CURRENT_SOURCE_DIR}/Setup/load_setup.cpp")
