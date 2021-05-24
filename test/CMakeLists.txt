cmake_minimum_required(VERSION 3.15)

project(test VERSION 1.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_executable(test main.cpp)

if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Debug)
endif()

#add_library(multify SHARED IMPORTED)
#add_library(add SHARED IMPORTED)

#target_include_directories(test PUBLIC ${PROJECT_SOURCE_DIR}/../multify/build/include)

#set_property(TARGET multify PROPERTY IMPORTED_LOCATION ${PROJECT_SOURCE_DIR}/../multify/build/lib/libmultify.so)
#set_property(TARGET add PROPERTY IMPORTED_LOCATION ${PROJECT_SOURCE_DIR}/../add/build/des/lib/libadd.so)

#target_link_libraries(test PRIVATE multify add)

#target_link_libraries(test PRIVATE ${PROJECT_SOURCE_DIR}/../multify/build/lib/libmultify.so
#				  ${PROJECT_SOURCE_DIR}/../add/build/des/lib/libadd.so)

#include(${PROJECT_SOURCE_DIR}/../add/build/des/lib/cmake/add_target_debug.cmake)
#include(${PROJECT_SOURCE_DIR}/../add/build/des/lib/cmake/add_target_release.cmake)
#include(${PROJECT_SOURCE_DIR}/../multify/build/lib/cmake/multify_target.cmake)

find_package(multify PATHS ${PROJECT_SOURCE_DIR}/../multify/build/lib/cmake)
target_link_libraries(test PRIVATE ${multify_LIBS})
