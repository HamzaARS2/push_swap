CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC_FILES = push_swap.c ft_atoi.c

all:
	$(CC) $(SRC_FILES) -o play