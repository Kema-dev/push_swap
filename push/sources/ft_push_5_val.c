/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_5_val.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjourdan <jjourdan@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 13:52:41 by jjourdan          #+#    #+#             */
/*   Updated: 2021/03/31 14:45:57 by jjourdan         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push_5_val(t_list *mem, t_stack *stack)
{
	tab = ft_push_list_to_tab(mem, stack, ft_push_lstsize(stack->a));
	while (ft_push_lstsize(stack->a) > 3)
		ft_push_pb(stack);
	ft_push_3_val(stack, tab);
	if (stack->b->next)
		if (stack->b->value < stack->b->next->value)
			ft_push_sb(stack);
}