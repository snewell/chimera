set(item_sources
        "${CMAKE_CURRENT_SOURCE_DIR}/equipment.cpp"
        "${CMAKE_CURRENT_SOURCE_DIR}/fixed_inventory.cpp"
        "${CMAKE_CURRENT_SOURCE_DIR}/item.cpp"
        "${CMAKE_CURRENT_SOURCE_DIR}/stacked_inventory.cpp"
    PARENT_SCOPE
   )

create_test(item_test
                "${CMAKE_CURRENT_SOURCE_DIR}/equipment_test.cpp"
                "${CMAKE_CURRENT_SOURCE_DIR}/fixed_inventory_test.cpp"
                "${CMAKE_CURRENT_SOURCE_DIR}/item_test.cpp"
           )
