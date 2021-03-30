/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjourdan <jjourdan@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 10:38:50 by jjourdan          #+#    #+#             */
/*   Updated: 2021/03/30 14:12:14 by jjourdan         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	ssize_t		i;
	int			nb;
	t_stack		*stack;
	t_list		*mem;

	if (argc < 2)
		exit(ft_kema_error(NO_LIST, &mem, &free));
	stack = kemalloc_exit(&mem, 1, sizeof(t_stack));
	stack->a = NULL;
	stack->b = NULL;
	i = 0;
	while (++i < argc)
	{
		nb = ft_atoi(argv[i]);
		if ((nb == 0) && (argv[i][0] != '0'))
			exit(ft_kema_error(INVALID_LIST, &mem, &free));
		ft_push_lstadd_back(&stack->a, ft_push_lstnew(mem, nb));
	}
	ft_push_chose_algo(mem, stack);
	exit(ft_kema_error(SUCCESS, &mem, &free));
}
