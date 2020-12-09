#pragma once
#include "stdafx.h"

#include "inputClass.h"

//return opposite direction of input
char inputClass::opposite()
{
	if (character == 'w')
		return 's';
	if (character == 's')
		return 'w';
	if (character == 'a')
		return 'd';
	if (character == 'd')
		return 'a';
	else
		return ' ';
}