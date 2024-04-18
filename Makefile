CC = cc
CFLAGS = -Wall -Wextra -Werror
SRC_FILES = push_swap.c ft_stack_utils.c ft_stack.c \
ft_atol.c ft_swapi.c r_rotate_instructions.c sp_instructions.c \
rotate_instructions.c sort_algo.c sort_algo_utils.c count_words.c \
ft_split.c ft_substr.c validation.c get_data.c sort_three.c ft_strcmp.c

BONUS_FILES =  ft_checker.c ft_stack_utils.c ft_stack.c \
ft_atol.c ft_swapi.c r_rotate_instructions.c sp_instructions.c \
rotate_instructions.c get_data.c ft_split.c \
count_words.c ft_substr.c validation.c ft_checker_utils.c ft_strcmp.c

GNL = ./get_next_line/get_next_line.c ./get_next_line/get_next_line_utils.c

HEADERS = push_swap.h ft_stack.h instructions.h

NAME = push_swap

BONUS_NAME = checker

GNL_LIB = gnl_lib.a

GNL_OBJS = $(GNL:.c=.o)


$(NAME): $(SRC_FILES) $(HEADERS)
	$(CC) $(CFLAGS) $(SRC_FILES) -o $@ 

$(BONUS_NAME): $(BONUS_FILES) $(GNL_LIB) $(HEADERS) ft_checker.h
	$(CC) $(CFLAGS) $(BONUS_FILES) $(GNL_LIB) -o $(BONUS_NAME)
	
$(GNL_LIB): $(GNL_OBJS) 
	ar rcs $@ $^
	
%.o: %.c ./get_next_line/get_next_line.h
	$(CC) -c $(CFLAGS) $< -o $@
	
all: $(NAME)

bonus: $(BONUS_NAME)

clean:
	rm -f $(GNL_OBJS)

fclean: clean
	rm -f $(NAME) $(BONUS_NAME) $(GNL_LIB)

re: fclean all