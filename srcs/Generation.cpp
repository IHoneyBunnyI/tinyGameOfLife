#include "Generation.hpp"
#include "GameOfLife.hpp"

Generation::Generation(): survivors(0), iterations(1), state(live) {};

void Generation::getMapFromFile(char* av1)
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
	std::system("clear");
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
	if (this->survivors == 0)
		this->state = death;
	this->iterations++;
	if (this->iterations == 100)
		this->state = death;
	sleep(1);
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
