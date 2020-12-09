#include "stdafx.h"
#include "run.h"
#include "unit.h"

#include <iostream>
#include <Windows.h>
#include <conio.h>

using namespace std;

//name explains itself
void run::drawfood()
{
	snakeobj.board.grid[meat.ypos][meat.xpos].value = '*';
}

//ASCII art "you lose"
void run::youlose()
{
	cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
	cout << "                      .__                      \n"
		<< " ___.__. ____  __ __  |  |   ____  ______ ____\n"
		<< "<   |  |/  _ \\|  |  \\ |  |  /  _ \\/  ___// __ \\\n"
		<< " \\___  (  <_> )  |  / |  |_(  <_> )___ \\\\\  ___/\n"
		<< " / ____|\\____/|____/  |____/\\____/____  >\\___  >\n"
		<< " \\/                                   \\/     \\/";
}

int run::start(inputClass& input, inputClass& prevInput)
{
	//assigns grid values to the characters of the snake
	snakeobj.spawn();

	//bool of whether the snake has eaten food
	bool eaten = true;

	//game loop
	while (true)
	{
		//if snake ate food
		if (eaten == true)
		{
			//change value of x and y of meat object
			meat.spawn(snakeobj.board.xval, snakeobj.board.yval);

			//ensures that meat object does not spawn in position of snake object and respawns the food if so
			for (int i = 0; i != snakeobj.parts.size(); ++i)
			{
				if (meat.xpos == snakeobj.parts[i].xpos && meat.ypos == snakeobj.parts[i].ypos)
				{
					meat.spawn(snakeobj.board.xval, snakeobj.board.yval);
				}
			}
		}
		
		//if snake ate a food(snake head pos at food head pos), draw the position of new food on board
		if (eaten == true)
			drawfood();
		//resets eaten bool to signify food not eaten
		eaten = false;

		//if snake eats food increase length of snake
		if (snakeobj.parts[0].xpos == meat.xpos && snakeobj.parts[0].ypos == meat.ypos)
		{
			snakeobj.grow();
			eaten = true;
		}

		char command = prevInput.character;

		//if snake hits borders of board you lose
		if (snakeobj.parts[0].xpos == snakeobj.board.xval + 1 ||
			snakeobj.parts[0].xpos == 0 ||
			snakeobj.parts[0].ypos == snakeobj.board.yval + 1 ||
			snakeobj.parts[0].ypos == 0)
		{
			youlose();
			cout << endl;
			Sleep(1000);
			break;
		}
		
		//if keyboard input is detected 
		if (_kbhit())
		{
			//create local char to collect the input data
			char temp = ' ';
			//assign temp value to input data value
			temp = _getch();
			//if temp is a valid key input change value of official input character
			if (temp == 'w' || temp == 'a' || temp == 's' || temp == 'd')
				input.character = temp;
		}

		//if input character is not the opposite direction of the snake and the snake is not 1 unit long
		if (input.character != prevInput.opposite() && snakeobj.parts.size() != 1)
		{
			//input is valid. input is going to be used as actual command
			prevInput = input;
			command = input.character;
		}

		//clear screen
		system("CLS");

		//draws snake
		unit last;
		last = snakeobj.move(command);
		snakeobj.draw(last);

		//cout board on cmd
		snakeobj.board.draw();

		//bool to check if snake has hit himself
		bool hitOrNot = false;

		//if snake head isnt eating a food
		if (snakeobj.parts[0].xpos != meat.xpos && snakeobj.parts[0].ypos != meat.ypos)
		{
			for (int i = 4; i != snakeobj.parts.size(); ++i)
			{
				//check if snake head is same position as snake body parts
				if (snakeobj.parts[0].xpos == snakeobj.parts[i].xpos && snakeobj.parts[0].ypos == snakeobj.parts[i].ypos)
				{
					//snake has hit something
					hitOrNot = true;
					//leave for loop
					break;
				}
			}
			//if snake hit something
			if (hitOrNot == true)
			{
				//end game sequence
				youlose();
				cout << endl;
				Sleep(1000);
				break;
			}
		}

		//output score
		cout << "SCORE: " << snakeobj.parts.size() - snakeobj.length << endl;
		//program doesnt do anything for 1 sec
		Sleep(snakeobj.speed);
	}
	//returns the score
	return snakeobj.parts.size() - snakeobj.length;
}
