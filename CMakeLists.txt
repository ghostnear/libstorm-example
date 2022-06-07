cmake_minimum_required(VERSION 3.9)

# Project metadata
project(exampleApp)

# Project output path for install()
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ../bin/)

# Project dependencies
add_subdirectory(external)

# Project core
add_executable(
    exampleApp
    "src/main.cpp"
    "src/states/mainState.cpp"
    "src/systems/rectdraw.cpp"
)

set_property(TARGET exampleApp PROPERTY CXX_STANDARD 14)

target_link_libraries(
    exampleApp
    PRIVATE
        libStorm
)

# Install executables
install(TARGETS exampleApp DESTINATION bin)