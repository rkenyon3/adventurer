cmake_minimum_required(VERSION 3.15)

configure_file(config.h.in config.h)

# aux_source_directory is being abused slightly here, to save having to add every game state explicitly.
# This shouldn't be too much of a problem however, as the build command being used regenerates the cmake
# files every time
aux_source_directory(game_states, GAME_STATES) 

add_executable(adventurer main.cpp manager.cpp presenter.cpp text.cpp game_state.cpp ${GAME_STATES})
target_include_directories(adventurer PUBLIC 
							${PROJECT_BINARY_DIR}/src 
							${PROJECT_SOURCE_DIR} 
							${PROJECT_SOURCE_DIR}/game_states
							)
target_link_libraries(adventurer PUBLIC)

