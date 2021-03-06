cmake_minimum_required(VERSION 3.22)
project(Maze VERSION 0.1.0)

include(CTest)
enable_testing()

file(GLOB_RECURSE main_srcs src/*.cpp)
add_executable(Maze ${main_srcs})

add_compile_definitions(_DEBUG)
if("${CMAKE_SYSTEM_NAME}" MATCHES "Windows")
	add_compile_definitions(WINDOWS)
endif()

target_precompile_headers(Maze PRIVATE src/maze.h)

add_subdirectory(third_party/glm EXCLUDE_FROM_ALL)
add_subdirectory(third_party/glfw EXCLUDE_FROM_ALL)
add_subdirectory(third_party/GLAD EXCLUDE_FROM_ALL)
add_subdirectory(third_party/stb_image EXCLUDE_FROM_ALL)

target_link_libraries(Maze PRIVATE glfw glm glad stb_image)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
