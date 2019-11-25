project(test)

add_executable(test.exe test_main.cpp)
target_link_libraries(test.exe PRIVATE catch program)