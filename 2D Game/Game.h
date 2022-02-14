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
	vector<InvisibleBarriers*> barriers;
	vector<Stone*> stones;
	vector<Tree*> trees;
	vector<Player*> player;
	int x_coord, y_coord;
	char read_from_file;
	bool is_index_printed;
	bool game_over;
	vector<vector<char>> map_storage;
	vector<char> map_storage_helper;
	int min_left_side, max_right_side;
	int min_up, max_down;
	bool first_entry;
public:
	Game();
	~Game();
	void Show();
	void Run();
	void Logic();
	void MoveTerrain();
};