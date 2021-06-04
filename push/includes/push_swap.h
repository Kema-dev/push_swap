/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjourdan <jjourdan@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 11:28:31 by jjourdan          #+#    #+#             */
/*   Updated: 2021/06/04 11:57:31 by jjourdan         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

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

typedef struct s_group {
	int					min;
	int					max;
	int					size;
	bool				dir;
	struct s_group		*next;
}	t_group;

typedef struct s_info {
	int		min;
	int		max;
	int		nb;
	int		nb_grps;
	int		grp_size;
}	t_info;

// ? main.c
char		*ft_push_strjoin(char *s1, char const *s2);
int			ft_push_check_arg(char **argv);
void		main_pt_2(t_stack *stack, t_list **mem, char **arg);
int			main(int argc, char **argv);

// ? ft_push_list_manip.c
void		ft_push_print_stack(t_dish *dish);
t_dish		*ft_push_lstnew(t_list **mem, int content);
t_commands	*ft_push_command_lstnew(t_list **mem, char *text);
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
t_commands	*ft_push_get_commands(t_list **mem, t_commands *command);

// ? ft_push_get_stack_size.c
void		ft_push_get_stack_size(t_list **mem, t_stack *stack);

// ? ft_push_sort_values.c
int			ft_push_lstsize(t_dish *dish);
int			*ft_push_list_to_tab(t_list **mem, t_dish *dish, size_t size);
void		ft_push_chose_algo(t_list **mem, t_stack *stack);

// ? ft_push_3_val.c
int			ft_push_check_sort(t_dish *val);
void		ft_push_3_val(t_stack *stack, int *tab, int size);

// ? ft_push_get_infos.c
void		ft_push_sort_tab(int *tab, int size);

// ? ft_push_to_b.c
int			ft_push_find_idx(t_dish *dish, int value);
void		ft_push_b_to_a_pt_2(int size, int itt, t_stack *stack, int *tab);
void		ft_push_b_to_a(t_list **mem, t_stack *stack);

// ? ft_push_maths.c
void		ft_push_5_val_pt_2(int size, int itt, int i, t_stack *stack, int *tab);
void		ft_push_5_val(t_list **mem, t_stack *stack);
int			ft_push_get_sqrt(int nb);
void		ft_push_250_max(int *tab, t_list **mem, t_info *info, \
					t_stack *stack);
void		ft_push_sort_group(t_info *info, t_group *group, t_stack *stack);

// ? ft_push_grp_manip.c
t_group		*ft_push_group_lstnew(t_list **mem, int min, int max, \
					int group_size);
void		ft_push_group_lstadd_back(t_group **alst, t_group *new);
void		ft_push_group_lstadd_front(t_group **alst, t_group *new);

// ? ft_push_split.c
char		**ft_push_split(t_list **mem, char const *s, char c);

#endif