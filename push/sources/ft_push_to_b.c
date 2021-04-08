/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_to_b.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjourdan <jjourdan@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 11:00:49 by jjourdan          #+#    #+#             */
/*   Updated: 2021/04/08 15:40:20 by jjourdan         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_push_find_idx(t_dish *dish, int value)
{
	t_dish	*buf;
	size_t	i;

	buf = dish;
	i = 0;
	while (buf)
	{
		if (buf->value == value)
			break ;
		i++;
		buf = buf->next;
	}
	return (i);
}

void	ft_push_b_to_a(t_list **mem, t_stack *stack)
{
	int	itt;
	int	*tab;
	int	size;

	itt = 0;
	size = ft_push_lstsize(stack->b);
	tab = ft_push_list_to_tab(mem, stack->b, size);
	ft_push_sort_tab(tab, size);
	while (size > 0)
	{
		itt = ft_push_find_idx(stack->b, tab[size - 1]);
		if (itt < size / 2)
		{
			while (itt-- > 0)
				ft_push_rb(stack);
			ft_push_pa(stack);
		}
		else
		{
			itt = size - itt;
			while (itt-- > 0)
				ft_push_rrb(stack);
			ft_push_pa(stack);
		}
		size--;
	}
}
