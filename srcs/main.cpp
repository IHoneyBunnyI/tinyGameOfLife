#include "Cell.hpp"
#include "GameOfLife.hpp"

int main(int ac, char **av)
{
	std::vector<std::string> map;

	if (ac != 2)
		return (error(1));
	std::ifstream file(av[1]);
	if (!file)
		return (error(2));
	while (file)
	{
		std::string tmp;
		getline(file, tmp);
		map.push_back(tmp);
	}
	print_vector(map);
	return 0;
}
