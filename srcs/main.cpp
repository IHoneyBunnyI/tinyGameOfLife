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
		std::system("clear");
		gen.print_status_game();
		gen.iteration();
		if (gen.getSurvivors() == 0)
			break;
		usleep(200000);
	}
	gen.theEnd();
	return 0;
}
