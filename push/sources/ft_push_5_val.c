/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_5_val.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjourdan <jjourdan@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 13:52:41 by jjourdan          #+#    #+#             */
/*   Updated: 2021/03/31 14:38:06 by jjourdan         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push_5_val(t_list *mem, t_stack *stack, int *tab)
{
	(void)mem;
	(void)tab;
	while (ft_push_lstsize(stack->a) > 3)
		ft_push_pb(stack);
	ft_push_3_val(stack, tab);
	if (stack->b->next)
		if (stack->b->value < stack->b->next->value)
			ft_push_sb(stack);
}