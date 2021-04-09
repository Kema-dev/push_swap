/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_main.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjourdan <jjourdan@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 10:38:50 by jjourdan          #+#    #+#             */
/*   Updated: 2021/04/09 12:34:07 by jjourdan         ###   ########lyon.fr   */
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

char	*ft_check_strjoin(char *s1, char const *s2)
{
	size_t	tot_len;
	char	*out;

	tot_len = ft_strlen(s1) + ft_strlen(s2);
	out = ft_calloc(sizeof(char), (tot_len + 1));
	if (!out)
		return (NULL);
	ft_strcat(out, (char *)s1);
	ft_strcat(out, (char *)s2);
	free(s1);
	return (out);
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

int	main(int argc, char **argv)
{
	ssize_t		i;
	t_stack		*stack;
	t_commands	*command;
	t_list		*mem;
	int			return_value;
	int			nb;
	char		**arg;
	char		*str;

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
	if (ft_check_check_arg(arg) != SUCCESS)
		exit(ft_kema_error(INVALID_LIST, &mem, &free, PRINT));
	stack = kemalloc_exit(&mem, 1, sizeof(t_stack), PRINT);
	stack->a = NULL;
	stack->b = NULL;
	i = -1;
	while (arg[++i])
	{
		nb = ft_atoi(arg[i]);
		if ((nb == 0) && (arg[i][0] != '0'))
			exit(ft_kema_error(INVALID_LIST, &mem, &free, PRINT));
		if (ft_check_check_duplicates(nb, stack->a) != SUCCESS)
			exit(ft_kema_error(DUPLICATE, &mem, &free, PRINT));
		ft_check_lstadd_back(&stack->a, ft_check_lstnew(&mem, nb));
	}
	command = NULL;
	command = ft_check_get_commands(&mem, command);
	return_value = ft_check_order(&mem, stack, command);
	// ! ft_check_print_stack(stack->a);
	ft_check_free_command(&command);
	exit(ft_kema_error(return_value, &mem, &free, PRINT));
}
