set(money_sources
        "${CMAKE_CURRENT_SOURCE_DIR}/currency.cpp"
        "${CMAKE_CURRENT_SOURCE_DIR}/money.cpp"
    PARENT_SCOPE
   )

create_test(money_test
                "${CMAKE_CURRENT_SOURCE_DIR}/currency_test.cpp"
                "${CMAKE_CURRENT_SOURCE_DIR}/money_test.cpp"
           )
