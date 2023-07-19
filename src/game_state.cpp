#include "game_state.h"

GameState::GameState(void)
{
	this->next_game_state = nullptr;
}

GameState * GameState::get_next_game_state()
{
	return this->next_game_state;
}

void GameState::process_game_state()
{

}

GameState::~GameState()
{

}
