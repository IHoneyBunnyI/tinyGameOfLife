#include "Cell.hpp"
#include "GameOfLife.hpp"

void parse_and_create_map(std::vector<std::string>& map, std::string av1)
{
	int max_size = 0;

	std::ifstream file(av1);
	if (!file)
		error(2);
	while (file)
	{
		std::string tmp;
		getline(file, tmp);
		if (tmp.size() > max_size)
			max_size = tmp.size();
		map.push_back(tmp);
	}
	for (std::vector<std::string>::iterator it = map.begin(); it != map.end(); it++)
	{
		while (it->size() < max_size)
			*it += ' ';
	}
}

int main(int ac, char **av)
{
	std::vector<std::string> map;

	if (ac != 2)
		return (error(1));
	parse_and_create_map(map, av[1]);
	//print_vector(map);
	//while(1);
	return 0;
}
