#ifndef MANAGER_H
#define MANAGER_H

#include <iostream>
#include <vector>

#include "game_state.h"
#include "game_states/beginning_state.h"
#include "player_response.h"
#include "presenter.h"
#include "text.h"

class Manager{
	public:
		Manager();
		void run();
	
	private:
		Presenter* presenter;
};

#endif

