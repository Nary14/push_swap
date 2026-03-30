/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adaptive_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: traomeli <traomeli@student.42Antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/26 10:39:29 by marasolo          #+#    #+#             */
/*   Updated: 2026/03/30 06:16:34 by traomeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	sorted(t_node *stack)
{
	if (!stack || !stack->next)
		return (1);
	while (stack->next)
	{
		if (stack->value > stack->next->value)
			return (0);
		stack = stack->next;
	}
	return (1);
}

void	adaptive_sort(t_node **stack1, t_node **stack2)
{
	int	size;
	int	chunks;

	size = stack_size(*stack1);
	if (sorted(*stack1))
		return ;
	if (size <= 5)
		ft_simple_sort(stack1, stack2, size);
	else if (size <= 100)
	{
		chunks = size / 11;
		if (chunks < 1)
			chunks = 1;
		ft_chunk_sort(stack1, stack2, chunks);
	}
	else
		ft_radix_sort(stack1, stack2);
}
