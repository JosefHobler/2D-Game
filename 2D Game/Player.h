#pragma once
#include "AdditionalFunctions.h"


class Player
{
private:
	int x_player, y_player;
	bool jump;
	bool right_move, left_move, gravity, up;
	int jump_counter;
	bool zombie_left, zombie_right;
	friend class Zombie;
public:
	Player();
	Player(int x, int y);
	virtual void Move();
	int Get_x_player();
	int Get_y_player();
	bool Get_gravity();
	bool Get_up();
	int Get_jump_counter();
	void Modify_right_move(bool value);
	void Modify_left_move(bool value);
	void Modify_gravity(bool value);
	void Modify_up(bool value);
	void Modify_jump_counter(int value);
	bool Get_jump();
	void Modify_jump(bool value);
	void Increment_y_player();
	void Decrement_y_player();
	virtual void ToConsole();
};


class Zombie : public Player
{
private:
	int count_move;
	bool focus;
	bool movement;
public:
	Zombie(int x, int y);
	void ToConsole();
	void Move();
	void Modify_focus(bool value);
	bool Get_focus();
	void Modify_zombie_left(bool value);
	void Modify_zombie_right(bool value);
};