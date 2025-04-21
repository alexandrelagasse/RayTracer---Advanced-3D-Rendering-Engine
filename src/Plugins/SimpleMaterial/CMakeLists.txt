cmake_minimum_required(VERSION 3.13)

target_include_directories(plugin_simple_material PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}")

target_sources(plugin_simple_material PRIVATE
        "${CMAKE_CURRENT_SOURCE_DIR}/SimpleMaterial.cpp"
        )
