/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_get_infos.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjourdan <jjourdan@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 10:21:07 by jjourdan          #+#    #+#             */
/*   Updated: 2021/04/08 15:06:23 by jjourdan         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push_sort_tab(int *tab, int	size)
{
	int		i;
	int		buf;

	i = -1;
	while (++i < size - 1)
	{
		if (i < 0)
			i = 0;
		if (tab[i] > tab[i + 1])
		{
			buf = tab[i + 1];
			tab[i + 1] = tab[i];
			tab[i] = buf;
			i -= 2;
		}
	}
}
