cmake_minimum_required(VERSION 3.17)

project(Basic_Concepts-Classes-A_More_Real_Class)

set(CMAKE_CXX_STANDARD 14)

# Files from `./src` directory
set(SRC
        src/main.cpp
        src/Address.cpp
        src/create_dummy_address.cpp)


# Running learner side code
# Use PROJECT_NAME dependent names of targets for the plugin support to work correctly.
add_executable(${PROJECT_NAME}-run ${SRC})