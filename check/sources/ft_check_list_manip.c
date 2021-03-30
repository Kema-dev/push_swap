/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_list_manip.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjourdan <jjourdan@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 09:47:58 by jjourdan          #+#    #+#             */
/*   Updated: 2021/03/30 10:32:11 by jjourdan         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ft_check_print_stack(t_dish *dish)
{
	t_dish	*buf;

	buf = dish;
	while (buf)
	{
		ft_dprintf(STDOUT_FILENO, "%d\n", buf->value);
		buf = buf->next;
	}
}

t_dish	*ft_check_lstnew(t_list *mem, int content)
{
	t_dish	*lst;

	lst = kemalloc(&mem, 1, sizeof(t_dish));
	lst->value = content;
	lst->next = NULL;
	return (lst);
}

t_commands	*ft_check_command_lstnew(t_list *mem, char *text)
{
	t_commands	*lst;

	lst = kemalloc(&mem, 1, sizeof(t_commands));
	lst->value = text;
	lst->next = NULL;
	return (lst);
}

void	ft_check_lstadd_back(t_dish **alst, t_dish *new)
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

void	ft_check_command_lstadd_back(t_commands **alst, t_commands *new)
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
