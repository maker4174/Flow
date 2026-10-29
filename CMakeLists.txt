cmake_minimum_required(VERSION 3.16)

project(Flow2D CXX C)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

file(GLOB_RECURSE CPP_SOURCES "src/*.cpp")

set(BUILD_SHARED_LIBS ON CACHE BOOL "" FORCE)
set(SDL_SHARED ON CACHE BOOL "" FORCE )
set(SDL_STATIC OFF CACHE BOOL "" FORCE)
set(SDL_TESTS OFF CACHE BOOL "" FORCE)
set(SDL_INSTALL OFF CACHE BOOL "" FORCE)

add_subdirectory(vendor/SDL)

add_executable(Flow ${CPP_SOURCES} imp_libs/glad.c)

target_include_directories(Flow PRIVATE

  ${CMAKE_SOURCE_DIR}/src

  ${CMAKE_SOURCE_DIR}/src/Utility
  ${CMAKE_SOURCE_DIR}/src/Utility/Core
  ${CMAKE_SOURCE_DIR}/src/Utility/Core/Math
  ${CMAKE_SOURCE_DIR}/src/Utility/Core/Platform
  ${CMAKE_SOURCE_DIR}/src/Utility/Core/Graphics

  ${CMAKE_SOURCE_DIR}/src/Shapes
  ${CMAKE_SOURCE_DIR}/src/Physics

  ${CMAKE_SOURCE_DIR}/imp_libs
  ${CMAKE_SOURCE_DIR}/imp_libs/libs/include
  ${CMAKE_SOURCE_DIR}/imp_libs/libs/include/KHR

  ${CMAKE_SOURCE_DIR}/imp_libs/glm

)

target_link_libraries(Flow PRIVATE SDL3::SDL3)
