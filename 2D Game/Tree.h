#pragma once
#include "AdditionalFunctions.h"


class Tree
{
private:
	int x_tree, y_tree;
public:
	Tree(int x, int y);
	int Get_x_tree();
	int Get_y_tree();
};


class Leaves : public Tree
{
private:
public:
	Leaves(int x, int y);
};