#include "Cell.hpp"
#include "GameOfLife.hpp"

//template <class T>
void print_vector(std::vector<std::string> &v)
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
