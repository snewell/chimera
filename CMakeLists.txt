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

if(BUILD_TESTS)
    find_package(GTest REQUIRED)

    function(create_test name)
        add_executable(${name} ${ARGN})
        target_link_libraries(${name}
                                GTest::GTest
                                GTest::Main
                                chimera
                             )
        if(NOT SYSTEM_GTEST)
            target_link_libraries("${name}"
                                    Threads::Threads
                                 )
        endif()
        set_target_properties(${name} PROPERTIES
                                CXX_STANDARD 17
                                CXX_EXTENSIONS OFF
                             )
        target_include_directories(${name} PUBLIC
                                    $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/include_internal>
                                )
        add_test(${name} ${name} "--gtest_output=xml:${CMAKE_CURRENT_BINARY_DIR}/${name}_results.xml")
    endfunction()
else()
    function(create_test name)
        # do nothing
    endfunction()
endif()

add_subdirectory(battler)
add_subdirectory(item)
add_subdirectory(object)
add_subdirectory(stat)

set(chimera_sources
        ${battler_sources}
        ${item_sources}
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
                            $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include_internal>
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
            include/chimera/battler.hpp
            include/chimera/equipment.hpp
            include/chimera/identified_object.hpp
            include/chimera/item.hpp
            include/chimera/job.hpp
            include/chimera/named_object.hpp
            include/chimera/stat.hpp
            include/chimera/types.hpp
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
