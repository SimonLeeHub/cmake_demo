cmake_minimum_required(VERSION 3.15)

project(add VERSION 1.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Debug)
endif()

message(${CMAKE_INSTALL_PREFIX})

add_library(add SHARED add.cpp)

target_include_directories(add PUBLIC $<BUILD_INTERFACE:${CMAKE_BINARY_DIR}> $<INSTALL_INTERFACE:include>)

include (GenerateExportHeader) 
generate_export_header(add EXPORT_MACRO_NAME EXPORT)

list(APPEND INSTALL_FILES add.hpp ${CMAKE_BINARY_DIR}/add_export.h)
install(FILES ${INSTALL_FILES} DESTINATION include)

install(TARGETS add EXPORT add_target_debug CONFIGURATIONS Debug DESTINATION lib/debug)
install(TARGETS add EXPORT add_target_release CONFIGURATIONS Release DESTINATION lib/release)

install(EXPORT add_target_debug NAMESPACE add::debug:: FILE add_target_debug.cmake DESTINATION lib/cmake)
install(EXPORT add_target_release NAMESPACE add::release:: FILE add_target_release.cmake DESTINATION lib/cmake)

set(add_LIBS optimized add::release::add debug add::debug::add)

include(CMakePackageConfigHelpers)
configure_package_config_file(${CMAKE_CURRENT_SOURCE_DIR}/add_config.cmake.in "${CMAKE_CURRENT_BINARY_DIR}/add-config.cmake" INSTALL_DESTINATION lib/cmake)
install(FILES "${CMAKE_CURRENT_BINARY_DIR}/add-config.cmake" DESTINATION lib/cmake)


