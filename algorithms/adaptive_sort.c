/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adaptive_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marasolo <marasolo@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/26 10:39:29 by marasolo          #+#    #+#             */
/*   Updated: 2026/03/26 10:51:42 by marasolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sorted(t_list *stack)
{
	int	*current;
	int	*next;

	if (!stack || !stack->next)
		return (1);
	while (stack->next)
	{
		current = (int *)stack->content;
		next = (int *)stack->next->content;
		if (*current > *next)
			return (0);
		stack = stack->next;
	}
	return (1);
}

void	adaptive_sort(t_list **stack1, t_list **stack2)
{
	int	size;

	size = ft_lstsize(*stack1);
	if (!sorted(*stack1))
		return ;
	if (size <= 5)
		simple_sort(stack1, stack2, size);
	else if (size <= 100)
		chunk_sort(stack1, stack2, size);
	else
		radix_sort(stack1, stack2, size);
}
