/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: traomeli <traomeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 14:54:57 by traomeli          #+#    #+#             */
/*   Updated: 2026/01/26 16:44:05 by traomeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isnegative(int i)
{
	if (i < 0)
		return (1);
	return (0);
}

static int	ft_c(int temp)
{
	int	len;

	if (temp == 0)
		return (1);
	len = 0;
	if (ft_isnegative(temp))
		temp = temp * -1;
	while (temp)
	{
		temp /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*str;
	long	num;
	int		len;
	int		is_negative;
	long	temp;

	num = n;
	len = ft_c(n);
	is_negative = ft_isnegative(num);
	if (is_negative)
		num = -num;
	temp = num;
	len += is_negative;
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	str[len] = '\0';
	while (len-- > is_negative)
	{
		str[len] = (num % 10) + '0';
		num /= 10;
	}
	if (is_negative)
		str[0] = '-';
	return (str);
}
