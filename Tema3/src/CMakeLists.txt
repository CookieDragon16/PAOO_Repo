cmake_minimum_required(VERSION 3.10)

# set the project name and version
project(tema3 VERSION 1.0)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_subdirectory(FileManager)

add_executable(main main.cpp)

target_link_libraries(main PUBLIC FileManager pthread stdc++fs)

target_include_directories(main PUBLIC
                        "${PROJECT_SOURCE_DIR}/FileManager"
)