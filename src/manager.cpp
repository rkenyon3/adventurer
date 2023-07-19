#include "manager.h"

using namespace std;

Manager::Manager()
{
	this->presenter = new Presenter();
}

void Manager::run()
{
	GameState *current_state, *next_state = nullptr;
	
	current_state  = new BeginningState();
	
	do{
		current_state -> process_game_state();
		next_state = current_state->get_next_game_state();
		delete current_state; // TODO: confirm if this works
		current_state = next_state;
	} while(current_state != nullptr);
}

