/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_words.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helarras <helarras@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 12:28:59 by helarras          #+#    #+#             */
/*   Updated: 2024/04/18 12:09:24 by helarras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	count_words(char const *str, char delimeter)
{
	size_t	i;
	size_t	count;

	count = 0;
	i = 0;
	while (str[i])
	{
		while (str[i] == delimeter)
			i++;
		while (str[i] && str[i] != delimeter)
			i++;
		if (i > 0 && str[i - 1] != delimeter)
			count++;
	}
	if (!count)
	{
		write(2, "Error\n", 6);
		exit(1);
	}
	return (count);
}
