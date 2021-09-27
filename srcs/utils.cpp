#include "Generation.hpp"
#include "GameOfLife.hpp"
#include <cstdlib>

void print_map(std::vector<std::string> &v)
{
	std::vector<std::string>::iterator begin = v.begin();
	std::vector<std::string>::iterator end = v.end();
	for (; begin != end - 1; begin++)
		std::cout << "\033[38;5;46m" << *begin << WHITE << std::endl;
}

int error(int Case)
{
	if (Case == 1)
		std::cout << "\e[38;5;147m" << "Sorry, but I need a first generation file :(" << WHITE << std::endl;
	if (Case == 2)
		std::cout << "\e[38;5;147m" << "Sorry, but I don't need an empty file" << WHITE << std::endl;
	exit(Case);
}

int check_generations(int *g)
{
	for (int i = 0; i < 20; i++)
	{
		if (g[0] != g[i])
			return 1;
	}
	return 0;
}

int check_neighbors(int i, int j, std::vector<std::string> &map)
{
	int neighbors = 0;
	if (i != 0 && map[i -1][j] != ' ') //проверка слева
		neighbors++;
	if (i != MAX_HIGHT - 2 && map[i + 1][j] != ' ') //проверка справа
		neighbors++;
	if (j != MAX_WIDTH - 1 && map[i][j + 1] != ' ') //проверка снизу
		neighbors++;
	if (j != 0 && map[i][j - 1] != ' ') //проверка сверху
		neighbors++;
	if (i != 0 && j != 0 && map[i -1][j - 1] != ' ') //слева сверху
		neighbors++;
	if (i != 0 && j != MAX_WIDTH - 1 && map[i - 1][j + 1] != ' ') //справа сверху
		neighbors++;
	if (i != MAX_HIGHT - 2 && j != MAX_WIDTH - 1 && map[i + 1][j + 1] != ' ') //справа снизу
		neighbors++;
	if (i != MAX_HIGHT- 2 && j != 0 && map[i + 1][j - 1] != ' ') //слева снизу
		neighbors++;
	return neighbors;
}
