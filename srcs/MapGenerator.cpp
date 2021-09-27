#include "MapGenerator.hpp"
#include <cstdlib>

MapGenerator::MapGenerator(std::string name): name(name), probability(50), symbol('.') {}
MapGenerator::MapGenerator(std::string name, int probability): name(name), probability(probability), symbol('.') {}
MapGenerator::MapGenerator(std::string name, int probability, char symbol): name(name), probability(probability), symbol(symbol) {}

char MapGenerator::getSymbol()
{
	return this->symbol;
}

int MapGenerator::getProbability()
{
	return this->probability;
}

void MapGenerator::generateMap()
{
	std::srand(time(0));
	std::ofstream file(this->name);
	if (!file)
		error(4);
	for (int hight = 0; hight < MAX_HIGHT; hight++)
	{
		for (int width = 0; width < MAX_WIDTH; width++)
		{
			int probability = rand() % 100;
			if (probability < this->probability)
				file << this->symbol;
			else
				file << ' ';
		}
		file << '\n';
	}
}
