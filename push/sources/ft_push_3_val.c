/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_3_val.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjourdan <jjourdan@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 15:12:11 by jjourdan          #+#    #+#             */
/*   Updated: 2021/03/30 16:31:36 by jjourdan         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_push_3_push_top(t_stack *stack)
{
	t_dish	*buf;
	int		idx;
	int		max;
	int		i;

	buf = stack->a;
	idx = 0;
	max = 0;
	i = 0;
	while (buf)
	{
		if (buf->value > max)
		{
			max = buf->value;
			idx = i;
		}
		i++;
		buf = buf->next;
	}
	while (--i > idx)
		ft_push_ra(stack);
	ft_push_pb(stack);
}

void	ft_push_3_val(t_list *mem, t_stack *stack)
{
	while (ft_push_lstsize(stack->a) > 1)
		ft_push_3_push_top(stack);
	while (ft_push_lstsize(stack->b) > 0)
		ft_push_pa(stack);
	(void)mem;
}
