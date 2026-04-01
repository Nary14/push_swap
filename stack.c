/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: traomeli <traomeli@student.42Antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/30 22:07:57 by marasolo          #+#    #+#             */
/*   Updated: 2026/04/01 08:52:50 by traomeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_size(t_node *stack)
{
	int	count;

	count = 0;
	while (stack != NULL)
	{
		count ++;
		stack = stack->next;
	}
	return (count);
}

void	free_stack(t_node **stack)
{
	t_node	*lig;
	t_node	*temp;

	lig = *stack;
	while (lig != NULL)
	{
		temp = lig;
		lig = lig->next;
		free(temp);
	}
	*stack = NULL;
}
