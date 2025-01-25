PROJECT(${CMAKE_PROJECT_NAME}_test)

set(TEST_SOURCES
    ./test_array.c
    ./test_link_list.c
    ./test_list.c
    ./test_ll_stack.c
)

foreach(TEST_FILE ${TEST_SOURCES})
    get_filename_component(TEST_NAME ${TEST_FILE} NAME_WE)
    add_executable(${TEST_NAME} ${TEST_FILE})

    target_include_directories(${TEST_NAME}
        SYSTEM PRIVATE
        ${CMAKE_SOURCE_DIR}/include
    )

    target_link_libraries(${TEST_NAME}
        PRIVATE
        ${Test_Dependency}
    )

    add_test(NAME ${TEST_NAME} COMMAND ${TEST_NAME})
endforeach()

