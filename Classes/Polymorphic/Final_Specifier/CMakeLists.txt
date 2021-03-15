cmake_minimum_required(VERSION 3.17)

project(Classes-Object_Oriental-Final_and_Override_Specifier)

set(CMAKE_CXX_STANDARD 14)

# Files from `./src` directory
set(SRC
        src/main.cpp)


# Running learner side code
# Use PROJECT_NAME dependent names of targets for the plugin support to work correctly.
#add_executable(${PROJECT_NAME}-run ${SRC})

configure_test_target(${PROJECT_NAME}-run "" SRC)