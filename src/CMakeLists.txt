### Build Target
#
# - Get all the source files found in the current subdirectory
# - Add a library build target with the source files that were found

file(GLOB PROJECT_SOURCE_FILES *.c *.cpp *.cxx)

add_library(disc_cache_enabler SHARED ${PROJECT_SOURCE_FILES})

### Dependencies
#
# - Create a new value for the include directory
# - Include the include directory if it was found

set(INCLUDE_DIRECTORY ${PROJECT_SOURCE_DIR}/include)

if (EXISTS ${INCLUDE_DIRECTORY})
    target_include_directories(disc_cache_enabler PRIVATE ${INCLUDE_DIRECTORY})
endif ()
