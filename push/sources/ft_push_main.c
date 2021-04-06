/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjourdan <jjourdan@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 10:38:50 by jjourdan          #+#    #+#             */
/*   Updated: 2021/04/06 11:38:19 by jjourdan         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_push_check_duplicates(int nb, t_dish *a)
{
	t_dish	*buf;

	buf = a;
	while (buf)
	{
		if (buf->value == nb)
			return (FAILURE);
		buf = buf->next;
	}
	return (SUCCESS);
}

int	ft_push_check_arg(char **argv)
{
	ssize_t	i;
	ssize_t	j;

	i = 0;
	while (argv[++i])
	{
		j = -1;
		if (((argv[i][0] > '9') || (argv[i][0] < '0')) && (argv[i][0] != '-'))
			return (FAILURE);
		while (argv[i][++j])
		{
			if ((argv[i][j] > '9') || (argv[i][j] < '0'))
				return (FAILURE);
		}
	}
	return (SUCCESS);
}

int	main(int argc, char **argv)
{
	ssize_t		i;
	int			nb;
	t_stack		*stack;
	t_list		*mem;

	if (argc < 2)
		exit(ft_kema_error(NO_LIST, &mem, &free, NO_PRINT));
	if (ft_push_check_arg(argv) != SUCCESS)
		exit(ft_kema_error(INVALID_LIST, &mem, &free, NO_PRINT));
	stack = kemalloc_exit(&mem, 1, sizeof(t_stack), NO_PRINT);
	stack->a = NULL;
	stack->b = NULL;
	i = 0;
	while (++i < argc)
	{
		nb = ft_atoi(argv[i]);
		if ((nb == 0) && (argv[i][0] != '0'))
			exit(ft_kema_error(INVALID_LIST, &mem, &free, NO_PRINT));
		if (ft_push_check_duplicates(nb, stack->a) != SUCCESS)
			exit(ft_kema_error(DUPLICATE, &mem, &free, NO_PRINT));
		ft_push_lstadd_back(&stack->a, ft_push_lstnew(mem, nb));
	}
	ft_push_chose_algo(mem, stack);
	exit(ft_kema_error(SUCCESS, &mem, &free, NO_PRINT));
}
