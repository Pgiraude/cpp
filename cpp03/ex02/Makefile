NAME = fragtrap2

CC = c++

RM = rm -f

CPPFLAGS = -Wall -Wextra -Werror -std=c++98

SRC = ClapTrap.cpp main.cpp ScavTrap.cpp FragTrap.cpp

HEADER = ClapTrap.hpp ScavTrap.hpp FragTrap.hpp

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

