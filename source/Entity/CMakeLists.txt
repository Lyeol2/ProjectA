# source/Entity/CMakeLists.txt

set(ENTITY_SOURCE
    Private/Entity.cpp
)

add_library(Entity STATIC ${ENTITY_SOURCE})

target_include_directories(Entity PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}/Public
)