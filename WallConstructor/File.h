#pragma once
#include <fstream>
#include <vector>


using std::ifstream;
using std::string;
using std::vector;

class File
{
	string path;
	ifstream file;
	vector<string> lines;


public:
	File(const string& _path);

	string getPath() const {return path;}
	auto getLines() const  {return lines;}
	
};

