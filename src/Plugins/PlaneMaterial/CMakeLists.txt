cmake_minimum_required(VERSION 3.13)

target_include_directories(plugin_plane_material PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}")

target_sources(plugin_plane_material PRIVATE
        "${CMAKE_CURRENT_SOURCE_DIR}/PlaneMaterial.cpp"
        )
