/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helarras <helarras@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 16:49:21 by helarras          #+#    #+#             */
/*   Updated: 2024/04/18 12:18:43 by helarras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "ft_stack.h"
# include "instructions.h"
# include <unistd.h>

typedef struct move_a
{
	int			ra;
	int			rra;
}				t_move_a;

typedef struct move_b
{
	int			rb;
	int			rrb;
}				t_move_b;

typedef struct move
{
	t_move_a	a_moves;
	t_move_b	b_moves;
	int			cheapest_index;
	int			rr;
	int			rrr;
}				t_move_ab;

long			ft_atol(const char *str);
void			ft_swapi(int *n1, int *n2);
void			sort_three(t_stack *stack);
int				max_index(int *nums, size_t size);
int				get_best_index(int *arr, int number, size_t size);
t_move_b		count_b_moves(size_t index, size_t size);
t_move_a		count_a_moves(size_t index, size_t size);
t_move_ab		count_all_moves(t_stack *stack_a, t_stack *stack_b,
					size_t index);
t_move_ab		find_cheapest_number(t_stack *stack_a, t_stack *stack_b);
void			sort(t_stack *stack_a, t_stack *stack_b);
void			execute_moves(t_stack *stack_a, t_stack *stack_b,
					t_move_ab moves);
int				get_best_a_index(int *arr, int number, size_t size);
t_data			get_data(char **args, size_t size);
char			*ft_substr(char const *str, unsigned int start, size_t len);
int				count_words(char const *str, char delimeter);
char			**ft_split(char const *str, char c);
int				validate_data(char **data);
void			sort_three(t_stack *stack);
int				ft_strcmp(const char *s1, const char *s2);
#endif