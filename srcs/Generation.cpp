#include "Generation.hpp"
#include "GameOfLife.hpp"

Generation::Generation(){};

void Generation::parse_and_create_map(char* av1)
{
	int max_size = 0;
	std::string path;

	if (av1 != 0)
		path = av1;
	else
		path = "maps/map";
	std::ifstream file(path);
	if (!file)
		error(2);
	while (file)
	{
		std::string tmp;
		getline(file, tmp);
		if (tmp.size() > max_size)
			max_size = tmp.size();
		this->map.push_back(tmp);
	}
	for (std::vector<std::string>::iterator it = this->map.begin(); it != this->map.end(); it++)
	{
		while (it->size() < max_size)
			*it += ' ';
	}
}


std::vector<std::string>& Generation::getMap()
{
	return (this->map);
}
