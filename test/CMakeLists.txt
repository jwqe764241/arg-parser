project(test)

add_executable(test test_main.cpp)
target_link_libraries(test PRIVATE catch program)