# source/ECS/CMakeLists.txt

set(ECS_SOURCE
    Private/ECS.cpp
)

add_library(ECS STATIC ${ECS_SOURCE})

target_include_directories(ECS PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}/Public
)