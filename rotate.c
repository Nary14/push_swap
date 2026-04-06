/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: traomeli <traomeli@student.42Antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/26 06:21:57 by traomeli          #+#    #+#             */
/*   Updated: 2026/04/01 22:50:00 by traomeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_stack(t_node **stack)
{
	t_node	*temp;

	if (!stack || !*stack)
		return ;
	temp = *stack;
	*stack = temp->next;
	temp->next = NULL;
	add_back(stack, temp);
}

void	ra(t_node **a, int print)
{
	rotate_stack(a);
	if (print)
		bench_log("ra\n", 1);
}

void	rb(t_node **b, int print)
{
	rotate_stack(b);
	if (print)
		bench_log("rb\n", 1);
}

void	rr(t_node **a, t_node **b, int print)
{
	rotate_stack(a);
	rotate_stack(b);
	if (print)
		bench_log("rr\n", 1);
}
