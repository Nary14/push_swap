/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: traomeli <traomeli@student.42Antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 07:39:20 by traomeli          #+#    #+#             */
/*   Updated: 2026/03/29 14:27:12 by traomeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	swap_top(t_node **stack)
{
	int	temp;

	if (!stack || !*stack)
		return ;
	temp = (*stack)->value;
	(*stack)->value = (*stack)->next->value;
	(*stack)->next->value = temp;
}

void	sa(t_node **a, int print)
{
	swap_top(a);
	if (print)
		ft_putstr_fd("sa\n", 1);
}

void	sb(t_node **b, int print)
{
	swap_top(b);
	if (print)
		ft_putstr_fd("sb\n", 1);
}

void	ss(t_node **a, t_node **b, int print)
{
	swap_top(a);
	swap_top(b);
	if (print)
		ft_putstr_fd("ss\n", 1);
}
