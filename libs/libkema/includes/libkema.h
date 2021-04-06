/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libkema.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjourdan <jjourdan@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/21 15:47:55 by jjourdan          #+#    #+#             */
/*   Updated: 2021/04/06 11:24:26 by jjourdan         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBKEMA_H
# define LIBKEMA_H

# include "libft.h"
# include "gnl.h"
# include "ft_dprintf.h"
# include <errno.h>

# define PRINT					1
# define NO_PRINT				0
# define SUCCESS				0
# define STR_SUCCESS			"OK\n"
# define FAILURE				-1
# define STR_FAILURE			"KO\n"
# define NO_LIST				-2
# define STR_NO_LIST			"No list provided\n"
# define INVALID_LIST			-3
# define STR_INVALID_LIST		"Provided list is invalid\n"
# define STACK_B_NOT_EMPTY		-4
# define STR_STACK_B_NOT_EMPTY	"Stack B is not empty\n"
# define WRONG_ORDER			-5
# define STR_WRONG_ORDER		"Order is not correct\n"
# define WRONG_COMMAND			-6
# define STR_WRONG_COMMAND		"Provided command is invalid\n"
# define NO_COMMAND				-7
# define STR_NO_COMMAND			"No command provided\n"
# define DUPLICATE				-8
# define STR_DUPLICATE			"There is a duplicate in the list\n"

#endif
