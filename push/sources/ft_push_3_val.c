/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_3_val.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjourdan <jjourdan@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 15:12:11 by jjourdan          #+#    #+#             */
/*   Updated: 2021/06/04 11:57:19 by jjourdan         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_push_check_sort(t_dish *val)
{
	t_dish	*buf;

	buf = val;
	while (buf->next)
	{
		if (buf->value > buf->next->value)
			return (FAILURE);
		buf = buf->next;
	}
	return (SUCCESS);
}

void	ft_push_3_val(t_stack *stack, int *tab, int size)
{
	if (ft_push_check_sort(stack->a) == SUCCESS)
		;
	else if (size <= 2)
	{
		if (tab[0] > tab[1])
			ft_push_sa(stack);
	}
	else if ((tab[0] > tab[1]) && (tab[0] < tab[2]))
		ft_push_sa(stack);
	else if ((tab[0] > tab[1]) && (tab[1] > tab[2]))
	{
		ft_push_sa(stack);
		ft_push_rra(stack);
	}
	else if ((tab[0] > tab[2]) && (tab[2] > tab[1]))
		ft_push_ra(stack);
	else if ((tab[1] > tab[2]) && (tab[2] > tab[0]))
	{
		ft_push_sa(stack);
		ft_push_ra(stack);
	}
	else
		ft_push_rra(stack);
}
