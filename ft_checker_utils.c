/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helarras <helarras@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 19:02:34 by helarras          #+#    #+#             */
/*   Updated: 2024/04/18 10:56:06 by helarras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line/get_next_line.h"
#include "push_swap.h"

char	**read_instructions(void)
{
	char	*line;
	char	*all_lines;
	char	**instructions;

	line = get_next_line(0);
	all_lines = line;
	while (line)
	{
		line = get_next_line(0);
		all_lines = strcombine(all_lines, line);
	}
	instructions = ft_split(all_lines, '\n');
	return (instructions);
}

void	execute_instruction(t_stack *stack_a, t_stack *stack_b,
		char *instruction)
{
	if (!ft_strcmp(instruction, "sa"))
		sa_swap_a(stack_a, 0);
	else if (!ft_strcmp(instruction, "sb"))
		sb_swap_b(stack_b, 0);
	else if (!ft_strcmp(instruction, "ss"))
		ss_swap_ab(stack_a, stack_b, 0);
	else if (!ft_strcmp(instruction, "pa"))
		pa_push_a(stack_a, stack_b, 0);
	else if (!ft_strcmp(instruction, "pb"))
		pb_push_b(stack_a, stack_b, 0);
	else if (!ft_strcmp(instruction, "ra"))
		ra_rotate_a(stack_a, 0);
	else if (!ft_strcmp(instruction, "rb"))
		rb_rotate_b(stack_b, 0);
	else if (!ft_strcmp(instruction, "rr"))
		rr_rotate_ab(stack_a, stack_b, 0);
	else if (!ft_strcmp(instruction, "rra"))
		rra_reverse_rotate_a(stack_a, 0);
	else if (!ft_strcmp(instruction, "rrb"))
		rrb_reverse_rotate_b(stack_b, 0);
	else if (!ft_strcmp(instruction, "rrr"))
		rrr_reverse_rotate_ab(stack_a, stack_b, 0);
}

void	execute_all(t_stack *stack_a, t_stack *stack_b)
{
	int		i;
	char	**instructions;

	i = 0;
	instructions = read_instructions();
	while (instructions[i])
		execute_instruction(stack_a, stack_b, instructions[i++]);
}

int	check_stack(t_stack *stack_a, t_stack *stack_b)
{
	size_t	i;

	i = 1;
	if (stack_b->size > 0)
		return (write(1, "KO\n", 3));
	while (i < stack_a->size)
	{
		if (stack_a->arr[i - 1] > stack_a->arr[i])
			return (write(1, "KO\n", 3));
		i++;
	}
	return (write(1, "OK\n", 3));
}
