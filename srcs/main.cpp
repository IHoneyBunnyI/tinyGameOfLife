#include "Generation.hpp"
#include "GameOfLife.hpp"


int main(int ac, char **av)
{
	Generation gen;

	if (ac < 1 || ac > 2)
		return (error(1));
	gen.parse_and_create_map(av[1]);
	print_map(gen.getMap());
	//while(1);
	return 0;
}
