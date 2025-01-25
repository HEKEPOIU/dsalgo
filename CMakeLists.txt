cmake_minimum_required(VERSION 3.10)
project(dsalgo
    LANGUAGES   C # need this to let clangd can auto import current.
)

set(CMAKE_C_STANDARD 11)
include(${CMAKE_SOURCE_DIR}/lib/Dependencies.cmake)
add_compile_options(-O2)

option(BUILD_TEST "Is Test enable" ON)
if (${BUILD_TEST})
    enable_testing() # Must enable to let ctest work.
    add_subdirectory(test)
endif()



add_executable(${CMAKE_PROJECT_NAME} src/main.c)

target_include_directories(${CMAKE_PROJECT_NAME} SYSTEM PRIVATE ${CMAKE_SOURCE_DIR}/include)


