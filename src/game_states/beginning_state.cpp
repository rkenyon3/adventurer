#include "beginning_state.h"

using namespace std;

void BeginningState::process_game_state()
{
	Presenter presenter = Presenter();
	presenter.show_text(welcome_text);

	vector<string> prompts;
	prompts.push_back(option_beginning_castle);
	prompts.push_back(option_beginning_forest);
	prompts.push_back(option_beginning_stay);


	player_response response = presenter.get_player_response(beginning_text, prompts);
	switch(response.prompt_choice)
	{
		case 0:
			presenter.show_text(response_beginning_castle);
			break;
		case 1:
			presenter.show_text(response_beginning_forest);
			break;
		case 2:
			presenter.show_text(response_beginning_stay);
			break;
	}
	this->next_game_state = new LostState();
}
