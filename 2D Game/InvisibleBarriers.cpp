#include "InvisibleBarriers.h"


// Constructors
InvisibleBarriers::InvisibleBarriers(int x, int y)
	:x_inv_barrier(x), y_inv_barrier(y) {}

VisibleBarriers::VisibleBarriers(int x, int y)
	: InvisibleBarriers(x,y) {}

HalfVisibleBarriers::HalfVisibleBarriers(int x, int y)
	: InvisibleBarriers(x, y) {}


// Print to console
void InvisibleBarriers::ToConsole()
{
	cout << " ";
}

void VisibleBarriers::ToConsole()
{
	cout << "\xDB";
}

void HalfVisibleBarriers::ToConsole()
{
	cout << "\xDF";
}


// Getters
int InvisibleBarriers::Get_x_inv_barrier()
{
	return x_inv_barrier;
}

int InvisibleBarriers::Get_y_inv_barrier()
{
	return y_inv_barrier;
}