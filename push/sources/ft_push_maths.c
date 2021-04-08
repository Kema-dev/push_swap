/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_maths.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjourdan <jjourdan@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 15:46:00 by jjourdan          #+#    #+#             */
/*   Updated: 2021/04/08 15:08:46 by jjourdan         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push_5_val(t_list *mem, t_stack *stack)
{
	int	itt;
	int	*tab;
	int	i;
	int	size;

	tab = ft_push_list_to_tab(mem, stack->a, ft_push_lstsize(stack->a));
	ft_push_sort_tab(tab, ft_push_lstsize(stack->a));
	itt = 0;
	size = ft_push_lstsize(stack->a);
	i = 0;
	while (size > 3)
	{
		itt = ft_push_find_idx(stack->a, tab[i++]);
		if (itt < size / 2)
		{
			while (itt-- > 0)
				ft_push_ra(stack);
			ft_push_pb(stack);
		}
		else
		{
			itt = size - itt;
			while (itt-- > 0)
				ft_push_rra(stack);
			ft_push_pb(stack);
		}
		size--;
	}
	free(tab);
	size = ft_push_lstsize(stack->a);
	tab = ft_push_list_to_tab(mem, stack->a, size);
	ft_push_3_val(stack, tab);
	ft_push_b_to_a(mem, stack);
}

int	ft_push_get_sqrt(int nb)
{
	int	sqrt;

	sqrt = 0;
	while (sqrt * sqrt < nb)
		sqrt++;
	return (sqrt);
}

void	ft_push_250_max(int *tab, t_list *mem, t_info *info, t_stack *stack)
{
	t_group	*group;
	int		i;

	group = NULL;
	i = 0;
	while (i < info->nb_grps)
	{
		ft_push_group_lstadd_back(&group, ft_push_group_lstnew(mem, tab[i *info->grp_size], \
				tab[(i + 1) *info->grp_size - 1], info->grp_size));
		i++;
	}
	ft_push_group_lstadd_back(&group, ft_push_group_lstnew(mem, tab[i * info->grp_size], \
			tab[info->nb - 1], info->nb - i * info->grp_size));
	i = 0;
	while (i < info->nb_grps)
	{
		ft_push_sort_group(info, group, stack);
		group = group->next;
		i++;
	}
	ft_push_sort_group(info, group, stack);
	ft_push_b_to_a(mem, stack);
}

void	ft_push_sort_group(t_info *info, t_group *group, t_stack *stack)
{
	int		nb_pushed;

	(void)info;
	group->dir = false;
	nb_pushed = 0;
	while (nb_pushed < group->size)
	{
		if ((stack->a->value >= group->min) && (stack->a->value \
					<= group->max))
		{
			ft_push_pb(stack);
			nb_pushed++;
		}
		else if (group->dir == true)
			ft_push_ra(stack);
		else
			ft_push_rra(stack);
	}
}
