/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marasolo <marasolo@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 09:55:37 by marasolo          #+#    #+#             */
/*   Updated: 2026/03/23 14:11:36 by marasolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "push_swap.h"

int	ft_atoi(const char *str)
{
	int	i;
	int	s;
	
	i = 0;
	s = 1;
	while ((8 < *str && *str < 14) || *str == 32)
		str++;
	if (*str == 45 || *str == 43)
	{
		if (*str == 45)
			s = s * -1;
		str++;
	}
	while ('0' <= *str && *str <= '9')
	{
		i = i * 10 + (*str - '0');
		str++;
	}
	return (i * s);
}


