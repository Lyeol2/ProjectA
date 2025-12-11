# source/ECS/CMakeLists.txt


add_library(ECS)

target_sources(ECS
    PRIVATE
        Private/ECS.cpp
        Private/World.cpp
        Private/Archetype.cpp
        Private/Signature.cpp
        Private/Component.cpp
    PUBLIC
        FILE_SET HEADERS
        BASE_DIRS Public
        FILES
            Public/World.h
            Public/Archetype.h
            Public/Component.h
            Public/Signature.h
            Public/Chunk.h
            Public/Entity.h

)



target_include_directories(ECS PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}/Include
)