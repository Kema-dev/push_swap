/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjourdan <jjourdan@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 22:43:56 by jjourdan          #+#    #+#             */
/*   Updated: 2021/03/18 15:02:03 by jjourdan         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	i;
	char	*out;

	i = 0;
	if (!s || !f)
		return (NULL);
	out = ft_calloc(sizeof(char), (ft_strlen(s) + 1));
	if (!out)
		return (NULL);
	while (s[i])
	{
		out[i] = f((unsigned int)i, s[i]);
		i++;
	}
	return (out);
}
