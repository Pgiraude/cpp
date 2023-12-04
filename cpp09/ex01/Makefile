NAME = RPN

CC = c++

RM = rm -f

CPPFLAGS = -Wall -Wextra -Werror -std=c++98

SRC = main.cpp RPN.cpp

HEADER = RPN.hpp

OBJS = $(SRC:.cpp=.o)

%.o: %.cpp	$(HEADER)
	$(CC) -g $(CPPFLAGS) -c $< -o $@

$(NAME):	$(OBJS)
	$(CC) $(CPPFLAGS) -o $(NAME) $(OBJS)

all: $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re:	fclean all

.PHONY: all clean fclean re

