/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_5_val.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjourdan <jjourdan@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 13:52:41 by jjourdan          #+#    #+#             */
/*   Updated: 2021/04/01 10:56:48 by jjourdan         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_push_find_idx(int *tab, int *full)
{
	ssize_t	i;
	ssize_t	j;
	bool	ret;

	i = -1;
	while (full[++i])
	{
		j = -1;
		while (tab[++j])
			if (tab[i] == full[j]) ret = true;
		if (ret == false)
			return (i);
	}
	return (i);
}

void	ft_push_sort_tab(int *tab)
{
	size_t	i;
	int		buf;

	i = 0;
	while (tab[i + 1])
	{
		if (tab[i] > tab[i + 1])
		{
			buf = tab[i];
			tab[i] = tab[i + 1];
			tab[i + 1] = buf;
		}
		else
			i++;
	}
}

void	ft_push_5_val(t_list *mem, t_stack *stack, int *full)
{
	int	*tab;

	(void)full;
	while (ft_push_lstsize(stack->a) > 3)
		ft_push_pb(stack);
	tab = ft_push_list_to_tab(mem, stack, ft_push_lstsize(stack->a));
	ft_push_3_val(stack, tab);
	if (stack->b->next)
		if (stack->b->value < stack->b->next->value)
			ft_push_sb(stack);
	ft_dprintf(STDOUT_FILENO, "STACK A:\n"); // ! TO BE REMOVED
	ft_push_print_stack(stack->a); // ! TO BE REMOVED
	ft_dprintf(STDOUT_FILENO, "STACK B:\n"); // ! TO BE REMOVED
	ft_push_print_stack(stack->b); // ! TO BE REMOVED
	free(tab);
}
