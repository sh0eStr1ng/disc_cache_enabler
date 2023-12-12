### CMake Setup
#
# - Set the minimum CMake version required to build the project

cmake_minimum_required(VERSION 3.26.4)

### Project Setup
#
# - Initialize the project
# - Enable the C++23 standard
# - Force 32-bit compilation and generation

project(FalloutNewVegasKit VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -m32")

### Subdirectory Setup
#
# - Add the subdirectory containing the project sources

add_subdirectory(src)
