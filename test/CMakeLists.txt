# test/CMakeList.txt

project("TEST")


add_executable(TEST Private/main.cpp)

target_sources(TEST
    PRIVATE
        
    PUBLIC
        FILE_SET HEADERS
        BASE_DIRS Public
        FILES
            Public/ECS/TEST_World.h
)

target_include_directories(TEST PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}/lib/googletest/googletest/include
    ${CMAKE_CURRENT_LIST_DIR}/lib/googletest/googlemock/include)


target_link_libraries(TEST PRIVATE 
    ${CMAKE_CURRENT_LIST_DIR}/lib/googletest/build/lib/libgtest.a
    ${CMAKE_CURRENT_LIST_DIR}/lib/googletest/build/lib/libgmock.a
    pthread
)

    
target_link_libraries(TEST 
    PRIVATE Application Entity ECS)

    

