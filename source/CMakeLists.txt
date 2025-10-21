# source/CMakeLists.txt

add_subdirectory(Application)
add_subdirectory(Entity)
add_subdirectory(ECS)
# add_subdirectory(gam)

add_dependencies(Application Entity) 

