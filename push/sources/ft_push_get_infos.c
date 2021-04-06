/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_get_infos.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjourdan <jjourdan@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 10:21:07 by jjourdan          #+#    #+#             */
/*   Updated: 2021/04/06 14:46:35 by jjourdan         ###   ########lyon.fr   */
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

t_info	*ft_push_get_infos(int *tab, t_info *info)
{
	size_t	grp_size;
	ssize_t	i;

	ft_push_sort_tab(tab, (int)info->nb);
	info->group_1_low = tab[0];
	grp_size = 0;
	i = 0;
	while (i < (info->nb / 3))
	{
		info->group_1_high = tab[i];
		grp_size++;
		info->group_1_size = grp_size;
		i++;
	}
	info->group_2_low = tab[i];
	grp_size = 0;
	while (i < (2 * info->nb / 3))
	{
		info->group_2_high = tab[i];
		grp_size++;
		info->group_2_size = grp_size;
		i++;
	}
	info->group_3_low = tab[i];
	grp_size = 0;
	while (i < info->nb)
	{
		info->group_3_high = tab[i];
		grp_size++;
		info->group_3_size = grp_size;
		i++;
	}
	return (info);
}
