/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_sort_values.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjourdan <jjourdan@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 14:06:56 by jjourdan          #+#    #+#             */
/*   Updated: 2021/03/30 14:08:55 by jjourdan         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push_finish_rotate(t_info *info, t_stack *stack)
{
	while (info->group_1_size > 0)
	{
		ft_push_rra(stack);
		info->group_1_size--;
	}
}

void	ft_push_g2(t_info *info, t_stack *stack)
{
	while (info->group_2_size > 0)
	{
		if ((stack->a->value >= info->group_2_low) && (stack->a->value <= info->group_2_high))
		{
			ft_push_pb(stack);
			info->group_2_size--;
		}
		else
			ft_push_rra(stack);
	}
}

int	ft_push_lstsize(t_dish *dish)
{
	size_t	size;
	t_dish	*buf;

	size = 0;
	buf = dish;
	while (buf)
	{
		size++;
		buf = buf->next;
	}
	return (size);
}

int	*ft_push_list_to_tab(t_list *mem, t_dish *dish, size_t size)
{
	int		*tab;
	int		i;
	t_dish	*buf;

	tab = kemalloc_exit(&mem, size, sizeof(int), NO_PRINT);
	i = 0;
	buf = dish;
	while (buf)
	{
		tab[i] = buf->value;
		i++;
		buf = buf->next;
	}
	return (tab);
}

void	ft_push_chose_algo(t_list *mem, t_stack *stack)
{
	t_info	*info;
	size_t	size;
	int		*tab;

	size = ft_push_lstsize(stack->a);
	tab = ft_push_list_to_tab(mem, stack->a, size);
	if (size <= 3)
	{
		ft_push_3_val(stack, tab);
		return ;
	}
	info = kemalloc_exit(&mem, 1, sizeof(t_info), NO_PRINT);
	info->nb = size;
	ft_push_get_infos(tab, info);
	ft_push_x2_max_to_b(info, stack);
	ft_push_b_to_a(mem, stack);
	ft_push_0_x1_to_b(info, stack);
	ft_push_b_to_a(mem, stack);
	ft_push_g2(info, stack);
	ft_push_b_to_a(mem, stack);
	// ! ft_dprintf(STDOUT_FILENO, "STACK A:\n");
	// ! ft_push_print_stack(stack->a);
	// ! ft_dprintf(STDOUT_FILENO, "STACK B:\n");
	// ! ft_push_print_stack(stack->b);
	// ! ft_dprintf(STDOUT_FILENO, "\n\n");
	ft_push_finish_rotate(info, stack);
	// ! ft_dprintf(STDOUT_FILENO, "STACK A:\n");
	// ! ft_push_print_stack(stack->a);
	// ! ft_dprintf(STDOUT_FILENO, "STACK B:\n");
	// ! ft_push_print_stack(stack->b);
	// ! ft_dprintf(STDOUT_FILENO, "nb:%d\n", info->nb);
}
