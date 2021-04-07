/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_grp_manip.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjourdan <jjourdan@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 17:42:32 by jjourdan          #+#    #+#             */
/*   Updated: 2021/04/07 17:45:20 by jjourdan         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_group	*ft_push_group_lstnew(t_list *mem, int min, int max, int group_size)
{
	t_group	*lst;

	lst = kemalloc_exit(&mem, 1, sizeof(t_group), NO_PRINT);
	lst->min = min;
	lst->max = max;
	lst->size = group_size;
	lst->next = NULL;
	return (lst);
}

void	ft_push_group_lstadd_back(t_group **alst, t_group *new)
{
	t_group	*buf;

	if (!new || !alst)
		return ;
	buf = *alst;
	if (*alst == NULL)
		*alst = new;
	else
	{
		while (buf->next)
			buf = buf->next;
		buf->next = new;
	}
}
