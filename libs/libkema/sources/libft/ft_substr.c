/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjourdan <jjourdan@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 02:01:42 by jjourdan          #+#    #+#             */
/*   Updated: 2021/03/18 15:00:19 by jjourdan         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*fill_out(size_t i, unsigned int start, char *str, \
				char *out)
{
	size_t	j;

	j = 0;
	while (j + start < i)
	{
		out[j] = str[j + start];
		j++;
	}
	return (out);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t			i;
	char			*str;
	char			*out;

	if (!s)
		return (NULL);
	str = (char *)s;
	i = ft_strlen(s);
	if (start >= i)
	{
		out = ft_calloc(sizeof(char), 1);
		if (!out)
			return (NULL);
		*out = 0;
		return (out);
	}
	if (i > start + len)
		i = start + len;
	out = ft_calloc(sizeof(char), (i - start + 1));
	if (!out)
		return (NULL);
	out = fill_out(i, start, str, out);
	return (out);
}
