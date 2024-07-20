target_sources(${PROJECT_NAME}
    PRIVATE Main.cpp)

target_include_directories(${PROJECT_NAME}
    PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})

add_subdirectory(Board)
add_subdirectory(Spawn)
add_subdirectory(Convert)
add_subdirectory(Check)
add_subdirectory(Print)
add_subdirectory(Application)
add_subdirectory(Scene)
add_subdirectory(InputHandle)
