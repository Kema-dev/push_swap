/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_to_b.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjourdan <jjourdan@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 11:00:49 by jjourdan          #+#    #+#             */
/*   Updated: 2021/04/07 12:06:19 by jjourdan         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push_0_x1_to_b(t_info *info, t_stack *stack)
{
	int	size;

	size = info->group_1_size;
	while (size > 0)
	{
		if ((stack->a->value >= info->group_1_low) && (stack->a->value <= info->group_1_high))
		{
			ft_push_pb(stack);
			size--;
		}
		else
			ft_push_rra(stack);
	}
}

int		ft_push_find_idx(t_dish *dish, int value)
{
	t_dish	*buf;
	size_t	i;

	buf = dish;
	i = 0;
	while (buf)
	{
		if (buf->value == value)
			break;
		i++;
		buf = buf->next;
	}
	return (i);
}

void	ft_push_b_to_a(t_list *mem, t_stack *stack)
{
	int	itt;
	int	*tab;
	int	size;

	itt = 0;
	size = ft_push_lstsize(stack->b);
	tab = ft_push_list_to_tab(mem, stack->b, size);
	ft_push_sort_tab(tab, size);
	while (size > 0)
	{
		itt = ft_push_find_idx(stack->b, tab[size - 1]);
		if (itt < size / 2)
		{
			while (itt-- > 0)
				ft_push_rb(stack);
			ft_push_pa(stack);
		}
		else
		{
			itt = size - itt;
			while (itt-- > 0)
				ft_push_rrb(stack);
			ft_push_pa(stack);
		}
		size--;
	}
}

void	ft_push_x2_max_to_b(t_info *info, t_stack *stack)
{
	size_t	sigma_idx;
	t_dish	*buf;
	size_t	i;
	size_t	nb_pushed;

	buf = stack->a;
	sigma_idx = 0;
	i = 0;
	while (buf)
	{
		if ((buf->value > info->group_3_low) && (buf->value \
					< info->group_3_high))
			sigma_idx += i;
		i++;
		buf = buf->next;
	}
	if (((info->nb / 3) * (info->nb / 2) - sigma_idx) > 0)
		info->group_3_dir = true;
	else
		info->group_3_dir = false;
	nb_pushed = 0;
	while (nb_pushed < info->group_3_size)
	{
		if ((stack->a->value >= info->group_3_low) && (stack->a->value \
					<= info->group_3_high))
		{
			ft_push_pb(stack);
			nb_pushed++;
		}
		else if (info->group_3_dir == true)
			ft_push_ra(stack);
		else
			ft_push_rra(stack);
	}
}
