/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_operation_p.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjourdan <jjourdan@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 12:36:25 by jjourdan          #+#    #+#             */
/*   Updated: 2021/03/24 10:45:28 by jjourdan         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ft_check_pa(t_stack *stack)
{
	t_dish	*buf;

	if (stack->b)
	{
		buf = stack->b->next;
		stack->b->next = stack->a;
		stack->a = stack->b;
		stack->b = buf;
	}
}

void	ft_check_pb(t_stack *stack)
{
	t_dish	*buf;

	if (stack->a)
	{
		buf = stack->a->next;
		stack->a->next = stack->b;
		stack->b = stack->a;
		stack->a = buf;
	}
}
