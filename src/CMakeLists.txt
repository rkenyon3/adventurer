cmake_minimum_required(VERSION 3.15)

configure_file(config.h.in config.h)

add_executable(adventurer main.cpp manager.cpp presenter.cpp text.cpp game_state.cpp game_states/beginning_state.cpp game_states/lost_state.cpp)
target_include_directories(adventurer PUBLIC 
						   ${PROJECT_SOURCE_DIR}/game_states
						   ${PROJECT_BINARY_DIR}/src 
						   ${PROJECT_SOURCE_DIR} 
						   )

target_link_libraries(adventurer PUBLIC)

