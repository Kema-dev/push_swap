/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_operation_r.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjourdan <jjourdan@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 10:49:59 by jjourdan          #+#    #+#             */
/*   Updated: 2021/03/25 13:04:34 by jjourdan         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push_ra(t_stack *stack)
{
	t_dish	*buf;
	t_dish	*buf_2;

	if ((stack->a) && (stack->a->next))
	{
		buf = stack->a;
		buf_2 = stack->a->next;
		while (buf->next)
			buf = buf->next;
		buf->next = stack->a;
		buf->next->next = NULL;
		stack->a = buf_2;
	}
}

void	ft_push_rb(t_stack *stack)
{	
	t_dish	*buf;
	t_dish	*buf_2;

	if ((stack->b) && (stack->b->next))
	{
		buf = stack->b;
		buf_2 = stack->b->next;
		while (buf->next)
			buf = buf->next;
		buf->next = stack->b;
		buf->next->next = NULL;
		stack->b = buf_2;
	}
}

void	ft_push_rr(t_stack *stack)
{
	t_dish	*buf;
	t_dish	*buf_2;

	if ((stack->a) && (stack->a->next))
	{
		buf = stack->a;
		buf_2 = stack->a->next;
		while (buf->next)
			buf = buf->next;
		buf->next = stack->a;
		buf->next->next = NULL;
		stack->a = buf_2;
	}
	if ((stack->b) && (stack->b->next))
	{
		buf = stack->b;
		buf_2 = stack->b->next;
		while (buf->next)
			buf = buf->next;
		buf->next = stack->b;
		buf->next->next = NULL;
		stack->b = buf_2;
	}
}
