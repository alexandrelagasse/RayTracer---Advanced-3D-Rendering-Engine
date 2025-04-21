cmake_minimum_required(VERSION 3.13)

target_include_directories(plugin_simple_skybox PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}")
target_include_directories(raytracer PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}")

target_sources(plugin_simple_skybox PRIVATE
        "${CMAKE_CURRENT_SOURCE_DIR}/Skybox.cpp"
        )

target_sources(raytracer PRIVATE
        "${CMAKE_CURRENT_SOURCE_DIR}/Skybox.cpp"
        )
