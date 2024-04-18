/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helarras <helarras@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 12:55:23 by helarras          #+#    #+#             */
/*   Updated: 2024/04/17 13:22:30 by helarras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	srclen;

	srclen = ft_strlen(src);
	i = 0;
	if (dstsize <= 0)
		return (srclen);
	while (src[i] && i < (dstsize - 1))
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = 0;
	return (srclen);
}

char	*ft_substr(char const *str, unsigned int start, size_t len)
{
	char	*substr;
	size_t	strsize;
	size_t	sublen;

	if (!str)
		return (0);
	strsize = ft_strlen(str);
	if (start > strsize)
	{
		sublen = 0;
		start = strsize;
	}
	else
	{
		if (strsize - start > len)
			sublen = len;
		else
			sublen = strsize - start;
	}
	substr = malloc((sublen + 1) * sizeof(char));
	if (!substr)
		return (0);
	ft_strlcpy(substr, str + start, sublen + 1);
	return (substr);
}
