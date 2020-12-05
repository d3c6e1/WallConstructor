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
	int height;
	int width;
	vector<vector<Cell>> structure;

public:
	Wall(): height{0}, width{0}{}
	
	Wall(const int _height, const int _width, const vector<string>& _wall): height{_height}, width{_width}
	{
		vector<Cell> row{};
		
		for (const auto& _row : _wall)
		{
			for (auto _cell : _row)
			{
				row.push_back(static_cast<Cell>(_cell));
			}
			
			structure.push_back(row);
			row.clear();
		}
	}

	int getHeight() const {return height;}
	int getWidth() const {return width;}
	auto getStructure() const{return structure;}

};

