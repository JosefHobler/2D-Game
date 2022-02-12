#pragma once
#include "AdditionalFunctions.h"
#include "InvisibleBarriers.h"
#include "Stone.h"
#include "Player.h"


class Game
{
private:
	int screen_width, screen_height;
	vector<InvisibleBarriers*> invisible_barriers;
	vector<Stone*> stones;
	Player* player;
	int x_coord, y_coord;
	char read_from_file;
	bool is_index_printed;
	bool game_over;
	bool left_move, right_move;
	bool gravity;
public:
	Game();
	~Game();
	void Show();
	void Run();
	void Logic();
};