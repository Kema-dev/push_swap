/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_to_b.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjourdan <jjourdan@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 11:00:49 by jjourdan          #+#    #+#             */
/*   Updated: 2021/04/06 13:00:41 by jjourdan         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push_x2_max_to_b(t_info *info, t_stack *stack)
{
	size_t	sigma_idx;
	t_dish	*buf;
	size_t	i;
	size_t	nb_pushed;

	buf = stack->a;
	sigma_idx = 0;
	i = 0;
	while (buf)
	{
		if ((buf->value > info->group_3_low) && (buf->value \
					< info->group_3_high))
			sigma_idx += i;
		i++;
		buf = buf->next;
	}
	if (((info->nb / 3) * (info->nb / 2) - sigma_idx) > 0)
		info->group_3_dir = true;
	else
		info->group_3_dir = false;
	nb_pushed = 0;
	//while (nb_pushed < info->group_3_size)
	//{
	//	if ((stack->a->value > info->group_3_low) && (stack->a->value \
	//				< info->group_3_high))
	//	{
	//		ft_push_pb(stack);
	//		nb_pushed++;
	//	}
	//	else if (info->group_3_dir == true)
	//		ft_push_ra(stack);
	//	else
	//		ft_push_rra(stack);
	//}
}
