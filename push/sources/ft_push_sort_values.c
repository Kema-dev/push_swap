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

void	ft_push_chose_algo(t_list *mem, t_stack *stack)
{
	size_t	size;

	size = ft_push_lstsize(stack->a);
	if (size <= 3)
		ft_push_3_val(mem, stack);
	(void)mem;
	//else if (size <= 5)
	//{
	//	ft_push_5_val(mem, stack);
	//	ft_push_3_val(mem, stack);
	//}
	//else if (size <= 100)
	//{
	//	ft_push_100_val(mem, stack);
	//	ft_push_5_val(mem, stack);
	//	ft_push_3_val(mem, stack);
	//}
	//else
	//{
	//	ft_push_500_val(mem, stack);
	//	ft_push_100_val(mem, stack);
	//	ft_push_5_val(mem, stack);
	//	ft_push_3_val(mem, stack);
	//}
}
