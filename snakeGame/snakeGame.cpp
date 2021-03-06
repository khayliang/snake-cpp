// snakeGame.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include "run.h"
#include <stdlib.h>
#include <time.h>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <Windows.h>
#include <conio.h>

using namespace std;

//if a greater than be return true
bool greater(int a, int b)
{
	return a > b;
}

int main()
{
	//provides random number generator time based seed
	srand(time(NULL));

	//creates runtime object
	run begin;
	
	//creates inputClass object for runtime to work with that isnt destroyed everytime game loops
	inputClass input;
	input.character = 'w';
	inputClass prevInput;
	int score = 0;
	score = begin.start(input, prevInput);

	//high score file IO objects
	ifstream infile("score.txt", fstream::app);
	ofstream outfile("score.txt", fstream::app);

	//create empty vector to store high scores
	vector<int> records;
	//integer to collect value stored in file for usage in code
	int collect;

	//loop file input until nothing left
	while (infile >> collect)
	{
		//put input values into the vector of records
		records.push_back(collect);
	}

	//bool to check if current score already exists in the score board
	bool exist = false;

	//loop through all scores to check if score exists
	for (int i = 0; i != records.size(); ++i)
	{
		if (score == records[i])
		{
			exist = true;
			break;
		}
	}

	//if scores doesnt exist
	if (exist == false)
	{
		//put score into high score file
		outfile << score << endl;
		records.push_back(score);
	}

	//sort record vector from big to small using function created previously
	sort(records.begin(), records.end(), greater);

	int position = 0;

	for (int i = 0; i != records.size(); ++i)
	{
		if (records[i] == score)
		{
			position = i + 1;
			break;
		}
	}

	cout << "\n\n\n\n\nYOUR SCORE: " << score 
		<< "\n\nPOSITION: " << position
		<<"\n\n\n";

	cout << "HIGH SCORES:" << endl;

	//cout only the top 8 high scores
	int counter = 0;
	while (counter != 9 && counter != (records.size()))
	{
		cout << counter + 1 << ". " << records[counter] << endl;
		++counter;
	}

	cout << "\n\n\n\n";

	Sleep(1000);
	//prevent console from closing if launch from .exe
	_getch();

    return 0;
}

