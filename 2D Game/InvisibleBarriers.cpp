#include "InvisibleBarriers.h"


// Constructor
InvisibleBarriers::InvisibleBarriers(int x, int y)
	:x_inv_barrier(x), y_inv_barrier(y) {}


// Getters
int InvisibleBarriers::Get_x_inv_barrier()
{
	return x_inv_barrier;
}


int InvisibleBarriers::Get_y_inv_barrier()
{
	return y_inv_barrier;
}