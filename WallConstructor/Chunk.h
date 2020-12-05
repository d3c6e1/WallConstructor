#pragma once


class Chunk
{
	int height = 0;
	int width = 0;
	int bricksCount = 0;

public:
	Chunk(int _height, int _width);

	int getBricksCount() const { return bricksCount; }
	int getHeight() const {return height;}
	int getWidth() const {return width;}

};

