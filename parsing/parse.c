/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: traomeli <traomeli@student.42Antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 09:55:37 by marasolo          #+#    #+#             */
/*   Updated: 2026/04/01 08:52:17 by traomeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	process_number(char	*str, t_node **stack)
{
	long int	num;
	t_node		*node;

	if (!is_valid_int(str))
		return (0);
	num = ft_atol(str);
	if (num < INT_MIN || num > INT_MAX)
		return (0);
	if (has_duplicate(*stack, (int)num))
		return (0);
	node = new_node((int)num);
	if (!node)
		return (0);
	add_back(stack, node);
	return (1);
}

int	parse_strings(char *str, t_node **stack)
{
	char	**split;
	int		i;
	int		result;

	split = ft_split(str, ' ');
	if (!split)
		return (0);
	if (!split[0])
	{
		free(split);
		return (0);
	}
	i = 0;
	result = 1;
	while (split[i])
	{
		if (!process_number(split[i], stack))
			result = 0;
		free(split[i]);
		i++;
	}
	free(split);
	return (result);
}

int	parse_args(int argc, char **argv, t_node **a)
{
	t_node	*stack;
	int		i;

	stack = NULL;
	i = 1;
	while (i < argc)
	{
		if (!parse_strings(argv[i], &stack))
		{
			free_stack(&stack);
			return (0);
		}
		i++;
	}
	if (!stack)
		return (0);
	*a = stack;
	return (1);
}
