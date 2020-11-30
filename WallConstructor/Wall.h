#pragma once
#include <string>
#include <vector>


using std::vector;
using std::string;

enum class Cell
{
	GAP,
	WALL,
	FILLED_WALL
};


class Wall
{
	int height = 0;
	int width = 0;
	vector<vector<Cell>> structure;


public:
	Wall(int _height, int _width, vector<string> _wall);

	
	int getHeight() const {return height;}
	int getWidth() const {return width;}
	auto getStructure() const{return structure;}

};

