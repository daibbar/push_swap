NAME = push_swap.a  ## check the name
SRC = ## add the sources
OBJ = $(SRC:.c=.o)
CLFLAGS = -Wall -Wextra -Werror
CC = cc
AR = ar rcs
RM = rm -f

all: $(NAME)

$(NAME): $(OBJ)
	$(AR) $(NAME) $(OBJ)

%.o: .c lifbt.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: clean fclean re