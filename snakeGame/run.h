#pragma once
#include "snake.h"
#include "inputClass.h"
#include "food.h"

class run
{
public:
	//initializes the game loop
	int start(inputClass&, inputClass&);

	//cout the food object on the grid using the food object xpos and ypos
	void drawfood();

	//cout the ascii art of losing
	void youlose();
private:
	snake snakeobj;
	food meat;
};

