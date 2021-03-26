cmake_minimum_required(VERSION 3.17)
project(vulkantest)

set(CMAKE_CXX_STANDARD 14)

file(GLOB_RECURSE sources RELATIVE ${CMAKE_SOURCE_DIR} "src/*.cpp")
add_executable(vulkantest ${sources})

# find_package(OpenGL REQUIRED)
# list(APPEND INCLUDE_DIRS ${OPENGL_INCLUDE_DIR})
# target_link_libraries(DoubleShift ${OPENGL_gl_LIBRARY})

# Load Vulkan
find_library(Vulkan REQUIRED)
target_link_libraries(vulkantest ${Vulkan_LIBRARIES})
list(APPEND INCLUDE_DIRS "${Vulkan_INCLUDE_DIR}")

# Load GLAD
# add_subdirectory(lib/glad)
# target_link_libraries(vulkantest glad)

# Load GLFW (Window/Context Library)
set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)

add_subdirectory(lib/glfw)
target_link_libraries(vulkantest glfw)
list(APPEND INCLUDE_DIRS "${PROJECT_SOURCE_DIR}/lib/glfw/include")

# Load GLM (Math Library)
list(APPEND INCLUDE_DIRS "${PROJECT_SOURCE_DIR}/lib/glm")

# Include directories
target_include_directories(vulkantest PUBLIC "${PROJECT_BINARY_DIR}" ${INCLUDE_DIRS})
target_compile_definitions(vulkantest PRIVATE GLFW_INCLUDE_VULKAN)
