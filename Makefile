NAME = game

CXX = clang++

CXXFLAGS = -g -Iincludes/ -fsanitize=address

FILES_CPP = main.cpp\
			Cell.cpp\
			utils.cpp\

FILES_HPP = Cell.hpp\
			GameOfLife.hpp\

SRCS = $(addprefix srcs/, $(FILES_CPP))
HEADERS = $(addprefix includes/, $(FILES_HPP))

OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS) $(HEADERS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME) 

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all
