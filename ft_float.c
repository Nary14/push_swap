/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_float.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: traomeli <traomeli@student.42Antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/02 00:00:00 by marasolo          #+#    #+#             */
/*   Updated: 2026/04/08 15:58:59 by traomeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	put_ulong(unsigned long n, int fd)
{
	if (n >= 10)
		put_ulong(n / 10, fd);
	ft_putchar_fd('0' + (n % 10), fd);
}

static unsigned long	ft_pow10(int exp)
{
	unsigned long	result;

	result = 1;
	while (exp > 0)
	{
		result *= 10;
		exp--;
	}
	return (result);
}

static void	put_decimals(double frac, int precision, int fd)
{
	unsigned long	scale;
	unsigned long	dec;
	unsigned long	place;
	int				i;

	scale = ft_pow10(precision);
	dec = (unsigned long)(frac * (double)scale + 0.5);
	if (dec >= scale)
		dec = scale - 1;
	i = precision - 1;
	while (i >= 0)
	{
		place = ft_pow10(i);
		ft_putchar_fd('0' + (dec / place % 10), fd);
		i--;
	}
}

void	ft_float(double n, int precision, int fd)
{
	double			abs_n;
	unsigned long	int_part;

	if (n < 0.0)
	{
		ft_putchar_fd('-', fd);
		n = -n;
	}
	abs_n = n;
	int_part = (unsigned long)abs_n;
	put_ulong(int_part, fd);
	if (precision <= 0)
		return ;
	ft_putchar_fd('.', fd);
	put_decimals(abs_n - (double)int_part, precision, fd);
}
