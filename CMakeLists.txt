cmake_minimum_required(VERSION 3.28)
project(FlappyBird LANGUAGES CXX)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

find_package(SFML 3.0 COMPONENTS Graphics REQUIRED)

file(GLOB SOURCES "src/*.cpp")

add_executable(main ${SOURCES})
target_compile_features(main PRIVATE cxx_std_23)
target_include_directories(main PRIVATE include)
target_link_libraries(main PRIVATE SFML::Graphics)

set(ROOT_DIR ${CMAKE_SOURCE_DIR})
target_compile_definitions(main PRIVATE ROOT_DIR="${ROOT_DIR}/")