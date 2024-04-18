/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helarras <helarras@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 14:35:10 by helarras          #+#    #+#             */
/*   Updated: 2024/04/17 19:59:07 by helarras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_stack *stack)
{
	if (stack->arr[0] > stack->arr[1] && 
		(stack->arr[0] > stack->arr[stack->size - 1]))
		ra_rotate_a(stack, 1);
	if (stack->arr[stack->size - 1] < stack->arr[1] && 
		(stack->arr[stack->size - 1] < stack->arr[0]))
		rra_reverse_rotate_a(stack, 1);
	if (stack->arr[1] > stack->arr[stack->size - 1])
		rra_reverse_rotate_a(stack, 1);
	if (stack->arr[0] > stack->arr[1])
		sa_swap_a(stack, 1);
}
