/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disorder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marasolo <marasolo@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/29 14:58:58 by traomeli          #+#    #+#             */
/*   Updated: 2026/04/01 18:15:54 by marasolo         ###   ########.fr       */
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
	long	result;
	int		sign;

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
		{
			if (sign == 1)
				return (LONG_MAX);
			else
				return (LONG_MIN);
		}
		result = result * 10 + (*str++ - '0');
	}
	return (result * sign);
}

double	compute_disorder(t_node *a)
{
	long	inversions;
	int		n;
	t_node	*cur;
	t_node	*runner;

	inversions = 0;
	n = 0;
	cur = a;
	while (cur)
	{
		runner = cur->next;
		while (runner)
		{
			if (cur->value > runner->value)
				inversions++;
			runner = runner->next;
		}
		n++;
		cur = cur->next;
	}
	if (n < 2)
		return (0.0);
	return ((double)inversions / ((double)n * (n - 1) / 2.0));
}
/* max inversions = n*(n-1)/2 */