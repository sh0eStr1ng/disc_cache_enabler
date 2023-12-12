### Build Target
#
# - Get all the source files found in the current subdirectory
# - Add a library build target with the source files that were found

file(GLOB PROJECT_SOURCE_FILES *.c *.cpp *.cxx)

add_library(disc_cache_enabler SHARED ${PROJECT_SOURCE_FILES})

### Dependencies
#
# - Get the include directory if applicable
# - Tell CMake to include the directory that was found

set(INCLUDE_DIRECTORY ${PROJECT_SOURCE_DIR}/include)

target_include_directories(disc_cache_enabler PRIVATE ${INCLUDE_DIRECTORY})
