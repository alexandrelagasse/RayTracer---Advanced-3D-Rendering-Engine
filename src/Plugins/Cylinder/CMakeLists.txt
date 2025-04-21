cmake_minimum_required(VERSION 3.13)

target_include_directories(plugin_cylinder PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}")

target_sources(plugin_cylinder PRIVATE
        "${CMAKE_CURRENT_SOURCE_DIR}/Cylinder.cpp"
        )
