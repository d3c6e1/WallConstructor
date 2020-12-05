#pragma once
#include "Chunk.h"
#include "File.h"
#include "Wall.h"

class Constructor
{
	File file;
	Wall wall;
	vector<Chunk> chunks;

public:
	Constructor(const string& _filePath): file{_filePath}
	{
		int wallHeight{};
		int wallWidth{};
		string buffer{};
		auto fileLines{file.getLines()};
		vector<string> wallStructure{};

		// wall
		auto space{fileLines[0].find_first_of(" ")};
		
		for(int i = 0; i < space; i++)
		{
			buffer.push_back(fileLines[0][i]);
		}

		wallHeight = stoi(buffer);
		buffer.clear();
		
		for(int i = space; i < fileLines[0].length(); i++)
		{
			buffer.push_back(fileLines[0][i]);
		}
		
		wallWidth = stoi(buffer);
		buffer.clear();

		for(int i = 1; i < wallHeight; i++)
		{
			wallStructure.push_back(fileLines[i]);
		}

		wall = Wall{wallHeight, wallWidth, wallStructure};

	}


	
	auto getChunks() const { return chunks; }	
};

