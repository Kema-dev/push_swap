/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dprintf.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjourdan <jjourdan@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 14:19:20 by jjourdan          #+#    #+#             */
/*   Updated: 2021/03/22 11:35:44 by jjourdan         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_DPRINTF_H
# define FT_DPRINTF_H

# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdarg.h>

typedef struct s_flag
{
	int		fd;
	int		minus;
	int		plus;
	int		space;
	char	zero;
	int		hashtag;
	int		width;
	int		prec;
	char	add_flags;
	char	type;
	size_t	tot_len;
}	t_flag;

int					ft_dprintf_atoi(const char *nptr);
void				*ft_dprintf_calloc(size_t nmemb, size_t size);
char				*ft_dprintf_itoa(int n);
void				*ft_dprintf_memset(void *s, int c, size_t n);
char				*ft_dprintf_ptoa(unsigned long long ull, t_flag *flag);
void				ft_dprintf_putchar_fd(char c, t_flag *flag);
void				ft_dprintf_putstr_fd(char *str, t_flag *flag);
size_t				ft_dprintf_strlen(const char *s);
char				*ft_dprintf_utoa(unsigned int n);
char				*ft_dprintf_xtoa(unsigned int n, t_flag *flag);
int					ft_dprintf(int fd, const char *input, ...);
t_flag				*ft_dprintf_flag_init(t_flag *flag);
t_flag				*ft_dprintf_flag_reset(t_flag *flag);
int					ft_dprintf_get_add_flags(const char *input, \
									t_flag *flag);
int					ft_dprintf_get_first_flags(const char *input, \
									t_flag *flag, va_list args);
int					ft_dprintf_get_flag(const char *input, va_list args, \
									t_flag *flag);
int					ft_dprintf_get_prec(const char *input, va_list args, \
									t_flag *flag);
int					ft_dprintf_get_type(const char *input, t_flag *flag);
int					ft_dprintf_get_width(const char *input, va_list args, \
									t_flag *flag);
void				ft_dprintf_print_c(va_list args, t_flag *flag);
void				ft_dprintf_print_s(va_list args, t_flag *flag);
void				ft_dprintf_print_x(va_list args, t_flag *flag);
int					ft_dprintf_treat_flag(va_list args, t_flag *flag);
int					ft_dprintf_treat_input(const char *input, va_list args, \
									t_flag *flag);
int					ft_dprintf_print_normal(const char *input, int i, \
									t_flag *flag);
int					ft_dprintf_print_percent(int i, t_flag *flag);
void				ft_dprintf_print_p(va_list args, t_flag *flag);

#endif
