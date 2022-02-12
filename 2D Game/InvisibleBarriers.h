#pragma once
#include "AdditionalFunctions.h"


class InvisibleBarriers
{
private:
	int type;
	int x_inv_barrier, y_inv_barrier;
public:
	InvisibleBarriers(int x, int y, int type);
	int Get_x_inv_barrier();
	int Get_y_inv_barrier();
	int Get_type();
};