/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_main.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjourdan <jjourdan@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 10:38:50 by jjourdan          #+#    #+#             */
/*   Updated: 2021/03/30 10:50:59 by jjourdan         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	main(int argc, char **argv)
{
	ssize_t		i;
	t_stack		*stack;
	t_commands	*command;
	t_list		*mem;
	int			return_value;
	int			nb;

	if (argc < 2)
		exit(ft_kema_error(NO_LIST, &mem, &free));
	stack = kemalloc(&mem, 1, sizeof(t_stack));
	i = 0;
	stack->a = NULL;
	stack->b = NULL;
	while (++i < argc)
	{
		nb = ft_atoi(argv[i]);
		if ((nb == 0) && (argv[i][0] != '0'))
			exit(ft_kema_error(INVALID_LIST, &mem, &free));
		ft_check_lstadd_back(&stack->a, ft_check_lstnew(mem, nb));
	}
	command = NULL;
	command = ft_check_get_commands(mem, command);
	return_value = ft_check_order(mem, stack, command);
	ft_dprintf(STDOUT_FILENO, "stack a:\n"); // ! TO BE REMOVED
	ft_check_print_stack(stack->a); // ! TO BE REMOVED
	ft_dprintf(STDOUT_FILENO, "stack b:\n"); // ! TO BE REMOVED
	ft_check_print_stack(stack->b); // ! TO BE REMOVED
	exit(ft_kema_error(return_value, &mem, &free));
}
