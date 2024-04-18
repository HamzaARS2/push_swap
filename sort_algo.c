/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_algo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helarras <helarras@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 20:13:29 by helarras          #+#    #+#             */
/*   Updated: 2024/04/17 22:02:38 by helarras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_move_ab	count_all_moves(t_stack *stack_a, t_stack *stack_b, size_t index)
{
	t_move_ab	m;

	m = (t_move_ab){.cheapest_index = 0, .rr = 0, .rrr = 0};
	m.b_moves = count_b_moves(get_best_index(stack_b->arr, stack_a->arr[index],
				stack_b->size), stack_b->size);
	m.a_moves = count_a_moves(index, stack_a->size);
	while (m.b_moves.rb && m.a_moves.ra)
	{
		m.rr++;
		m.b_moves.rb--;
		m.a_moves.ra--;
	}
	while (m.b_moves.rrb && m.a_moves.rra)
	{
		m.rrr++;
		m.b_moves.rrb--;
		m.a_moves.rra--;
	}
	return (m);
}

t_move_ab	find_cheapest_number(t_stack *stack_a, t_stack *stack_b)
{
	size_t		i;
	int			least_moves;
	int			moves;
	t_move_ab	cm;
	t_move_ab	ab_moves;

	least_moves = 2147483647;
	i = 0;
	while (i < stack_a->size)
	{
		if (least_moves == 1)
			return (ab_moves);
		cm = count_all_moves(stack_a, stack_b, i);
		moves = cm.a_moves.ra + cm.a_moves.rra + cm.b_moves.rb + cm.b_moves.rrb
			+ cm.rr + cm.rrr + 1;
		if (moves < least_moves)
		{
			least_moves = moves;
			ab_moves = cm;
			ab_moves.cheapest_index = i;
		}
		i++;
	}
	return (ab_moves);
}

int	find_min_index(t_stack *stack)
{
	size_t	i;
	int		min_i;

	min_i = 0;
	i = 0;
	while (i < stack->size)
	{
		if (stack->arr[min_i] > stack->arr[i])
			min_i = i;
		i++;
	}
	return (min_i);
}

void	arrange_stack(t_stack *stack)
{
	int			min_index;
	t_move_a	last_moves;

	min_index = find_min_index(stack);
	last_moves = count_a_moves(min_index, stack->size);
	while (last_moves.ra--)
		ra_rotate_a(stack, 1);
	while (last_moves.rra--)
		rra_reverse_rotate_a(stack, 1);
}

void	sort(t_stack *stack_a, t_stack *stack_b)
{
	t_move_a	a_moves;

	pb_push_b(stack_a, stack_b, 1);
	pb_push_b(stack_a, stack_b, 1);
	while (stack_a->size > 3)
	{
		execute_moves(stack_a, stack_b, find_cheapest_number(stack_a, stack_b));
		pb_push_b(stack_a, stack_b, 1);
	}
	sort_three(stack_a);
	while (stack_b->size)
	{
		a_moves = count_a_moves(get_best_a_index(stack_a->arr, stack_b->arr[0],
					stack_a->size), stack_a->size);
		while (a_moves.ra--)
			ra_rotate_a(stack_a, 1);
		while (a_moves.rra--)
			rra_reverse_rotate_a(stack_a, 1);
		pa_push_a(stack_a, stack_b, 1);
	}
	arrange_stack(stack_a);
}
