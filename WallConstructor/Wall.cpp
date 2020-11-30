#include "Wall.h"

Wall::Wall(int _height, int _width, vector<string> _wall): height(_height), width(_width)
{
	vector<Cell> row;
	
	for (auto _row : _wall)
	{
		for (auto _cell : _row)
		{
			row.push_back(static_cast<Cell>(_cell));
		}
		
		structure.push_back(row);
		row.clear();
	}
}

