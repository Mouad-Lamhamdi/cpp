CC = g++

CXXFLAGS = -Wall -Wextra -Werror -std=c++98

SRCS = megaphone.cpp

OBJS = $(SRCS:.cpp=.o)

all: megaphone

megaphone: $(OBJS)
	$(CC) $(CXXFLAGS) -o $@ $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f megaphone

re: fclean all

.PHONY: clean fclean re