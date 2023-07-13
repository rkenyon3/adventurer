cmake_minimum_required(VERSION 3.15)

project(adventurer VERSION 0.1)

configure_file(config.h.in config.h)
add_executable(adventurer main.cpp manager.cpp presenter.cpp text.cpp)
target_include_directories(adventurer PUBLIC ${PROJECT_BINARY_DIR} ${PROJECT_SOURCE_DIR})
target_link_libraries(adventurer PUBLIC)

