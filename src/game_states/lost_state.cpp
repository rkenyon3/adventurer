#include "lost_state.h"

using namespace std;

void LostState::process_game_state()
{
	Presenter presenter = Presenter();
	this->next_game_state = nullptr;
	presenter.show_text("\nYou have lost. Better luck next time. Thanks for playing!\n");
}
