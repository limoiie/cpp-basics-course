cmake_minimum_required(VERSION 3.17)

project(Expressions-Value-Value_is_also_Expressions)

set(CMAKE_CXX_STANDARD 14)

# Files from `./src` directory
set(SRC
    src/demo.cpp)


# Running learner side code
# Use PROJECT_NAME dependent names of targets for the plugin support to work correctly.
#add_executable(${PROJECT_NAME}-run ${SRC})

configure_test_target(${PROJECT_NAME}-run "" ${SRC})