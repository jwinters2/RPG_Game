cmake_minimum_required(VERSION 2.8)

project(RPG_Game)

set(CMAKE_BINARY_DIR ${CMAKE_SOURCE_DIR}/bin)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR})
set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR})
set(CMAKE_BUILD_DIRECTORY ${CMAKE_SOURCE_DIR}/build)

set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_CXX_STANDARD 11)

find_package(OpenGL)

set(GLFW_INCLUDE_PATH "" CACHE PATH     "where is GLFW/glfw3.h?")
set(GLFW_LIBRARY      "" CACHE FILEPATH "where is libglfw.a?")

set(GLEW_INCLUDE_PATH "" CACHE PATH     "where is GL/glew.h?")
set(GLEW_LIBRARY      "" CACHE FILEPATH "where is libglew.a?")

set(
  RPG_HEADER_FILES
  src/GraphicsManager.h
  src/Camera.h
  src/Math.h
  src/ObjModel.h
  src/EntityManager.h
  src/Entity.h
  src/Object.h
)

set(
  RPG_SOURCE_FILES
  src/GraphicsManager.cpp
  src/Camera.cpp
  src/Math.cpp
  src/ObjModel.cpp
  src/EntityManager.cpp
  src/Entity.cpp
  src/Object.cpp
)

include_directories(
  ${PROJECT_SOURCE_DIR}
  ${GLFW_INCLUDE_PATH}
  ${GLEW_INCLUDE_PATH}
)

add_executable(
  RPG_Game
  ${CMAKE_SOURCE_DIR}/main.cpp
  ${RPG_HEADER_FILES}
  ${RPG_SOURCE_FILES}
)

target_link_libraries(
  RPG_Game
  -lGL
  -lGLEW
  -lglfw
)
