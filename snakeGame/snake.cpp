#include "stdafx.h"
#include "snake.h"

using namespace std;

//Initialize snake. Create and push back units into vector<unit> parts that has been given coordinates
void snake::spawn()
{
	//for loop that loops through initial length 
	for (int i = 0; i != length; ++i)
	{
		unit part;
		//assign coordinates to centre of board
		part.xpos = board.xval / 2;
		part.ypos = (board.yval / 2) - i;
		parts.push_back(part);
	}
}

//draw out the units in parts on grid
void snake::draw(unit last)
{
	int snakeSize = snake::parts.size();
	for (vector<unit>::size_type i = 1; i != snakeSize; ++i)
	{
		board.grid[snake::parts[i].ypos][snake::parts[i].xpos].value = 'O';
	}
	board.grid[last.ypos][last.xpos].value = ' ';
}

//change the coordinates of the units in the vector parts based on input command
unit snake::move(char c)
{

	unit previous;
	previous.xpos = snake::parts[0].xpos;
	previous.ypos = snake::parts[0].ypos;

	unit previous2;

	if (c == 'w')
	{
		--snake::parts[0].ypos;
	}
	else if (c == 'a')
	{
		--snake::parts[0].xpos;
	}
	else if (c == 's')
	{
		++snake::parts[0].ypos;
	}
	else if (c == 'd')
	{
		++snake::parts[0].xpos;
	}

	vector<unit>::size_type snakeSize = snake::parts.size();

	for (vector<unit>::size_type i = 1; i != snakeSize; ++i)
	{
		previous2.xpos = snake::parts[i].xpos;
		previous2.ypos = snake::parts[i].ypos;

		snake::parts[i].ypos = previous.ypos;
		snake::parts[i].xpos = previous.xpos;

		previous.xpos = previous2.xpos;
		previous.ypos = previous2.ypos;
	}
	return previous;
}

//increase length of snake
void snake::grow()
{
	unit u;
	snake::parts.push_back(u);
}
