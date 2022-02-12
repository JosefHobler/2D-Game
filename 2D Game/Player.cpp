#include "Player.h"


// Constructor
Player::Player(int x, int y)
	:x_player(x), y_player(y), jump(false) {}


// Player's movement
void Player::Move(bool right_move, bool left_move, bool gravity)
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


// Decrementing player y by 1
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

// Setters
void Player::Modify_jump(bool value)
{
	jump = value;
}
