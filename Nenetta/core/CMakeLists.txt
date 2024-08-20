set(TARGET nenetta-core)

file(GLOB_RECURSE   core-sources    ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp
                                    ${CMAKE_CURRENT_SOURCE_DIR}/*.hpp
                                    )

add_library(${TARGET}   INTERFACE)
target_include_directories(${TARGET}    INTERFACE   ${PROJECT_SOURCE_DIR}/include)