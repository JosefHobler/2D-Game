#include "Stone.h"


// Constructors
Stone::Stone(int x, int y)
	:x_stone(x), y_stone(y) {}

Iron::Iron(int x, int y)
	:Stone(x,y) {}


// Print to console
void Stone::ToConsole()
{
	cout << "\xDB";
}

void Iron::ToConsole()
{
	cout << "\xB2";
}


// Getters
int Stone::Get_x_stone()
{
	return x_stone;
}

int Stone::Get_y_stone()
{
	return y_stone;
}