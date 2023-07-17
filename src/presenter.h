#ifndef PRESENTER_H
#define PRESENTER_H

#include <chrono>
#include <iostream>
#include <stdio.h>
#include <string>
#include <sstream>
#include <sys/ioctl.h>
#include <thread>  // just for sleeping
#include <unistd.h>
#include <vector>

#include "config.h"
#include "player_response.h"

class Presenter{
	public:
		Presenter();
		void show_text(const std::string text_to_show);
		player_response get_player_response(const std::string prompt_text, const std::vector<std::string> prompts);
};

#endif

