/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marasolo <marasolo@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 05:55:20 by marasolo          #+#    #+#             */
/*   Updated: 2026/04/08 20:47:31 by marasolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_valid_int(const char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

int	has_duplicate(t_node *stack, int value)
{
	t_node	*tmp;

	tmp = stack;
	while (tmp)
	{
		if (tmp->value == value)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

void	print_error(void)
{
	write(2, "Error\n", 6);
}

void	ft_error(void)
{
	print_error();
}

void	ft_error_exit(void)
{
	print_error();
	exit(EXIT_FAILURE);
}
