#ifndef GAME_STATE_H
#define GAME_STATE_H

#include <vector>

#include "player_response.h"
#include "presenter.h"
#include "text.h"

class GameState
{
public:
	GameState();
	GameState get_next_game_state();
	void process_game_state();
	~GameState();

private:
	GameState * next_game_state;
};

#endif
