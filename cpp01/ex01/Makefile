NAME = zombiehorde

CC = c++

CPPFLAGS	=	-Werror -Wextra -Wall -std=c++98

SRC = main.cpp zombieHorde.cpp Zombie.cpp

HEADER	= Zombie.hpp

OBJS	=	$(SRC:.cpp=.o)

%.o : %.cpp $(HEADER)
	${CC} -g ${CPPFLAGS} -c $< -o $@

$(NAME):	$(OBJS)
	$(CC) $(CPPFLAGS) -o $(NAME) $(OBJS)

all : $(NAME)

clean :
	rm -f $(OBJS)

fclean	: clean
	rm -f $(NAME)

re : fclean all

.PHONY: all clean fclean re