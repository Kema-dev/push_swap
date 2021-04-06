/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_get_infos.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjourdan <jjourdan@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 10:21:07 by jjourdan          #+#    #+#             */
/*   Updated: 2021/04/06 10:29:48 by jjourdan         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_push_sort_tab(int *tab)
{
	size_t	i;
	int		buf;

	i = 0;
	while (tab[i + 1])
	{
		if (tab[i] > tab[i + 1])
		{
			buf = tab[i];
			tab[i] = tab[i + 1];
			tab[i + 1] = buf;
		}
		else
			i++;
	}
	return (i + 1);
}

t_info	*ft_push_get_infos(t_list *mem, int *tab)
{
	t_info	*info;
	ssize_t	i;

	info = kemalloc_exit(&mem, 1, sizeof(t_info), NO_PRINT);
	info->nb = ft_push_sort_tab(tab);
	i = -1;
	info->group_1_low = tab[0];
	while (++i < (info->nb / 3)) ;
	info->group_1_high = tab[i];
	info->group_2_low = tab[i + 1];
	while (++i < (2 * info->nb / 3)) ;
	info->group_2_high = tab[i];
	info->group_3_low = tab[i + 1];
	info->group_3_high = tab[info->nb];
	return (info);
}
