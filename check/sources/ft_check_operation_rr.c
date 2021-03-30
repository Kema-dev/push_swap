/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_operation_rr.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjourdan <jjourdan@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 13:08:22 by jjourdan          #+#    #+#             */
/*   Updated: 2021/03/24 10:45:29 by jjourdan         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ft_check_rra(t_stack *stack)
{
	t_dish	*buf;
	t_dish	*buf_2;

	if ((stack->a) && (stack->a->next))
	{
		buf = stack->a;
		while (buf->next->next)
			buf = buf->next;
		buf_2 = buf->next;
		buf->next = NULL;
		buf_2->next = stack->a;
		stack->a = buf_2;
	}
}

void	ft_check_rrb(t_stack *stack)
{
	t_dish	*buf;
	t_dish	*buf_2;

	if ((stack->b) && (stack->b->next))
	{
		buf = stack->b;
		while (buf->next->next)
			buf = buf->next;
		buf_2 = buf->next;
		buf->next = NULL;
		buf_2->next = stack->b;
		stack->b = buf_2;
	}
}

void	ft_check_rrr(t_stack *stack)
{
	t_dish	*buf;
	t_dish	*buf_2;

	if ((stack->a) && (stack->a->next))
	{
		buf = stack->a;
		while (buf->next->next)
			buf = buf->next;
		buf_2 = buf->next;
		buf->next = NULL;
		buf_2->next = stack->a;
		stack->a = buf_2;
	}
	if ((stack->b) && (stack->b->next))
	{
		buf = stack->b;
		while (buf->next->next)
			buf = buf->next;
		buf_2 = buf->next;
		buf->next = NULL;
		buf_2->next = stack->b;
		stack->b = buf_2;
	}
}
