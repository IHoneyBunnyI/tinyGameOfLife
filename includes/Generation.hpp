#ifndef GENERATION_HPP
#define GENERATION_HPP
#define live 1
#define death 1

#include <iostream>
#include <vector>

class Generation
{
	typedef bool Status;
	public:
		Generation();
		void parse_and_create_map(char* av1);
		std::vector<std::string>& getMap();

	private:
		std::vector<std::string> map;
};

#endif /* GENERATION_HPP */
