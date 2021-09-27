#include "GameOfLife.hpp"
#include "MapGenerator.hpp"

int main(int ac, char** av)
{
	if (ac == 1)
		error(3);
	if (ac == 2)
	{
		std::string file_name(av[1]);
		MapGenerator generator(file_name);
		generator.generateMap();
	}
	else if (ac == 3)
	{
		std::string file_name(av[1]);
		MapGenerator generator(file_name, std::atoi(av[2]));
		generator.generateMap();
	}
	else if (ac == 4)
	{
		std::cout << av[3][0];
		std::string file_name(av[1]);
		MapGenerator generator(file_name, std::atoi(av[2]), av[3][0]);
		generator.generateMap();
	}
}
