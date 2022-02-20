#include "Player.h"


// Constructors
Player::Player()
	:x_player(0), y_player(0)
{
	weapon = new Weapons(1,5,10);
	attack_timer = Get_weapon_speed();
	head = true;
}

Player::Player(int x, int y)
	:x_player(x), y_player(y), jump(false), jump_counter(0) 
{
	weapon = new Weapons(1,5,10);
	attack_timer = Get_weapon_speed();
	head = true;
}

Zombie::Zombie(int x, int y)
	:Player(x,y), focus(false), count_move(3) {}


// Player's movement
void Player::Move()
{

	if (left_move)
	{
		if ((0x8000 & GetAsyncKeyState((unsigned char)('A'))) != 0)
		{
			x_player -= 1;
			head = true;
		}
	}
	if (right_move)
	{
		if ((0x8000 & GetAsyncKeyState((unsigned char)('D'))) != 0)
		{
			x_player += 1;
			head = false;
		}
	}
	if (!gravity)
	{
		jump = (0x8000 & GetAsyncKeyState((unsigned char)(VK_SPACE))) != 0 ? true : false;
	}
	if (attack_timer == 0)
	{
		attack = false;
		if ((0x8000 & GetAsyncKeyState((unsigned char)(VK_LBUTTON))) != 0)
		{
			attack = true;
			attack_timer = Get_weapon_speed();
		}
	}
	attack_timer--;
}

void Zombie::Move()
{
	if (left_move)
	{
		if (focus && zombie_left)
		{
			if (count_move == 0)
			{
				x_player -= 1;
				count_move = 2;
			}
			count_move--;
			return;
		}
		movement = rand() % 50;
		x_player -= (movement == 0) ? 1 : 0;
	}
	if (right_move)
	{
		if (focus && zombie_right)
		{
			if (count_move == 0)
			{
				x_player += 1;
				count_move = 2;
			}
			count_move--;
			return;
		}
		movement = rand() % 50;
		x_player += (movement == 0) ? 1 : 0;
	}
	if (!gravity)
	{
		movement = rand() % 100;
		jump = (movement == 0) ? true : false;
	}
}


// Show to console
void Player::ToConsole()
{
	cout << "\x4F";
}

void Zombie::ToConsole()
{
	cout << "\x99";
}

void Player::Call_weapon()
{
	weapon->ToConsole();
}


// Incrementing player y by 1
void Player::Increment_y_player()
{
	y_player++;
}


// Decrementing player y by 1
void Player::Decrement_y_player()
{
	y_player--;
}


// Getters
bool Player::Get_attack()
{
	return attack;
}

int Player::Get_weapon_power()
{
	return weapon->Get_power();
}

int Player::Get_weapon_speed()
{
	return weapon->Get_speed();
}

bool Player::Get_head()
{
	return head;
}

int Player::Get_weapon_range()
{
	return weapon->Get_range();
}

bool Zombie::Get_zombie_left()
{
	return zombie_left;
}

bool Zombie::Get_zombie_right()
{
	return zombie_right;
}

bool Player::Get_left_move()
{
	return left_move;
}

bool Player::Get_right_move()
{
	return right_move;
}

bool Zombie::Get_focus()
{
	return focus;
}

int Player::Get_x_player()
{
	return x_player;
}

int Player::Get_y_player()
{
	return y_player;
}

bool Player::Get_jump()
{
	return jump;
}

bool Player::Get_gravity()
{
	return gravity;
}

bool Player::Get_up()
{
	return up;
}

int Player::Get_jump_counter()
{
	return jump_counter;
}


// Setters
void Player::Modify_attack(bool value)
{
	attack = value;
}

void Zombie::Modify_focus(bool value)
{
	focus = value;
}

void Player::Modify_jump(bool value)
{
	jump = value;
}

void Player::Modify_up(bool value)
{
	up = value;
}

void Player::Modify_gravity(bool value)
{
	gravity = value;
}

void Player::Modify_left_move(bool value)
{
	left_move = value;
}

void Player::Modify_right_move(bool value)
{
	right_move = value;
}

void Player::Modify_jump_counter(int value)
{
	jump_counter = value;
}

void Zombie::Modify_zombie_left(bool value)
{
	zombie_left = value;
}

void Zombie::Modify_zombie_right(bool value)
{
	zombie_right = value;
}