/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtraiman <gtraiman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 16:26:28 by gtraiman          #+#    #+#             */
/*   Updated: 2024/03/19 17:41:34 by gtraiman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "libft/libft.h"
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

// char    *ft_itoa(int n);
int		ft_print_percent(void);
int		ft_print_char(char c);
int		ft_print_str(char *str);
int		ft_print_i(va_list arg);
int		ft_print_u(va_list arg);
int		ft_print_x(char c, va_list arg);
int		ft_print_p(size_t ptr);
int		ft_parse(char s, va_list arg);
int		ft_printf(const char *str, ...);
int		len_nb(int nb, int base);
int		ft_len_unb(unsigned int nb, int base);
void	ft_putnbr_base_fd(unsigned int nb, char *base, int fd);
// void            ft_putchar_fd(char c, int fd);
// void		ft_putnbr_fd(int n, int fd);
// void		ft_putstr_fd(char const *s, int fd);
// size_t    ft_strlen(const char *s);

#endif