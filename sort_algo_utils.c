/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_algo_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helarras <helarras@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 20:11:38 by helarras          #+#    #+#             */
/*   Updated: 2024/04/17 22:01:04 by helarras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_best_index(int *arr, int number, size_t size)
{
	size_t	i;
	int		best_index;
	int		biggest_i;

	i = 0;
	biggest_i = 0;
	best_index = -1;
	while (i < size)
	{
		if (number > arr[i])
		{
			if (best_index == -1 || arr[i] > arr[best_index])
				best_index = i;
		}
		if (arr[i] > arr[biggest_i])
			biggest_i = i;
		i++;
	}
	if (best_index == -1)
		return (biggest_i);
	return (best_index);
}

int	get_best_a_index(int *arr, int number, size_t size)
{
	size_t	i;
	int		best_index;
	int		smallest_i;

	i = 0;
	smallest_i = 0;
	best_index = -1;
	while (i < size)
	{
		if (arr[i] > number)
		{
			if (best_index == -1 || arr[i] < arr[best_index])
				best_index = i;
		}
		if (arr[i] < arr[smallest_i])
			smallest_i = i;
		i++;
	}
	if (best_index == -1)
		return (smallest_i);
	return (best_index);
}

t_move_b	count_b_moves(size_t index, size_t size)
{
	t_move_b	move_b;

	move_b = (t_move_b){0};
	if (index > (size / 2))
		move_b.rrb = size - index;
	else
		move_b.rb = index;
	return (move_b);
}

t_move_a	count_a_moves(size_t index, size_t size)
{
	t_move_a	move_a;

	move_a = (t_move_a){0};
	if (index > (size / 2))
		move_a.rra = size - index;
	else
		move_a.ra = index;
	return (move_a);
}

void	execute_moves(t_stack *stack_a, t_stack *stack_b, t_move_ab moves)
{
	while (moves.rr--)
		rr_rotate_ab(stack_a, stack_b, 1);
	while (moves.rrr--)
		rrr_reverse_rotate_ab(stack_a, stack_b, 1);
	while (moves.b_moves.rb--)
		rb_rotate_b(stack_b, 1);
	while (moves.a_moves.ra--)
		ra_rotate_a(stack_a, 1);
	while (moves.b_moves.rrb--)
		rrb_reverse_rotate_b(stack_b, 1);
	while (moves.a_moves.rra--)
		rra_reverse_rotate_a(stack_a, 1);
}
