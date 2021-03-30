/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_operation_r.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjourdan <jjourdan@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 12:55:36 by jjourdan          #+#    #+#             */
/*   Updated: 2021/03/23 14:09:41 by jjourdan         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ft_check_ra(t_stack *stack)
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

void	ft_check_rb(t_stack *stack)
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

void	ft_check_rr(t_stack *stack)
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
