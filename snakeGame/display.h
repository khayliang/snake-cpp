#pragma once
#include "unit.h"

#include <vector>

//define a unit vector to be called layer
typedef std::vector<unit> layer;

class display
{
	friend class snake;
	friend class run;
public:
	//display default constructor
	display();

	//output the display grid onto cmd
	void draw();

	//create a vector of vectors like a grid to draw the game
	std::vector<layer> grid;

private:
	//length
	int xval = 40;

	//height
	int yval = 20;
	
	
};

