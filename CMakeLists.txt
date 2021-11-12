cmake_minimum_required(VERSION 3.18)
project(X-Action)

set(CMAKE_CXX_STANDARD 17)

find_package(OpenCV REQUIRED)

set(IMAGE_PATH ${CMAKE_SOURCE_DIR}/images)
add_compile_definitions(IMAGE_PATH="${IMAGE_PATH}")

include_directories(${OpenCV_INCLUDE_DIRS})

add_executable(DisplayImage main.cpp)

target_link_libraries(DisplayImage ${OpenCV_LIBS})