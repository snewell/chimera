set(battler_sources
        "${CMAKE_CURRENT_SOURCE_DIR}/battler.cpp"
        "${CMAKE_CURRENT_SOURCE_DIR}/job.cpp"
    PARENT_SCOPE
   )

create_test(battler_test
                "${CMAKE_CURRENT_SOURCE_DIR}/battler_test.cpp"
                "${CMAKE_CURRENT_SOURCE_DIR}/job_test.cpp"
           )
