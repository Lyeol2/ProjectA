# source/Application/CMakeLists.txt

set(APPLICATION_SOURCE
    Private/Application.cpp
)

add_library(Application STATIC ${APPLICATION_SOURCE})

target_include_directories(Application PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}/Public
)