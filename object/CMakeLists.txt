set(object_sources
        "${CMAKE_CURRENT_SOURCE_DIR}/identified_object.cpp"
        "${CMAKE_CURRENT_SOURCE_DIR}/named_object.cpp"
    PARENT_SCOPE
   )

create_test(object_test
                "${CMAKE_CURRENT_SOURCE_DIR}/identifiedobject_test.cpp"
                "${CMAKE_CURRENT_SOURCE_DIR}/namedobject_test.cpp"
           )
