#pragma once
#include "AdditionalFunctions.h"


class Player
{
private:
	int x_player, y_player;
	bool jump;
public:
	Player(int x, int y);
	void Move(bool right_move, bool left_move, bool gravity);
	int Get_x_player();
	int Get_y_player();
	bool Get_jump();
	void Modify_jump(bool value);
	void Increment_y_player();
	void Decrement_y_player();
};