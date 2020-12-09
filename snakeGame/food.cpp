#include "stdafx.h"
#include "food.h"
#include <time.h>
#include <stdlib.h>
#include "display.h"

using namespace std;

//assign random values to xpos and ypos
void food::spawn(int xval, int yval)
{
	xpos = rand() % xval + 1;
	ypos = rand() % yval + 1;
}