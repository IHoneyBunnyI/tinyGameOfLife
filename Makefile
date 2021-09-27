NAME = game
GENERATOR = mapGenerate

CXX = clang++

CXXFLAGS = -g -Iincludes/ -fsanitize=address

FILES_CPP = main.cpp\
			Generation.cpp\
			utils.cpp\
			common_rules.cpp\

GENERATOR_FILES_CPP = MapGenerator.cpp\
						generateMap.cpp\
						utils.cpp\


FILES_HPP = Generation.hpp\
			GameOfLife.hpp\
			MapGenerator.hpp\

GENERATOR_FILES_HPP = MapGenerator.hpp\

SRCS = $(addprefix srcs/, $(FILES_CPP))
G_SRCS = $(addprefix srcs/, $(GENERATOR_FILES_CPP))

HEADERS = $(addprefix includes/, $(FILES_HPP))
G_HEADERS = $(addprefix includes/, $(GENERATOR_FILES_HPP))

OBJS = $(SRCS:.cpp=.o)
G_OBJS = $(G_SRCS:.cpp=.o)

all: $(NAME) $(GENERATOR)

$(NAME): $(OBJS) $(HEADERS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME) 

$(GENERATOR): $(G_OBJS) $(G_HEADERS)
	$(CXX) $(CXXFLAGS) $(G_OBJS) -o $(GENERATOR) 

clean:
	rm -rf $(OBJS)
	rm -rf $(G_OBJS)

fclean: clean
	rm -rf $(NAME)
	rm -rf $(GENERATOR)

re: fclean all
