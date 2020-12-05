#pragma once
#include "Chunk.h"
#include "File.h"
#include "Wall.h"


class Constructor
{
	File file;
	// Wall wall;
	vector<Chunk> chunks;

public:
	Constructor(const string& _filePath);
	
};

