#include "Constructor.h"

#include <iostream>


Constructor::Constructor(const string& _filePath): file(_filePath)
{
	string wallDimensions = file.getLines()[0];
	for (auto element : wallDimensions)
	{
		std::cout << element << "\n";	
	}
	
}
