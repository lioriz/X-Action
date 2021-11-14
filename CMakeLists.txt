cmake_minimum_required(VERSION 3.10)
project(X-Action)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

find_package(OpenCV REQUIRED)

set(IMAGE_PATH_IN ${CMAKE_SOURCE_DIR}/images)
add_compile_definitions(IMAGE_PATH_IN="${IMAGE_PATH_IN}")

set(IMAGE_PATH_OUT ${CMAKE_SOURCE_DIR}/images_out)
add_compile_definitions(IMAGE_PATH_OUT="${IMAGE_PATH_OUT}")
add_custom_target(make-dir-image-out ALL COMMAND ${CMAKE_COMMAND} -E make_directory ${IMAGE_PATH_OUT})

include_directories(${OpenCV_INCLUDE_DIRS}
        include
        )

add_executable(X-Action mainX-Action.cpp
        src/imageActions.cpp
        )

target_link_libraries(X-Action ${OpenCV_LIBS}  -lstdc++fs  pthread)

add_executable(PythonConversion mainPythonConversion.cpp
        src/imageActions.cpp
        )

target_link_libraries(PythonConversion ${OpenCV_LIBS}  -lstdc++fs pthread)