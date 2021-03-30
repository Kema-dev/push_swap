/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjourdan <jjourdan@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 11:28:31 by jjourdan          #+#    #+#             */
/*   Updated: 2021/03/30 10:46:36 by jjourdan         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../../libs/libkema/includes/libkema.h"

# define SUCCESS		0
# define FAILURE		-1
# define NO_LIST		-2
# define INVALID_LIST	-3

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

// ? ft_push_list_manip.c
void		ft_push_print_stack(t_dish *dish);
t_dish		*ft_push_lstnew(t_list *mem, int content);
t_commands	*ft_push_command_lstnew(t_list *mem, char *text);
void		ft_push_lstadd_back(t_dish **alst, t_dish *new);
void		ft_push_command_lstadd_back(t_commands **alst, t_commands *new);

// ? ft_push_operation_s.c
void		ft_push_sa(t_stack *stack);
void		ft_push_sb(t_stack *stack);
void		ft_push_ss(t_stack *stack);

// ? ft_push_operation_p.c
void		ft_push_pa(t_stack *stack);
void		ft_push_pb(t_stack *stack);

// ? ft_push_operation_r.c
void		ft_push_ra(t_stack *stack);
void		ft_push_rb(t_stack *stack);
void		ft_push_rr(t_stack *stack);

// ? ft_push_operation_rr.c
void		ft_push_rra(t_stack *stack);
void		ft_push_rrb(t_stack *stack);
void		ft_push_rrr(t_stack *stack);

// ? ft_push_get_commands.c
t_commands	*ft_push_get_commands(t_list *mem, t_commands *command);

#endif