#ifndef PLAYER_RESPONSE_H
#define PLAYER_RESPONSE_H

typedef struct {
	int prompt_choice;
	bool inventory_requested;
	bool prompt_returned;
	bool map_requested;
} player_response;

#endif

