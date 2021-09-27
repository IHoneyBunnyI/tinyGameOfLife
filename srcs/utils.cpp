#include "Cell.hpp"
#include "GameOfLife.hpp"

template <class T>
void print_vector(std::vector<T> &v)
{
	typename std::vector<T>::iterator begin = v.begin();
	typename std::vector<T>::iterator end = v.end();
	for (; begin != end - 1; begin++)
		std::cout << "\033[38;5;46m" << *begin << "\033[0m " <<std::endl;
}

int error(int Case)
{
	if (Case == 1)
		std::cout << "\e[38;5;147m" << "Sorry, but I need a first generation file :(" << WHITE << std::endl;
	if (Case == 2)
		std::cout << "\e[38;5;147m" << "Sorry, but I don't need an empty file" << WHITE << std::endl;
	return 0;
}
