#include "Generation.hpp"
#include "GameOfLife.hpp"

Generation::Generation(): survivors(0), iterations(1), state(live), symbol('#') {};
int find_symbol(std::string string, char &symbol)
{
	for (int i = 0; i < string.size(); i++)
	{
		if (string[i] != ' ')
		{
			symbol = string[i];
			return 1;
		}
	}
	return 0;
}

void Generation::getMapFromFile(char* av1)
{
	std::string path;
	int number_of_strs = 0;
	int find = 0;

	if (av1 != 0)
		path = av1;
	else
		path = "maps/map";
	std::ifstream file(path);
	if (!file)
		error(2);
	while (file && number_of_strs < MAX_HIGHT - 1)
	{
		std::string tmp;
		getline(file, tmp);
		if (!find)
			find = find_symbol(tmp, this->symbol);
		if (tmp.size() > MAX_WIDTH)
			tmp.erase(tmp.begin() + MAX_WIDTH - 1, tmp.end());
		if (tmp.size() < MAX_WIDTH)
			tmp.insert(tmp.end(), MAX_WIDTH - tmp.size() - 1, ' ');
		this->map.push_back(tmp);
		number_of_strs++;
	}
	std::string empty;
	empty.insert(empty.begin(), MAX_WIDTH - 1, ' ');
	while (number_of_strs < MAX_HIGHT - 1)
	{
		this->map.push_back(empty);
		number_of_strs++;
	}
}

void Generation::fillParametrs()
{
	for (std::vector<std::string>::iterator it_vec = this->map.begin(); it_vec != this->map.end(); it_vec++)
	{
		for (std::string::iterator it_str = it_vec->begin(); it_str != it_vec->end(); it_str++)
		{
			if (*it_str != ' ')
				this->survivors++;
		}
	}
}

void Generation::print_status_game()
{
	std::cout << "\t\t\t\t\t\t\t" << "\033[38;5;118mGame of Life" << WHITE << std::endl \
	<< "Is a live: " << "\033[38;5;93m" << this->survivors << WHITE << "\t\t\t\t" \
	<< "Iteration number: " << "\033[38;5;93m" << this->iterations << WHITE << std::endl;
}
void Generation::theEnd()
{
	std::system("clear");
	std::string mnogoTabov ="\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t";
	for (int i = 0; i < 37; i++)
		std::cout << std::endl;
	std::cout << mnogoTabov << "\033[38;5;220m" << "  _______      ___      .___  ___.  _______      ______   ____    ____  _______ .______      " << WHITE << std::endl;
 	std::cout << mnogoTabov << "\033[38;5;220m" << " /  _____|    /   \\     |   \\/   | |   ____|    /  __  \\  \\   \\  /   / |   ____||   _  \\     " << WHITE << std::endl;
	std::cout << mnogoTabov << "\033[38;5;220m" << "|  |  __     /  ^  \\    |  \\  /  | |  |__      |  |  |  |  \\   \\/   /  |  |__   |  |_)  |    " << WHITE << std::endl;
	std::cout << mnogoTabov << "\033[38;5;220m" << "|  | |_ |   /  /_\\  \\   |  |\\/|  | |   __|     |  |  |  |   \\      /   |   __|  |      /     " << WHITE << std::endl;
	std::cout << mnogoTabov << "\033[38;5;220m" << "|  |__| |  /  _____  \\  |  |  |  | |  |____    |  `--'  |    \\    /    |  |____ |  |\\  \\----." << WHITE << std::endl;
	std::cout << mnogoTabov << "\033[38;5;220m" << " \\______| /__/     \\__\\ |__|  |__| |_______|    \\______/      \\__/     |_______|| _| `._____|" << WHITE << std::endl;
	std::cout << mnogoTabov + "\t\t\t\t\t" << "\033[38;5;124m" << "All cells died :(" << WHITE << std::endl;
	for (int i = 0; i < 39; i++)
		std::cout << std::endl;
}

void Generation::iteration()
{
	int i = 0;
	int j = 0;
	int neighbors = 0;
	std::vector<std::string> copy_vector(this->map);
	if (this->survivors == 0)
		this->state = death;
	this->survivors = 0;
	this->iterations++;
	for (std::vector<std::string>::iterator it_vec = this->map.begin(); it_vec != this->map.end(); it_vec++, i++)
	{
		for (std::string::iterator it_str = it_vec->begin(); it_str != it_vec->end() - 1; it_str++, j++)
		{
			neighbors = check_neighbors(i, j, this->map);
			this->common_rules(copy_vector, neighbors, i, j);
		}
		j = 0;
	}
	print_map(copy_vector);
	this->map = copy_vector;
}

std::vector<std::string>& Generation::getMap()
{
	return (this->map);
}

int Generation::getSurvivors()
{
	return (this->survivors);
}

int Generation::getIterations()
{
	return (this->iterations);
}

int Generation::getState()
{
	return (this->state);
}
