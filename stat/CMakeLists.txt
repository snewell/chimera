set(stat_sources
        "${CMAKE_CURRENT_SOURCE_DIR}/stat.cpp"
        "${CMAKE_CURRENT_SOURCE_DIR}/stat_source.cpp"
    PARENT_SCOPE
   )

create_test(stat_test
                "${CMAKE_CURRENT_SOURCE_DIR}/basestat_test.cpp"
                "${CMAKE_CURRENT_SOURCE_DIR}/complexstat_test.cpp"
                "${CMAKE_CURRENT_SOURCE_DIR}/statsource_test.cpp"
           )
