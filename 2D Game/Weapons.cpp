#include "Weapons.h"


// Constructors
Weapons::Weapons(int range, int power, int speed)
	:range(range), power(power), speed(speed) {}

Sword::Sword(int range, int power, int speed)
	:Weapons(range,power,speed) {}


// To console
void Weapons::ToConsole()
{
	cout << "*";
}

void Sword::ToConsole()
{
	cout << "*";
}


// Getters
int Weapons::Get_range()
{
	return range;
}

int Weapons::Get_power()
{
	return power;
}

int Weapons::Get_speed()
{
	return speed;
}