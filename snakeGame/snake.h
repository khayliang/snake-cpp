#pragma once
#include "display.h"
#include "unit.h"
#include <vector>

class snake
{
	friend class run;
	public:
		//change initial length of snake here (it doesnt work though)
		snake() :score(0), length(4), speed(100) {}

		//draws the initial position of snake on the grid
		void spawn();

		//draw snake 
		void draw(unit);

		//the game board, containing the grid
		display board;

		//move snake
		unit move(char);

		//increase snake length
		void grow();
	private:
		int speed;
		unit head;
		int score;
		int length;
		std::vector<unit> parts;
};

