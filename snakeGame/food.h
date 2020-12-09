#pragma once
class food
{
public:
	//default constructor. Initializes integer values to 0 to prevent random stuff in values
	food() :xpos(0), ypos(0) {}

	//assign random values to xpos and ypos
	void spawn(int, int);

	int xpos;
	int ypos;
};

