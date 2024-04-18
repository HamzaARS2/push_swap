/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helarras <helarras@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 13:51:12 by helarras          #+#    #+#             */
/*   Updated: 2024/04/17 22:02:12 by helarras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_data	get_data(char **args, size_t size)
{
	size_t	i;
	int		k;
	size_t	p;
	t_data	data;
	char	**result;

	i = 0;
	data = (t_data){0};
	while (i < size)
		data.size += count_words(args[i++], ' ');
	data.nums = malloc((data.size + 1) * sizeof(char *));
	if (!data.nums)
		return (data);
	i = 0;
	p = 0;
	while (p < data.size)
	{
		k = 0;
		result = ft_split(args[i++], ' ');
		while (result && result[k])
			data.nums[p++] = result[k++];
		free(result);
	}
	data.nums[data.size] = 0;
	return (data);
}
