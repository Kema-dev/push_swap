/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_list_manip.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjourdan <jjourdan@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 09:47:58 by jjourdan          #+#    #+#             */
/*   Updated: 2021/03/31 13:24:03 by jjourdan         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push_print_stack(t_dish *dish)
{
	t_dish	*buf;

	buf = dish;
	while (buf)
	{
		ft_dprintf(STDIN_FILENO, "%d\n", buf->value);
		buf = buf->next;
	}
}

t_dish	*ft_push_lstnew(t_list *mem, int content)
{
	t_dish	*lst;

	lst = kemalloc_exit(&mem, 1, sizeof(t_dish), NO_PRINT);
	lst->value = content;
	lst->next = NULL;
	return (lst);
}

t_commands	*ft_push_command_lstnew(t_list *mem, char *text)
{
	t_commands	*lst;

	lst = kemalloc_exit(&mem, 1, sizeof(t_commands), NO_PRINT);
	lst->value = text;
	lst->next = NULL;
	return (lst);
}

void	ft_push_lstadd_back(t_dish **alst, t_dish *new)
{
	t_dish	*buf;

	if (!new || !alst)
		return ;
	buf = *alst;
	if (*alst == NULL)
		*alst = new;
	else
	{
		while (buf->next)
			buf = buf->next;
		buf->next = new;
	}
}

void	ft_push_command_lstadd_back(t_commands **alst, t_commands *new)
{
	t_commands	*buf;

	if (!new || !alst)
		return ;
	buf = *alst;
	if (*alst == NULL)
		*alst = new;
	else
	{
		while (buf->next)
			buf = buf->next;
		buf->next = new;
	}
}
