/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kema_error.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjourdan <jjourdan@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 13:29:56 by jjourdan          #+#    #+#             */
/*   Updated: 2021/03/30 10:44:02 by jjourdan         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libkema.h"

int	ft_kema_error(int errcode, t_list **lst, void (*del)(void*))
{
	char	*str[10];

	str[0] = STR_SUCCESS;
	str[1] = STR_FAILURE;
	str[2] = STR_NO_LIST;
	str[3] = STR_INVALID_LIST;
	str[4] = STR_STACK_B_NOT_EMPTY;
	str[5] = STR_WRONG_ORDER;
	str[6] = STR_WRONG_COMMAND;
	str[7] = STR_NO_COMMAND;
	str[8] = NULL;
	str[9] = NULL;
	ft_lstclear(lst, del);
	if (errcode < 0)
		ft_dprintf(STDERR_FILENO, "Error %d: %s\n", errcode, str[-errcode]);
	else if (errcode == SUCCESS)
		ft_dprintf(STDOUT_FILENO, STR_SUCCESS);
	else
		ft_dprintf(STDERR_FILENO, "Error %d: %s\n", errcode, strerror(ENOMEM));
	return (errcode);
}
