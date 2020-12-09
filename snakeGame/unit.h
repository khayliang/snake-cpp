#pragma once
class unit
{
public:
	unit() :value(' '), occupied(false), xpos(0), ypos(0) {}


	//reset unit to default
	void clear()
	{
		value = ' ';
		occupied = false;
		xpos = 0;
		ypos = 0;
	};

	char value;
	int xpos;
	int ypos;
	bool occupied;
	
};

