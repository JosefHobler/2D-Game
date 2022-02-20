#pragma once
#include "AdditionalFunctions.h"

class Weapons
{
private:
	int range;
	int power;
	int speed;
public:
	Weapons(int range, int power, int speed);
	int Get_range();
	int Get_power();
	int Get_speed();
	virtual void ToConsole();
};


class Sword : public Weapons
{
private:
public:
	Sword(int range, int power, int speed);
	void ToConsole();
};