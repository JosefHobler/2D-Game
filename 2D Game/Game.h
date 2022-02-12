#pragma once
#include "AdditionalFunctions.h"
#include "InvisibleBarriers.h"
#include "Stone.h"
#include "Player.h"
#include "Tree.h"


class Game
{
private:
	int screen_width, screen_height;
	vector<InvisibleBarriers*> invisible_barriers;
	vector<Stone*> stones;
	vector<Tree*> trees;
	vector<Leaves*> leaves;
	Player* player;
	int x_coord, y_coord;
	char read_from_file;
	bool is_index_printed;
	bool game_over;
	bool left_move, right_move;
	bool gravity;
	bool up;
	int jump_counter;
	vector<vector<char>> map_storage;
	vector<char> map_storage_helper;
	int min_left_side, max_right_side;
	bool first_entry;
public:
	Game();
	~Game();
	void Show();
	void Run();
	void Logic();
	void MoveTerrain();
};