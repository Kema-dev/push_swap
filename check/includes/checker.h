/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjourdan <jjourdan@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 11:28:31 by jjourdan          #+#    #+#             */
/*   Updated: 2021/03/30 10:51:31 by jjourdan         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "../../libs/libkema/includes/libkema.h"

typedef struct s_dish {
	int				value;
	struct s_dish	*next;
}	t_dish;

typedef struct s_stack {
	struct s_dish	*a;
	struct s_dish	*b;
}	t_stack;

typedef struct s_commands {
	char				*value;
	struct s_commands	*next;
}	t_commands;

// ? main.c
int			main(int argc, char **argv);

// ? ft_check_list_manip.c
void		ft_check_print_stack(t_dish *dish);
t_dish		*ft_check_lstnew(t_list *mem, int content);
t_commands	*ft_check_command_lstnew(t_list *mem, char *text);
void		ft_check_lstadd_back(t_dish **alst, t_dish *new);
void		ft_check_command_lstadd_back(t_commands **alst, t_commands *new);

// ? ft_check_operation_s.c
void		ft_check_sa(t_stack *stack);
void		ft_check_sb(t_stack *stack);
void		ft_check_ss(t_stack *stack);

// ? ft_check_operation_p.c
void		ft_check_pa(t_stack *stack);
void		ft_check_pb(t_stack *stack);

// ? ft_check_operation_r.c
void		ft_check_ra(t_stack *stack);
void		ft_check_rb(t_stack *stack);
void		ft_check_rr(t_stack *stack);

// ? ft_check_operation_rr.c
void		ft_check_rra(t_stack *stack);
void		ft_check_rrb(t_stack *stack);
void		ft_check_rrr(t_stack *stack);

// ? ft_check_get_commands.c
void		ft_check_apply_commands(t_list *mem, t_stack *stack, t_commands *command);
int			ft_check_order(t_list *mem, t_stack *stack, t_commands *commands);
t_commands	*ft_check_get_commands(t_list *mem, t_commands *command);

#endif