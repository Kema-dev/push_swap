/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_operation_s.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjourdan <jjourdan@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 10:49:54 by jjourdan          #+#    #+#             */
/*   Updated: 2021/03/30 15:29:35 by jjourdan         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push_sa(t_stack *stack)
{
	t_dish	*buf;

	if ((stack->a) && (stack->a->next))
	{
		buf = stack->a->next;
		stack->a->next = stack->a->next->next;
		buf->next = stack->a;
		stack->a = buf;
	}
	ft_dprintf(STDOUT_FILENO, "sa\n");
}

void	ft_push_sb(t_stack *stack)
{
	t_dish	*buf;

	if ((stack->b) && (stack->b->next))
	{
		buf = stack->b->next;
		stack->b->next = stack->b->next->next;
		buf->next = stack->b;
		stack->b = buf;
	}
	ft_dprintf(STDOUT_FILENO, "sb\n");
}

void	ft_push_ss(t_stack *stack)
{
	t_dish	*buf;

	if ((stack->a) && (stack->a->next))
	{
		buf = stack->a->next;
		stack->a->next = stack->a->next->next;
		buf->next = stack->a;
		stack->a = buf;
	}
	if ((stack->b) && (stack->b->next))
	{
		buf = stack->b->next;
		stack->b->next = stack->b->next->next;
		buf->next = stack->b;
		stack->b = buf;
	}
	ft_dprintf(STDOUT_FILENO, "ss\n");
}
