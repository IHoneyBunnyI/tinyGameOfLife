#ifndef GENERATION_HPP
#define GENERATION_HPP
#define live 1
#define death 0

#include <iostream>
#include <vector>

class Generation
{
	typedef bool Status;
	public:
		Generation();
		void getMapFromFile(char* av1);
		void iteration();
		void fillParametrs();
		void print_status_game();
		void theEnd();
		void common_rules(std::vector<std::string> &copy_vector, int neighbors, int i, int j);
		friend int find_symbol(std::string string);

	private:
		std::vector<std::string> map;
		int survivors;
		int iterations;
		int state;
		char symbol;

	public:
		std::vector<std::string>& getMap();
		int getSurvivors();
		int getIterations();
		int getState();
};

#endif /* GENERATION_HPP */
