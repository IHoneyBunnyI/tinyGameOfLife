#include "Generation.hpp"
#include "GameOfLife.hpp"


int main(int ac, char **av)
{
	Generation gen;

	if (ac < 1 || ac > 2)
		return (error(1));
	gen.getMapFromFile(av[1]);
	gen.fillParametrs();
	std::cout << gen.getSurvivors() << std::endl;
	while (gen.getState() != death)
	{
		gen.print_status_game();
		gen.iteration();
		//sleep(1);
	}
	gen.theEnd();
	return 0;
}
