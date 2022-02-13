#pragma once
#include "AdditionalFunctions.h"


class Stone
{
private:
	int x_stone, y_stone;
public:
	Stone(int x, int y);
	int Get_x_stone();
	int Get_y_stone();
	virtual void ToConsole();
};


class Iron : public Stone
{
private:
public:
	Iron(int x, int y);
	void ToConsole();
};