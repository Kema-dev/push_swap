/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_main.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjourdan <jjourdan@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 10:38:50 by jjourdan          #+#    #+#             */
/*   Updated: 2021/06/04 11:06:50 by jjourdan         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	ft_check_check_duplicates(int nb, t_dish *a)
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

int	ft_check_check_arg(char **argv)
{
	ssize_t	i;
	ssize_t	j;

	i = 0;
	while (argv[++i])
	{
		j = -1;
		if (((argv[i][0] > '9') || (argv[i][0] < '0')) && (argv[i][0] != '-'))
			return (FAILURE);
		if (argv[i][0] == '-')
			j++;
		while (argv[i][++j])
		{
			if ((argv[i][j] > '9') || (argv[i][j] < '0'))
				return (FAILURE);
		}
	}
	return (SUCCESS);
}

void	ft_check_free_command(t_commands **command)
{
	t_commands	*buf;

	buf = *command;
	while (buf)
	{
		free(buf->value);
		buf = buf->next;
	}
}

int	main_pt_2(t_stack *stack, t_list **mem, char **arg)
{
	t_commands	*command;
	int			return_value;
	ssize_t		i;
	int			nb;

	stack = kemalloc_exit(mem, 1, sizeof(t_stack), PRINT);
	stack->a = NULL;
	stack->b = NULL;
	i = -1;
	while (arg[++i])
	{
		nb = ft_atoi(arg[i]);
		if ((nb == 0) && (arg[i][0] != '0'))
			exit(ft_kema_error(INVALID_LIST, mem, &free, PRINT));
		if (ft_check_check_duplicates(nb, stack->a) != SUCCESS)
			exit(ft_kema_error(DUPLICATE, mem, &free, PRINT));
		ft_check_lstadd_back(&stack->a, ft_check_lstnew(mem, nb));
	}
	command = NULL;
	command = ft_check_get_commands(mem, command);
	return_value = ft_check_order(mem, stack, command);
	ft_check_free_command(&command);
	return (return_value);
}

int	main(int argc, char **argv)
{
	ssize_t		i;
	t_stack		*stack;
	t_list		*mem;
	char		**arg;
	char		*str;

	mem = NULL;
	stack = NULL;
	if (argc < 2)
		exit(ft_kema_error(NO_LIST, &mem, &free, PRINT));
	i = 0;
	str = NULL;
	while (argv[++i])
	{
		str = ft_check_strjoin(str, argv[i]);
		str = ft_check_strjoin(str, " ");
	}
	arg = ft_check_split(&mem, str, ' ');
	free(str);
	if (ft_check_check_arg(arg) != SUCCESS)
		exit(ft_kema_error(INVALID_LIST, &mem, &free, PRINT));
	exit(ft_kema_error(main_pt_2(stack, &mem, arg), \
			&mem, &free, PRINT));
}
