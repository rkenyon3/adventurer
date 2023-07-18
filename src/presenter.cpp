#include "presenter.h"

using namespace std;

Presenter::Presenter()
{
	
}

void Presenter::show_text(const string text_to_show)
{
	string text = string(text_to_show); // copy so we can add newlines without changing the original
	struct winsize w;
	ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);

	// replace spaces with newlines where the text would overflow, so it wraps nicely.
	int i, col_index, last_space_index;
	col_index = 0;
	for(i = 0; i < text.length(); i++)
	{
		if(text[i] == ' ')
			last_space_index = i;			
			
		col_index += 1;
		
		if(text[i] == '\n')
			col_index = 0;
			
		if(col_index == w.ws_col)
		{
			if(last_space_index != 0)
				text[last_space_index] = '\n';
			col_index = 0;
		}
	}
	
	for(i = 0; i < text.length(); i++)
	{
		cout << text[i] << flush;
		this_thread::sleep_for(chrono::milliseconds(CHAR_MILLI_DELAY));
	}
}

player_response Presenter::get_player_response(const string prompt_text, const vector<string> prompts)
{
	player_response response;
	string input_str;
	int prompt_input, response_number;
	
	// print prompt
	this->show_text(prompt_text);
	for(int i = 0; i < prompts.size(); i++)
	{
		cout << i + 1 << ". ";
		this->show_text(prompts[i]);
	}
	cout << ">" << flush;
	
	// Read input
	// This gives one-indexed numbers for display, but returns zero-indexed for internal logic. Note string compare logic
	// produces a zero if strings match, so if(!input_str.compare(...
	response.inventory_requested = false;
	response.prompt_returned = false;
	response.map_requested = false;
	
	while(!(response.inventory_requested || response.prompt_returned || response.map_requested))
	{
		cin >> input_str;

		if(!input_str.compare("m"))
		{
			response.map_requested = true;
			response.prompt_returned = false;
			response.inventory_requested = false;
		}
		else if(!input_str.compare("i"))
		{
			response.map_requested = true;
			response.prompt_returned = false;
			response.inventory_requested = false;
		}
		else
		{
			response_number = atoi(input_str.c_str());
			
			if(response_number < 1 || response_number > prompts.size())
			{
				stringstream buffer;
				buffer << "Choose  a number between 1 and " << prompts.size() << "\n>" << flush;
				this->show_text(buffer.str());
			}
			else
			{
					response.prompt_choice = response_number - 1;
					response.inventory_requested = false;
					response.prompt_returned = true;
					response.map_requested = false;
			}
		}
	}
	
	return response;
}
