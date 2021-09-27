#include "Generation.hpp"
#include "GameOfLife.hpp"

void print_map(std::vector<std::string> &v)
{
	std::vector<std::string>::iterator begin = v.begin();
	std::vector<std::string>::iterator end = v.end();
	for (; begin != end - 1; begin++)
		std::cout << *begin << std::endl;
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
	int i = 0;
	if (g[0] == g[1]
		&& g[0] == g[2]
		&& g[0] == g[3]
		&& g[0] == g[4]
		&& g[0] == g[5]
		&& g[0] == g[6]
		&& g[0] == g[7]
		&& g[0] == g[8]
		&& g[0] == g[9])
		return 0;
	else
		return 1;
}

int check_neighbors(int i, int j, std::vector<std::string> &map)
{
	//std::cout << "vec size=" << map.size() << std::endl;
	//std::cout << "str size=" << map[79].size() << std::endl;
	//std::cout << "i ="<<i << " j=" << j << std::endl;
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
