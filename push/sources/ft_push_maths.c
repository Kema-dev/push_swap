/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_maths.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjourdan <jjourdan@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 15:46:00 by jjourdan          #+#    #+#             */
/*   Updated: 2021/04/08 12:44:00 by jjourdan         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

	(void)stack;
	group = NULL;
	i = 0;
	while (i < info->nb_grps)
	{
		ft_push_group_lstadd_back(&group, ft_push_group_lstnew(mem, tab[i * info->grp_size], tab[(i + 1) * info->grp_size - 1], info->grp_size));
		i++;
	}
	ft_push_group_lstadd_back(&group, ft_push_group_lstnew(mem, tab[i * info->grp_size], tab[info->nb - 1], info->nb - i * info->grp_size));
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
