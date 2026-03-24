/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marasolo <marasolo@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 09:55:37 by marasolo          #+#    #+#             */
/*   Updated: 2026/03/24 11:13:23 by marasolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "push_swap.h"

int	process_number(char	*str, t_list **stack)
{
	long int	num;
	int			*content;
	t_list		*new_node;
	
	if (!valid_number(str))
		return (0);
	num = ft_atoi(str);
	if (num < INT_MIN || num > INT_MAX)
		return (0);
	if (duplicat(*stack, (int)num))
		return (0);
	content = malloc(sizeof(int));
	if (!content)
		return (0);
	*content = (int)num;
	new_node = ft_lstnew(content);
	if (!content)
	{
		free(content);
		return (0);
	}
	ft_lstadd_back(stack, new_node);
	return (1);
}

int	parse_strings(char *str, t_list **stack)
{
	char	**split;
	int		i;
	int		result;

	split = ft_split(str, ' ');
	if (!split)
		return (0);
	i = 0;
	result = 1;
	while (split[i])
	{
		if (!process_number(split[i], stack))
		{
			result = 0;
		}
		i++;
	}
	free(split);
	return (result);
}

t_list	parse_args(int argc, char **argv)
{
	t_list	*stack;
	int		i;

	stack = NULL
	i = 0;
	while (i < argc)
	{
		if (!parse_strings(argv[i], &stack[i]))
		{
			free(stack);
			error_exit();
		}
		i++;
	}
	if (!stack)
		error_exit();
	return (stack)
}
