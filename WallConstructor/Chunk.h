#pragma once

class Chunk
{
	const int height;
	const int width;
	const int bricksCount;

public:
	Chunk(const int _height, const int _width): height{_height}, width{_width}, bricksCount{_height * _width}{}

	int getBricksCount() const { return bricksCount; }
	int getHeight() const {return height;}
	int getWidth() const {return width;}

};

