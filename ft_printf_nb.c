/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_nb.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtraiman <gtraiman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 16:24:32 by gtraiman          #+#    #+#             */
/*   Updated: 2024/03/19 17:42:34 by gtraiman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_i(va_list arg)
{
	int		count;
	int		nb;
	char	*nb_str;

	nb = va_arg(arg, int);
	nb_str = ft_itoa(nb);
	count = ft_print_str(nb_str);
	free(nb_str);
	return (count);
}

int	ft_print_u(va_list arg)
{
	unsigned int	nb;

	nb = va_arg(arg, unsigned int);
	ft_putnbr_base_fd(nb, "0123456789", 1);
	return (ft_len_unb(nb, 10));
}

int	ft_print_x(char c, va_list arg)
{
	int	nb;

	nb = va_arg(arg, unsigned int);
	if (c == 'x')
		ft_putnbr_base_fd(nb, "0123456789abcdef", 1);
	else
		ft_putnbr_base_fd(nb, "0123456789ABCDEF", 1);
	return (ft_len_unb(nb, 16));
}

int	ft_print_p(size_t ptr)
{
	char	str[20];
	int		count;
	int		i;
	char	*b;

	i = 0;
	b = "0123456789abcdef";
	if (ptr == 0)
	{
		ft_print_str("(nil)");
		return (5);
	}
	ft_putstr_fd("0x", 1);
	count = 2;
	while (ptr != 0)
	{
		str[i] = b[ptr % 16];
		ptr /= 16;
		i++;
	}
	while (i-- && count++)
		ft_print_char(str[i]);
	return (count);
}
