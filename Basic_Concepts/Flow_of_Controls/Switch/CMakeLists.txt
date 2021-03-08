cmake_minimum_required(VERSION 3.17)

project(Basic_Concepts-Flow_of_Controls-Switch)

set(CMAKE_CXX_STANDARD 14)

# Files from `./src` directory
set(SRC
    )

set(TEST
    src/demo.cpp)


# Running learner side code
# Use PROJECT_NAME dependent names of targets for the plugin support to work correctly.
#add_executable(${PROJECT_NAME}-run ${SRC})


# Running tests
# Use PROJECT_NAME dependent names of targets for the plugin support to work correctly.
configure_test_target(${PROJECT_NAME}-run "${SRC}" ${TEST})