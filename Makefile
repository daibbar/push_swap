NAME = push_swap ## check the name
SRC = main.c stack_utils.c av_parser.c  mv_push_swap.c mv_rotations.c sorting.c small_sort.c \
		 ## add the sources
OBJ = $(SRC:.c=.o)
CFLAGS = -Wall -Wextra -Werror
CC = cc
RM = rm -f

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

%.o: %.c push_swap.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: clean fclean re