#pragma once
#include "AdditionalFunctions.h"


class InvisibleBarriers
{
private:
	int x_inv_barrier, y_inv_barrier;
public:
	InvisibleBarriers(int x, int y);
	int Get_x_inv_barrier();
	int Get_y_inv_barrier();
	virtual void ToConsole();
};


class VisibleBarriers : public InvisibleBarriers
{
private:
public:
	VisibleBarriers(int x, int y);
	void ToConsole();
};


class HalfVisibleBarriers : public InvisibleBarriers
{
private:
public:
	HalfVisibleBarriers(int x, int y);
	void ToConsole();
};