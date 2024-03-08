CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC_FILES = push_swap.c ft_stack_utils.c ft_stack.c ft_atoi.c ft_swapi.c r_rotate_instructions.c sp_instructions.c rotate_instructions.c

all:
	$(CC) $(SRC_FILES) -o play