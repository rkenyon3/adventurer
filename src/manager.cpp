#include "manager.h"

using namespace std;

Manager::Manager()
{
	//this->presenter = new Presenter();
}

void Manager::run()
{
	// gets the first state for the game to be in (BeginningState), then
	// follows the next state that is returned from the current one each
	// time until the game ends

	GameState *current_state, *next_state;

	current_state = new BeginningState();
	
	do
	{
		current_state -> process_game_state();
		next_state = current_state->get_next_game_state();
		delete current_state; // TODO: confirm if this works
		current_state = next_state;
	} while(current_state != nullptr);
}

