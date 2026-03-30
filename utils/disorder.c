/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disorder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: traomeli <traomeli@student.42Antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/29 14:58:58 by traomeli          #+#    #+#             */
/*   Updated: 2026/03/30 05:59:26 by traomeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	assign_index(t_node *a)
{
	int		count;
	t_node	*current;
	t_node	*runner;

	current = a;
	while (current)
	{
		count = 0;
		runner = a;
		while (runner)
		{
			if (current->value > runner->value)
				count++;
			runner = runner->next;
		}
		current->index = count;
		current = current->next;
	}
}

long	ft_atol(const char *str)
{
	long result;
	int sign;

	result = 0;
	sign = 1;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (ft_isdigit(*str))
	{
		if (result > (LONG_MAX - (*str - '0')) / 10)
			return (sign == 1 ? LONG_MAX : LONG_MIN);
		result = result * 10 + (*str - '0');
		str++;
	}
	return (result * sign);
}