cmake_minimum_required(VERSION 3.15)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

project(aiush)

if (NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE "Debug")
endif()

set(EXECUTABLE aiush)
set(UTILLIB    aiushutil)


add_library("${UTILLIB}" STATIC
  lib/history.cpp
  lib/match_function.cpp
  lib/recommend.cpp
)

add_executable("${EXECUTABLE}"
  src/main.cpp
)

target_include_directories("${EXECUTABLE}" PUBLIC include)
target_include_directories("${UTILLIB}" PUBLIC include)

target_link_libraries("${EXECUTABLE}" PRIVATE "${UTILLIB}")

target_compile_options("${EXECUTABLE}" PRIVATE "-Wall")
target_compile_options("${EXECUTABLE}" PRIVATE "$<$<CONFIG:Debug>:-DDEBUG;-g;>")
target_compile_options("${EXECUTABLE}" PRIVATE "$<$<CONFIG:Release>:-O3>")


add_subdirectory(./tests)
