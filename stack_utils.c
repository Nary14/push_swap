/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marasolo <marasolo@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/29 10:59:38 by traomeli          #+#    #+#             */
/*   Updated: 2026/03/30 22:08:45 by marasolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	add_front(t_node **stack, t_node *temp)
{
	temp->next = *stack;
	*stack = temp;
}

void	add_back(t_node **stack, t_node *temp)
{
	t_node	*l;

	if (*stack == NULL)
	{
		*stack = temp;
		return ;
	}
	l = *stack;
	while (l->next != NULL)
		l = l->next;
	l->next = temp;
}

t_node	*new_node(int value)
{
	t_node	*mall;

	mall = malloc(sizeof(t_node));
	if (!mall)
		return (NULL);
	mall->value = value;
	mall->index = 0;
	mall->next = NULL;
	return (mall);
}

int	is_sorted(t_node *stack)
{
	while (stack && stack->next)
	{
		if (stack->value > stack->next->value)
			return (0);
		stack = stack->next;
	}
	return (1);
}
