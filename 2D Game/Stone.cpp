#include "Stone.h"


// Constructor
Stone::Stone(int x, int y)
	:x_stone(x), y_stone(y) {}


// Getters
int Stone::Get_x_stone()
{
	return x_stone;
}


int Stone::Get_y_stone()
{
	return y_stone;
}