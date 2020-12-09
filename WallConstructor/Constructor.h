#pragma once
#include <unordered_map>
#include "Chunk.h"
#include "File.h"
#include "Wall.h"

class Constructor
{
	File file;
	Wall wall;
	// vector<Chunk> chunks;
	std::unordered_map<Chunk, int, Chunk::hashFunction> chunks;

public:
	Constructor(const string& _filePath): file{_filePath}
	{
		int wallHeight{};
		int wallWidth{};
		int chunksCount{};
		string buffer;
		vector<string> fileLines{file.getLines()};
		vector<string> wallStructure;

		// wall
		auto space{fileLines[0].find_first_of(" ")};
		
		// for(int i = 0; i < space; i++)
		// {
		// 	buffer.push_back(fileLines[0][i]);
		// }

		wallHeight = stoi(fileLines[0].substr(0, space));
		// buffer.clear();
		
		// for(int i = space; i < fileLines[0].length(); i++)
		// {
		// 	buffer.push_back(fileLines[0][i]);
		// }
		
		wallWidth = stoi(fileLines[0].substr(space));
		// buffer.clear();

		for(int i = 1; i < wallHeight - 1; i++)
		{
			wallStructure.push_back(fileLines[i]);
		}

		wall = Wall{wallHeight, wallWidth, wallStructure};

		// chunks
		chunksCount = stoi(fileLines[wallHeight - 1]);

		for(int i = wallHeight; i < chunksCount; i++)
		{
			space = fileLines[i].find_first_of(" ");
			auto space2{fileLines[i].find_last_of(" ")};
			int chunkH{stoi(fileLines[i].substr(0, space))};
			int chunkW{stoi(fileLines[i].substr(space, space2))};
			int chunkC{stoi(fileLines[i].substr(space2))};
			chunks[Chunk{chunkH, chunkW}] = chunkC;
		}

		
	}


	
	auto getChunks() const { return chunks; }	
};

