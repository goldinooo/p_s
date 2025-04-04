NAME = push_swap
CC = cc
RM = rm -rf
CFLAGS = -Wall -Wextra -Werror
SRC = src/main.c \
        src/operations/push.c \
        src/operations/swap.c \
        src/operations/rot.c \
        src/operations/rev_rot.c \
        src/parsing/args_handler.c \
        src/parsing/validation.c \
        src/sorting/sort_large.c \
        src/sorting/sort_small.c \
        src/utils/ft_split.c \
        src/utils/ft_strjoin.c \
        src/utils/list_utils.c \
        src/utils/stack_utils.c \
        src/utils/str_utils.c \

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)
	
%.o: %.c includes/push_swap.h
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	$(RM) $(OBJ)

fclean : clean
	$(RM) $(NAME)
	
re: fclean all

.PHONY: clean fclean re