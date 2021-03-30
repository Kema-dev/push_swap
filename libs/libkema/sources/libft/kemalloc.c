/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kemalloc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjourdan <jjourdan@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 08:47:22 by jjourdan          #+#    #+#             */
/*   Updated: 2021/03/29 14:22:09 by jjourdan         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libkema.h"

void	*kemalloc_exit(t_list	**lst, size_t nmemb, size_t size)
{
	void	*elem;

	elem = ft_calloc(nmemb, size);
	if (!elem)
		exit(ft_kema_error(ENOMEM, lst, &free));
	else
		ft_lstadd_back(lst, ft_lstnew(elem));
	return (elem);
}

void	*kemalloc(t_list	**lst, size_t nmemb, size_t size)
{
	void	*elem;

	elem = ft_calloc(nmemb, size);
	if (!elem)
		ft_kema_error(ENOMEM, lst, &free);
	else
		ft_lstadd_back(lst, ft_lstnew(elem));
	return (elem);
}
