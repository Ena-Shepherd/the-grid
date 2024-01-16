#

# Author: Yannis STEFANELLI

# Creation Date: 26-02-2023 16:04:32

# Description :

# This is the project configuration file

# Allows to build the project on any platform

#

cmake_minimum_required(VERSION 3.11)

# Executable name
set(PROJECT_NAME
    tron
)

project(${PROJECT_NAME} CXX)

# Source files
file(GLOB SOURCES "src/*.cpp")

#SFML lib location
set( CMAKE_SFML_DIR
    ${CMAKE_CURRENT_SOURCE_DIR}/SFML-2.5.1
)

include_directories(${CMAKE_SFML_DIR}/include)
link_directories(${CMAKE_SFML_DIR}/lib)

add_executable(${PROJECT_NAME} ${SOURCES})
target_link_libraries(${PROJECT_NAME} sfml-graphics sfml-window sfml-system)