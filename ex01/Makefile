CC = g++

CXXFLAGS = -Wall -Wextra -std=c++11

SRCS = main.cpp helpers.cpp utils.cpp

OBJS = $(SRCS:.cpp=.o)

all: $(OBJS)
	$(CC) $(CXXFLAGS) -o my_program $(OBJS)

clean:
	rm -f $(OBJS) my_program

fclean: clean
	rm -f my_program

re: fclean all

.PHONY: all clean fclean re
