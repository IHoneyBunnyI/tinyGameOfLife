#ifndef MAPGENERATOR_HPP
#define MAPGENERATOR_HPP
#include <iostream>
#include "GameOfLife.hpp"

class MapGenerator
{
	private:
		int probability;
		char symbol;
		std::string name;

	public:
		MapGenerator(std::string name);
		MapGenerator(std::string name, int probability, char symbol);
		MapGenerator(std::string name, int probability);
		char getSymbol();
		int getProbability();
		void generateMap();
};

#endif
