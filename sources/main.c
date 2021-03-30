/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjourdan <jjourdan@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 10:38:50 by jjourdan          #+#    #+#             */
/*   Updated: 2021/03/29 18:34:37 by jjourdan         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "my_project.h"

int	main(int argc, char **argv, char **envp)
{
	t_list	*mem;
	char	*str;

	(void)argc;
	(void)argv;
	(void)envp;
	mem = NULL;
	str = kemalloc(&mem, 10, sizeof(char));
	ft_memcpy(str, "Hello,world!", 13);
	ft_lstprint("%s", mem);
	ft_kema_error(SUCCESS, &mem, &free);
	return (SUCCESS);
}
// ? exit(ft_kema_error()) if exit accepted
