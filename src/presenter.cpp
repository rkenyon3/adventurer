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

int Presenter::get_player_response(const string prompt_text, const vector<string> prompts)
{
	int response_number = -1;
	this->show_text(prompt_text);
	for(int i = 0; i < prompts.size(); i++)
	{
		cout << i + 1 << ". ";
		this->show_text(prompts[i]);
	}
	cout << ">" << flush;
	
	// This gives one-indexed numbers for display, but returns zero-indexed for internal logic
	cin >> response_number;
	while(response_number < 1 || response_number > prompts.size())
	{
		stringstream buffer;
		buffer << "Choose  a number between 1 and " << prompts.size() << "\n>" << flush;
		this->show_text(buffer.str());
		cin >> response_number;
	}
	response_number -= 1;
	
	return response_number;
}
