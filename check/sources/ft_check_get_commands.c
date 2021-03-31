/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_get_commands.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjourdan <jjourdan@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 09:47:34 by jjourdan          #+#    #+#             */
/*   Updated: 2021/03/31 13:23:02 by jjourdan         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ft_check_apply_commands(t_list *mem, t_stack *stack, t_commands *command)
{
	t_commands	*buf;

	buf = command;
	while (buf)
	{
		if (ft_strncmp("sa", buf->value, 3) == 0)
			ft_check_sa(stack);
		else if (ft_strncmp("sb", buf->value, 3) == 0)
			ft_check_sb(stack);
		else if (ft_strncmp("ss", buf->value, 3) == 0)
			ft_check_ss(stack);
		else if (ft_strncmp("pa", buf->value, 3) == 0)
			ft_check_pa(stack);
		else if (ft_strncmp("pb", buf->value, 3) == 0)
			ft_check_pb(stack);
		else if (ft_strncmp("ra", buf->value, 3) == 0)
			ft_check_ra(stack);
		else if (ft_strncmp("rb", buf->value, 3) == 0)
			ft_check_rb(stack);
		else if (ft_strncmp("rr", buf->value, 3) == 0)
			ft_check_rr(stack);
		else if (ft_strncmp("rra", buf->value, 4) == 0)
			ft_check_rra(stack);
		else if (ft_strncmp("rrb", buf->value, 4) == 0)
			ft_check_rrb(stack);
		else if (ft_strncmp("rrr", buf->value, 4) == 0)
			ft_check_rrr(stack);
		else
			exit(ft_kema_error(WRONG_COMMAND, &mem, &free, PRINT));
		buf = buf->next;
	}
}

int	ft_check_order(t_list *mem, t_stack *stack, t_commands *commands)
{
	t_dish	*buf;
	int		return_value;

	return_value = SUCCESS;
	ft_check_apply_commands(mem, stack, commands);
	if (stack->b)
		return_value = STACK_B_NOT_EMPTY;
	buf = stack->a;
	while (buf->next)
	{
		if (buf->value > buf->next->value)
			return_value = WRONG_ORDER;
		buf = buf->next;
	}
	return (return_value);
}

t_commands	*ft_check_get_commands(t_list *mem, t_commands *command)
{
	char	*text;
	size_t	i;

	i = 0;
	while (get_next_line(STDIN_FILENO, &text))
	{
		if (!text)
			exit(ft_kema_error(NO_COMMAND, &mem, &free, PRINT));
		ft_check_command_lstadd_back(&command, ft_check_command_lstnew(mem, text));
		i++;
	}
	return (command);
}
