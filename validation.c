/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helarras <helarras@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 17:37:03 by helarras          #+#    #+#             */
/*   Updated: 2024/04/18 15:08:55 by helarras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_digits_only(char *str)
{
	int	i;

	i = 0;
	while (str[i] == 45 || str[i] == 43)
		i++;
	while (str[i])
	{
		if (str[i] < 48 || str[i] > 57)
			return (0);
		i++;
	}
	return (i);
}

int	is_duplicated(char **data, int position)
{
	int	i;

	i = 0;
	while (data[i])
	{
		if (position == i)
		{
			i++;
			continue ;
		}
		if (!ft_strcmp(data[position], data[i]))
			return (1);
		i++;
	}
	return (0);
}

int	is_int_range(long number)
{
	return (number <= 2147483647 && number >= -2147483648);
}

int	validate_data(char **data)
{
	int		i;
	int		is_valid;

	i = 0;
	is_valid = 1;
	while (data[i] && is_valid)
	{
		if (!is_digits_only(data[i]))
			is_valid = 0;
		else if (!is_int_range(ft_atol(data[i])))
			is_valid = 0;
		else if (is_duplicated(data, i))
			is_valid = 0;
		i++;
	}
	if (!is_valid)
		write(2, "Error\n", 6);
	return (is_valid);
}
