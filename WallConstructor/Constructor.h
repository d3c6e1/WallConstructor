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
	Constructor(const string& _filePath): file{_filePath}
	{
		string wallDimensions{file.getLines()[0]};
		
		for (auto element : wallDimensions)
		{
			std::cout << element << "\n";	
		}

	}


	
	auto getChunks() const { return chunks; }	
};

