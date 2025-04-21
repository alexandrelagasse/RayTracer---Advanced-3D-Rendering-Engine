cmake_minimum_required(VERSION 3.13)
project(
        Raytracer
        VERSION 1.0
        DESCRIPTION "Epitech raytracer project"
        LANGUAGES CXX
)

##############################################################################
# Raytracer binary
add_executable(raytracer)
set_target_properties(raytracer PROPERTIES
        CXX_STANDARD 20
        COMPILE_FLAGS "-fno-gnu-unique"
        )

add_custom_command(TARGET raytracer PRE_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${CMAKE_SOURCE_DIR}/plugins $<TARGET_FILE_DIR:raytracer>/plugins
        )

# add libconfig++ and SFML
find_package(PkgConfig REQUIRED)
pkg_check_modules(LIBCONFIG++ REQUIRED IMPORTED_TARGET libconfig++)
find_package(SFML 2.5 COMPONENTS graphics window system REQUIRED)

target_link_libraries(raytracer PRIVATE sfml-graphics sfml-window sfml-system PkgConfig::LIBCONFIG++ ${CMAKE_DL_LIBS} pthread)

##############################################################################
# Plugin .so libs
add_library(plugin_perspective_camera SHARED)
set_target_properties(plugin_perspective_camera PROPERTIES
        CXX_STANDARD 20
        COMPILE_FLAGS "-fno-gnu-unique"
        PREFIX ""
        LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/plugins"
        )

add_library(plugin_plane SHARED)
set_target_properties(plugin_plane PROPERTIES
        CXX_STANDARD 20
        COMPILE_FLAGS "-fno-gnu-unique"
        PREFIX ""
        LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/plugins"
        )

add_library(plugin_point_light SHARED)
set_target_properties(plugin_point_light PROPERTIES
        CXX_STANDARD 20
        COMPILE_FLAGS "-fno-gnu-unique"
        PREFIX ""
        LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/plugins"
        )

add_library(plugin_directional_light SHARED)
set_target_properties(plugin_directional_light PROPERTIES
        CXX_STANDARD 20
        COMPILE_FLAGS "-fno-gnu-unique"
        PREFIX ""
        LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/plugins"
        )

add_library(plugin_simple_material SHARED)
set_target_properties(plugin_simple_material PROPERTIES
        CXX_STANDARD 20
        COMPILE_FLAGS "-fno-gnu-unique"
        PREFIX ""
        LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/plugins"
        )

add_library(plugin_sphere SHARED)
set_target_properties(plugin_sphere PROPERTIES
        CXX_STANDARD 20
        COMPILE_FLAGS "-fno-gnu-unique"
        PREFIX ""
        LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/plugins"
        )

add_library(plugin_cone SHARED)
set_target_properties(plugin_cone PROPERTIES
        CXX_STANDARD 20
        COMPILE_FLAGS "-fno-gnu-unique"
        PREFIX ""
        LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/plugins"
        )

add_library(plugin_cylinder SHARED)
set_target_properties(plugin_cylinder PROPERTIES
        CXX_STANDARD 20
        COMPILE_FLAGS "-fno-gnu-unique"
        PREFIX ""
        LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/plugins"
        )

add_library(plugin_triangle SHARED)
set_target_properties(plugin_triangle PROPERTIES
        CXX_STANDARD 20
        COMPILE_FLAGS "-fno-gnu-unique"
        PREFIX ""
        LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/plugins"
        )

add_library(plugin_plane_material SHARED)
set_target_properties(plugin_plane_material PROPERTIES
        CXX_STANDARD 20
        COMPILE_FLAGS "-fno-gnu-unique"
        PREFIX ""
        LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/plugins"
        )
add_library(plugin_simple_skybox SHARED)
set_target_properties(plugin_simple_skybox PROPERTIES
        CXX_STANDARD 20
        COMPILE_FLAGS "-fno-gnu-unique"
        PREFIX ""
        LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/plugins"
        )

add_subdirectory(src)
