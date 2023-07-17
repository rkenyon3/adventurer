#include "manager.h"

using namespace std;

Manager::Manager()
{
	this->presenter = new Presenter();
}

void Manager::run()
{
	this->presenter->show_text(welcome_text);
	
	vector<string> prompts;
	prompts.push_back(option_beginning_castle);
	prompts.push_back(option_beginning_forest);
	prompts.push_back(option_beginning_stay);
	
	
	int selected_option = this->presenter->get_player_response(beginning_text, prompts);
	switch(selected_option)
	{
		case 0:
			this->presenter->show_text(response_beginning_castle);
			break;
		case 1:
			this->presenter->show_text(response_beginning_forest);
			break;
		case 2:
			this->presenter->show_text(response_beginning_stay);
			break;
		
	}
}

