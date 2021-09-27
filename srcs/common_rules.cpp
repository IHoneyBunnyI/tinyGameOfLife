#include "Generation.hpp"
#include "GameOfLife.hpp"

void Generation::common_rules(std::vector<std::string> &copy_vector, int neighbors, int i, int j)
{
	if (this->map[i][j] == ' ' && neighbors == 3)
	{
		copy_vector[i][j] = '#';
		this->survivors++;
	}
	else if (this->map[i][j] != ' ' && (neighbors == 3 || neighbors == 2))
	{
		copy_vector[i][j] = '#';
		this->survivors++;
	}
	else if (this->map[i][j] != ' ' && (neighbors > 3 || neighbors < 2))
		copy_vector[i][j] = ' ';
}
