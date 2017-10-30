set(item_sources
        "${CMAKE_CURRENT_SOURCE_DIR}/item.cpp"
    PARENT_SCOPE
   )

create_test(item_test
                "${CMAKE_CURRENT_SOURCE_DIR}/item_test.cpp"
           )
