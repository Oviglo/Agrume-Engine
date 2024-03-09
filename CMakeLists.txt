cmake_minimum_required(VERSION 3.29)
project(agrume-engine VERSION 1.0.0)


add_executable(agrume-engine "")
target_sources(agrume-engine
  PRIVATE
    "${CMAKE_CURRENT_SOURCE_DIR}/src/Main/Main.cpp"
)
include(cmake/Sources.cmake)
include(cmake/Modules.cmake)