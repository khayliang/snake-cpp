#pragma once

//class to simplify using the input wasd 
class inputClass
{
public:
	//value of input
	char character;
	//opposite value of input. If input is 'w', opposite is 's'. Returns opposite value
	char opposite();
};

