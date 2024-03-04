cmake_minimum_required(VERSION 3.20)

project(ltlib)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(SOURCE_DIR "${CMAKE_SOURCE_DIR}/src")
file(GLOB SOURCES "${SOURCE_DIR}/*.cc")

foreach(SOURCE_PATH ${SOURCES})
    get_filename_component(EXECUTABLE_NAME ${SOURCE_PATH} NAME_WE)
    add_executable(${EXECUTABLE_NAME} ${SOURCE_PATH})
endforeach()


