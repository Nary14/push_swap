/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: traomeli <traomeli@student.42Antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/26 06:46:26 by traomeli          #+#    #+#             */
/*   Updated: 2026/04/01 09:12:37 by traomeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	reverse_rotate_stack(t_node **stack)
{
	t_node	*prev;
	t_node	*temp;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	prev = *stack;
	while (prev->next->next != NULL)
		prev = prev->next;
	temp = prev->next;
	prev->next = NULL;
	add_front(stack, temp);
}

void	rra(t_node **a, int print)
{
	reverse_rotate_stack(a);
	if (print)
		bench_log("rra\n", 1);
}

void	rrb(t_node **b, int print)
{
	reverse_rotate_stack(b);
	if (print)
		bench_log("rrb\n", 1);
}

void	rrr(t_node **a, t_node **b, int print)
{
	reverse_rotate_stack(a);
	reverse_rotate_stack(b);
	if (print)
		bench_log("rrr\n", 1);
}
