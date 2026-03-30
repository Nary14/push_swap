/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: traomeli <traomeli@student.42Antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 08:28:36 by traomeli          #+#    #+#             */
/*   Updated: 2026/03/30 05:14:33 by traomeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	push(t_node **stack_a, t_node **stack_b)
{
	t_node	*temp;
	t_node *next;

	if (stack_a == NULL || *stack_a == NULL)
		return ;
	temp = *stack_a;
	next = temp->next;
	add_front(stack_b, temp);
	*stack_a = next;
}

void	pa(t_node **a, t_node **b, int print)
{
	push(b, a);
	if (print)
		ft_putstr_fd("pa\n", 1);
}

void	pb(t_node **a, t_node **b, int print)
{
	push(a, b);
	if (print)
		ft_putstr_fd("pb\n", 1);
}
