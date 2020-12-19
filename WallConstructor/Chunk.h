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


	friend bool operator==(const Chunk &c1, const Chunk &c2)
	{
		return (c1.height == c2.height && 
			c1.width == c2.width && 
			c1.bricksCount == c2.bricksCount);
	}

	struct hashFunction
	{
		size_t operator()(const Chunk &c) const
		{
			using std::hash;
			
			size_t hHash{hash<int>()(c.height)};
			size_t wHash{hash<int>()(c.width)};
			size_t cHash{hash<int>()(c.bricksCount)};

			return ((hHash ^ (wHash << 1)) >> 1) ^ (cHash << 1);
		} 
	};
	
	friend bool operator< (const Chunk &c1, const Chunk &c2)
	{
		return c1.bricksCount < c2.bricksCount;
	}
	friend bool operator<= (const Chunk &chunk1, const Chunk &chunk2)
	{
		return chunk1.bricksCount <= chunk2.bricksCount;
	}
	friend bool operator> (const Chunk &chunk1, const Chunk &chunk2)
	{
		return chunk1.bricksCount > chunk2.bricksCount;
	}
	friend bool operator>= (const Chunk &chunk1, const Chunk &chunk2)
	{
		return chunk1.bricksCount >= chunk2.bricksCount;
	}
};

