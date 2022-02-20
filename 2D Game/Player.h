#pragma once
#include "AdditionalFunctions.h"
#include "Weapons.h"

class Player
{
private:
	Weapons* weapon;
	int x_player, y_player;
	bool jump;
	bool right_move, left_move, gravity, up;
	int jump_counter;
	bool attack;
	int attack_timer;
	bool head;
	friend class Zombie;
public:
	Player();
	Player(int x, int y);

	int Get_x_player();
	int Get_y_player();
	bool Get_gravity();
	bool Get_up();
	int Get_jump_counter();
	bool Get_jump();
	bool Get_right_move();
	bool Get_left_move();
	int Get_weapon_power();
	int Get_weapon_range();
	int Get_weapon_speed();
	bool Get_attack();
	bool Get_head();
	void Call_weapon();

	void Modify_attack(bool value);
	void Modify_right_move(bool value);
	void Modify_left_move(bool value);
	void Modify_gravity(bool value);
	void Modify_up(bool value);
	void Modify_jump_counter(int value);
	void Modify_jump(bool value);

	void Increment_y_player();
	void Decrement_y_player();

	virtual void Move();
	virtual void ToConsole();
};


class Zombie : public Player
{
private:
	int count_move;
	bool focus;
	bool movement;
	bool zombie_left, zombie_right;
public:
	Zombie(int x, int y);
	void ToConsole();
	void Move();
	void Modify_focus(bool value);
	bool Get_focus();
	void Modify_zombie_left(bool value);
	void Modify_zombie_right(bool value);
	bool Get_zombie_left();
	bool Get_zombie_right();
};