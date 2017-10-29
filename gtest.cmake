include(ExternalProject)

# This is really hacky, but seems to work.  It captures the important CMake
# internal variables (flags, compiler, etc.), then configures gtest with those
# same arguments.  It also adds the library and installation directories so
# the freshly built gtest binaries are found and used.
#
# There's probably a better way to do this.

# Modified from here: https://stackoverflow.com/questions/10205986/how-to-capture-cmake-command-line-arguments/10218582#10218582
get_cmake_property(cache_vars CACHE_VARIABLES)
foreach(cache_var ${cache_vars})
    if((cache_var MATCHES "CMAKE_.*_FLAGS") OR (cache_var MATCHES "CMAKE_.*_COMPILER"))
        get_property(cache_var_type CACHE ${cache_var} PROPERTY TYPE)
            if(cache_var_type STREQUAL "UNINITIALIZED")
                set(cache_var_type)
            else()
                set(cache_var_type :${cache_var_type})
            endif()
        set(gtest_cmake_args ${gtest_cmake_args} "-D${cache_var}${cache_var_type}=${${cache_var}}")
    endif()
endforeach()

ExternalProject_Add(googletest
                        GIT_REPOSITORY    "https://github.com/google/googletest.git"
                        GIT_TAG           "release-1.8.0"
                        SOURCE_DIR        "${CMAKE_CURRENT_BINARY_DIR}/googletest-src"
                        BINARY_DIR        "${CMAKE_CURRENT_BINARY_DIR}/googletest-build"
                        INSTALL_COMMAND   ""
                        TEST_COMMAND      ""
                        CMAKE_CACHE_ARGS  ${gtest_cmake_args}
                   )

link_directories("${CMAKE_CURRENT_BINARY_DIR}/googletest-build/googlemock/gtest")
include_directories("${CMAKE_CURRENT_BINARY_DIR}/googletest-src/googletest/include")
