#ifndef CELL_HPP
#define CELL_HPP 
#define live 1
#define death 1

class Cell
{
	typedef bool Status;
	public:
		Cell();

	private:
		Status status;
};

#endif /* CELL_HPP */
