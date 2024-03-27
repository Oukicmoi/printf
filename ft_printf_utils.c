/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtraiman <gtraiman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 20:34:41 by gtraiman          #+#    #+#             */
/*   Updated: 2024/03/19 17:41:53 by gtraiman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	len_nb(int nb, int base)
{
	int	i;

	i = 0;
	if (nb < 0)
	{
		nb *= -1;
		i++;
	}
	if (nb == 0)
		return (i + 1);
	while (nb > 0)
	{
		nb /= base;
		i++;
	}
	return (i);
}

int	ft_len_unb(unsigned int nb, int base)
{
	unsigned int	i;

	i = 0;
	if (nb == 0)
		return (i + 1);
	while (nb > 0)
	{
		nb /= base;
		i++;
	}
	return (i);
}

void	ft_putnbr_base_fd(unsigned int nb, char *base, int fd)
{
	unsigned int	len_base;

	len_base = ft_strlen(base);
	if (nb < len_base)
		ft_putchar_fd(base[nb], fd);
	else
	{
		ft_putnbr_base_fd((nb / len_base), base, fd);
		ft_putnbr_base_fd((nb % len_base), base, fd);
	}
}
