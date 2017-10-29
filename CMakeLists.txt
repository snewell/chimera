cmake_minimum_required(VERSION 3.8)
cmake_policy(VERSION 3.8)

project("chimera"
        LANGUAGES
            CXX
        VERSION 0.1.0
       )

include(GNUInstallDirs)

enable_testing()

option(BUILD_TESTS  "Build unit tests" ON)
option(SYSTEM_GTEST "Use system-wide gtest instead of building locally" ON)

if(BUILD_TESTS)
    if(SYSTEM_GTEST)
        find_package(GTest REQUIRED)
        set(GTEST "GTest::GTest")
        set(GTEST_MAIN "GTest::Main")
    else()
        include(gtest.cmake)

        add_subdirectory("${CMAKE_CURRENT_BINARY_DIR}/googletest-src"
                         "${CMAKE_CURRENT_BINARY_DIR}/googletest-build"
                         EXCLUDE_FROM_ALL
                        )
        set(GTEST "gtest")
        set(GTEST_MAIN "gtest_main")
    endif()

    function(create_test name)
        add_executable(${name} ${ARGN})
        target_link_libraries(${name}
                                ${GTEST}
                                ${GTEST_MAIN}
                                chimera
                             )
        set_target_properties(${name} PROPERTIES
                                CXX_STANDARD 17
                                CXX_EXTENSIONS OFF
                             )
        add_test(${name} ${name} "--gtest_output=xml:${CMAKE_CURRENT_BINARY_DIR}/${name}_results.xml")
    endfunction()
else()
    function(create_test name)
        # do nothing
    endfunction()
endif()

add_subdirectory(object)
add_subdirectory(stat)

set(chimera_sources
        ${object_sources}
        ${stat_sources}
   )
add_library(chimera SHARED
                "${chimera_sources}"
           )
add_library(chimera-static STATIC
                "${chimera_sources}"
           )
set_target_properties(
                      chimera
                      chimera-static
                      PROPERTIES
                      VERSION ${PROJECT_VERSION}
                      SOVERSION ${PROJECT_VERSION_MAJOR}
                      CXX_STANDARD 17
                      CXX_EXTENSIONS OFF
                     )
target_include_directories(chimera PUBLIC
                            $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
                            $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>
                          )
target_include_directories(chimera-static PUBLIC
                            $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
                            $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>
                          )

install(TARGETS
            chimera
            chimera-static
        EXPORT ChimeraConfig
        ARCHIVE DESTINATION "${CMAKE_INSTALL_LIBDIR}"
        LIBRARY DESTINATION "${CMAKE_INSTALL_LIBDIR}"
        RUNTIME DESTINATION "${CMAKE_INSTALL_BINDIR}"
       )

install(FILES
            include/chimera/identified_object.hpp
            include/chimera/named_object.hpp
            include/chimera/stat.hpp
        DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/chimera
       )

export(TARGETS
            chimera
            chimera-static
        NAMESPACE Chimera::
        FILE "${CMAKE_CURRENT_BINARY_DIR}/ChimeraConfig.cmake"
      )
install(EXPORT
            ChimeraConfig
        DESTINATION "${CMAKE_INSTALL_DATADIR}/Chimera/cmake"
        NAMESPACE Chimera::
       )
