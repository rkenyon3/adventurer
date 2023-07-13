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
	prompts.push_back(option_beginning_1);
	prompts.push_back(option_beginning_2);
	prompts.push_back(option_beginning_3);
	
	
	int selected_option = this->presenter->get_player_response(beginning_text, prompts);
}

