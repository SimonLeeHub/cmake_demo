cmake_minimum_required(VERSION 3.15)

project(multify VERSION 1.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Debug)
endif()

find_package(add REQUIRED PATHS ${PROJECT_SOURCE_DIR}/../add/build/des/lib/cmake/)

add_library(multify SHARED multify.cpp)

target_include_directories(multify PUBLIC $<BUILD_INTERFACE:${PROJECT_BINARY_DIR}> $<INSTALL_INTERFACE:include>)
target_link_libraries(multify PUBLIC ${add_LIBS})

include(GenerateExportHeader)
generate_export_header(multify EXPORT_MACRO_NAME MULTIFY_EXPORT)

install(FILES multify.hpp ${PROJECT_BINARY_DIR}/multify_export.h DESTINATION include)

install(TARGETS multify EXPORT multify_target_debug CONFIGURATIONS Debug DESTINATION lib/debug)
install(TARGETS multify EXPORT multify_target_release CONFIGURATIONS Release DESTINATION lib/release)

install(EXPORT multify_target_debug NAMESPACE multify::debug:: FILE multify_target_debug.cmake DESTINATION lib/cmake)
install(EXPORT multify_target_release NAMESPACE multify::release:: FILE multify_target_release.cmake DESTINATION lib/cmake)

set(multify_LIBS optimized multify::release::multify debug multify::debug::multify ${add_LIBS})

include(CMakePackageConfigHelpers)
configure_package_config_file(${CMAKE_CURRENT_SOURCE_DIR}/multify_config.cmake.in "${CMAKE_CURRENT_BINARY_DIR}/multify-config.cmake" INSTALL_DESTINATION lib/cmake)
install(FILES "${CMAKE_CURRENT_BINARY_DIR}/multify-config.cmake" DESTINATION lib/cmake)
