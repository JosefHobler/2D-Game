#include "Tree.h"


// Constructors
Tree::Tree(int x, int y)
	:x_tree(x), y_tree(y) {}


Leaves::Leaves(int x, int y)
	:Tree(x,y) {}


// Getters
int Tree::Get_x_tree()
{
	return x_tree;
}


int Tree::Get_y_tree()
{
	return y_tree;
}