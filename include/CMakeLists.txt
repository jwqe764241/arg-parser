project(program)

set(INCLUDES 
${CMAKE_CURRENT_SOURCE_DIR} 
${CMAKE_CURRENT_SOURCE_DIR}/src
)

add_library(program INTERFACE)

target_include_directories(program INTERFACE ${INCLUDES})