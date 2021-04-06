/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_sort_values.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjourdan <jjourdan@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 14:06:56 by jjourdan          #+#    #+#             */
/*   Updated: 2021/03/30 14:08:55 by jjourdan         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_push_lstsize(t_dish *dish)
{
	size_t	size;
	t_dish	*buf;

	size = 0;
	buf = dish;
	while (buf)
	{
		size++;
		buf = buf->next;
	}
	return (size);
}

int		*ft_push_list_to_tab(t_list *mem, t_stack *stack, size_t size)
{
	int		*tab;
	int		i;
	t_dish	*buf;

	tab = kemalloc_exit(&mem, size, sizeof(int), NO_PRINT);
	i = 0;
	buf = stack->a;
	while (buf)
	{
		tab[i++] = buf->value;
		buf = buf->next;
	}
	return (tab);
}

void	ft_push_chose_algo(t_list *mem, t_stack *stack)
{
	t_info	*info;
	size_t	size;
	int		*tab;

	size = ft_push_lstsize(stack->a);
	tab = ft_push_list_to_tab(mem, stack, size);
	if (size <= 3)
	{
		ft_push_3_val(stack, tab);
		return ;
	}
	info = ft_push_get_infos(mem, tab);
	ft_push_x2_max_to_b(info, stack);
	ft_push_to_a(stack);
	ft_push_min_x1_to_b(info, stack);
	ft_push_to_a(stack);
	ft_push_finish_rotate(info, stack);
}
