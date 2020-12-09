#pragma once
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using std::string;

class File
{
	const string path;
	std::ifstream file;
	std::vector<string> lines;

public:
	File(const string& _path): path{_path}, file{_path}
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

		file.close();		
	}

	void reopenFile()
	{
		file.open(path);
	}
	
	string getPath() const {return path;}
	auto getLines() const  {return lines;}
};

