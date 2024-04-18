/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helarras <helarras@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 13:39:53 by helarras          #+#    #+#             */
/*   Updated: 2024/04/18 13:28:14 by helarras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ft_checker.h"

int	main(int argc, char *argv[])
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	t_data	data;
	int		size;

	size = argc - 1;
	if (!size)
		return (0);
	data = get_data(argv + 1, size);
	if (!validate_data(data.nums))
		exit(1);
	stack_a = init_stack(data, 1);
	stack_b = init_stack((t_data){0}, 0);
	execute_all(stack_a, stack_b);
	check_stack(stack_a, stack_b);
}
