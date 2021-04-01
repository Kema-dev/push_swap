/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_100_val.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjourdan <jjourdan@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 11:26:27 by jjourdan          #+#    #+#             */
/*   Updated: 2021/04/01 14:33:34 by jjourdan         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_push_get_sqrt(int nb)
{
	float	temp;
	float	sqrt;	
	printf("Provide the number: \n");	
	scanf("%d", &number);	
	// store the half of the given number e.g from 256 => 128
	sqrt = number / 2;
	temp = 0;	
	// Iterate until sqrt is different of temp, that is updated on the loop
	while(sqrt != temp){
		// initially 0, is updated with the initial value of 128
		// (on second iteration = 65)
		// and so on
		temp = sqrt;	
		// Then, replace values (256 / 128 + 128 ) / 2 = 65
		// (on second iteration 34.46923076923077)
		// and so on
		sqrt = ( number/temp + temp) / 2;
	}
	return (nb);
}

t_bound	*ft_push_get_boundaries(t_list *mem, t_dish *dish)
{
	t_bound	*bound;

	bound = kemalloc_exit(&mem, 1, sizeof(t_bound), NO_PRINT);
	
	return (bound);
}

int	ft_push_find_nb_rottions(t_dish *dish, t_bound *bound)
{
	t_dish	*buf;
	int		i;

	buf = dish;
	i = 0;	
}