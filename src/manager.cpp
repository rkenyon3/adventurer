#include "manager.h"

using namespace std;

Manager::Manager()
{
	//this->presenter = new Presenter();
}

void Manager::run()
{
//	this->presenter->show_text(welcome_text);
//
//	vector<string> prompts;
//	prompts.push_back(option_beginning_castle);
//	prompts.push_back(option_beginning_forest);
//	prompts.push_back(option_beginning_stay);
//
//
//	player_response response = this->presenter->get_player_response(beginning_text, prompts);
//	switch(response.prompt_choice)
//	{
//		case 0:
//			this->presenter->show_text(response_beginning_castle);
//			break;
//		case 1:
//			this->presenter->show_text(response_beginning_forest);
//			break;
//		case 2:
//			this->presenter->show_text(response_beginning_stay);
//			break;
//
//	}

	GameState *current_state, *next_state = nullptr;

	current_state = new BeginningState();
	
	do
	{
		current_state -> process_game_state();
		next_state = current_state->get_next_game_state();
		delete *current_state; // TODO: confirm if this works
		current_state = next_state;
	} while(current_state != nullptr);
}

