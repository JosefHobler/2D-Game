#include "Player.h"


// Constructors
Player::Player()
	:x_player(0), y_player(0) {}

Player::Player(int x, int y)
	:x_player(x), y_player(y), jump(false), jump_counter(0) {}

Zombie::Zombie(int x, int y)
	:Player(x,y), focus(false) {}


// Player's movement
void Player::Move()
{
	if (left_move)
	{
		x_player -= (0x8000 & GetAsyncKeyState((unsigned char)('A'))) != 0 ? 1 : 0;
	}
	if (right_move)
	{
		x_player += (0x8000 & GetAsyncKeyState((unsigned char)('D'))) != 0 ? 1 : 0;
	}
	if (!gravity)
	{
		jump = (0x8000 & GetAsyncKeyState((unsigned char)(VK_SPACE))) != 0 ? true : false;
	}
}

void Zombie::Move()
{
	if (left_move)
	{
		if (focus && zombie_left)
		{
			x_player -= 1;
			return;
		}
		movement = rand() % 50;
		x_player -= (movement == 0) ? 1 : 0;
	}
	if (right_move)
	{
		if (focus && zombie_right)
		{
			x_player += 1;
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

void Player::Modify_zombie_left(bool value)
{
	zombie_left = value;
}

void Player::Modify_zombie_right(bool value)
{
	zombie_right = value;
}


// Nothing
bool Player::Get_focus() 
{
	return false;
}

void Player::Modify_focus(bool value) {}