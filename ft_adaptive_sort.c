/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_adaptive_sort.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marasolo <marasolo@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/26 10:39:29 by marasolo          #+#    #+#             */
/*   Updated: 2026/04/08 21:03:39 by marasolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	sorted(t_node *stack)
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

void	ft_adaptive_sort(t_node **stack1, t_node **stack2)
{
	double	size;
	int		chunks;
	double	disorder;

	disorder = compute_disorder(*stack1);
	size = stack_size(*stack1);
	if (sorted(*stack1))
		return ;
	if (disorder < 0.2 || size <= 5)
		ft_simple_sort(stack1, stack2, size);
	else if (0.2 <= disorder && disorder < 0.5 && size > 5)
	{
		chunks = size / 12;
		if (chunks < 1)
			chunks = 1;
		ft_chunk_sort(stack1, stack2, chunks);
	}
	else
		ft_radix_sort(stack1, stack2);
}
