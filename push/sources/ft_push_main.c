/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjourdan <jjourdan@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 10:38:50 by jjourdan          #+#    #+#             */
/*   Updated: 2021/04/09 12:53:00 by jjourdan         ###   ########lyon.fr   */
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

char	*ft_push_strjoin(char *s1, char const *s2)
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

int	main(int argc, char **argv)
{
	ssize_t		i;
	int			nb;
	t_stack		*stack;
	t_list		*mem;
	char		**arg;
	char		*str;

	mem = NULL;
	if (argc < 2)
		exit(ft_kema_error(NO_LIST, &mem, &free, NO_PRINT));
	i = 0;
	str = NULL;
	while (argv[++i])
	{
		str = ft_push_strjoin(str, argv[i]);
		str = ft_push_strjoin(str, " ");
	}
	arg = ft_push_split(&mem, str, ' ');
	free(str);
	if (ft_push_check_arg(arg) != SUCCESS)
		exit(ft_kema_error(INVALID_LIST, &mem, &free, NO_PRINT));
	stack = kemalloc_exit(&mem, 1, sizeof(t_stack), NO_PRINT);
	stack->a = NULL;
	stack->b = NULL;
	i = -1;
	while (arg[++i])
	{
		nb = ft_atoi(arg[i]);
		if ((nb == 0) && (arg[i][0] != '0'))
			exit(ft_kema_error(INVALID_LIST, &mem, &free, NO_PRINT));
		if (ft_push_check_duplicates(nb, stack->a) != SUCCESS)
			exit(ft_kema_error(DUPLICATE, &mem, &free, NO_PRINT));
		ft_push_lstadd_back(&stack->a, ft_push_lstnew(&mem, nb));
	}
	if (ft_push_check_sort(stack->a) == SUCCESS)
		exit(ft_kema_error(SUCCESS, &mem, &free, NO_PRINT));
	ft_push_chose_algo(&mem, stack);
	//ft_dprintf(STDOUT_FILENO, "STACK A:\n");
	//ft_push_print_stack(stack->a);
	//ft_dprintf(STDOUT_FILENO, "STACK B:\n");
	//ft_push_print_stack(stack->b);
	exit(ft_kema_error(SUCCESS, &mem, &free, NO_PRINT));
}
