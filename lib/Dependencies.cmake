include(FetchContent)
set(FETCHCONTENT_QUIET OFF)

cmake_policy(SET CMP0135 NEW)

FetchContent_Declare(
    Unity
    GIT_REPOSITORY https://github.com/ThrowTheSwitch/Unity.git
    GIT_TAG master # or a specific version/tag
    SOURCE_DIR ${CMAKE_SOURCE_DIR}/lib/unity
)
FetchContent_MakeAvailable(Unity)

message(STATUS "Available targets: ${FetchContent_BASE_DIR}")

set(Test_Dependency unity)
