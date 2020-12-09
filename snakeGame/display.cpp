#include "stdafx.h"
#include "display.h"

#include <iostream>

using namespace std;

display::display()
{
	//modify grid to contain yval + 2 empty vectors 
	grid.resize(yval + 2);
	
	//for every vector in grid
	for (int i = 0; i != yval + 2; ++i)
	{
		//modify layer to store xval + 2 amount of units
		grid[i].resize(xval + 2);
		//draw the vertical borders
		grid[i][xval + 1].value = '+';
		grid[i][0].value = '+';
	}

	//draw the horizontal borders
	for (int i = 0; i != xval + 2; ++i)
	{
		grid[0][i].value = '+';
		grid[yval + 1][i].value = '+';
	}
}

//cout the grid onto console
void display::draw()
{
	for (int i = 0; i != yval + 2; ++i)
	{
		for (int x = 0; x != xval + 2; ++x)
		{
			cout << grid[i][x].value;
		}
		cout << endl;
	}
}








