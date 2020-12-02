#include "File.h"
#include <iostream>
#include <string>


File::File(const string& _path): path(_path), file(_path)
{
	if (!file)
	{
		std::cerr << "Error in opening file" << std::endl;
		// exit(1);
	}

	while (file)
	{
		string fLine;
		std::getline(file, fLine);
		lines.push_back(fLine);
	}
	
}
