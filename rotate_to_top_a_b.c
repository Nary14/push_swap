/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_to_top_a_b.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: traomeli <traomeli@student.42Antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/30 22:02:51 by marasolo          #+#    #+#             */
/*   Updated: 2026/04/01 08:52:44 by traomeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_to_top_a(t_node **a, int pos)
{
	int	sz;

	sz = stack_size(*a);
	if (pos <= sz / 2)
		while (pos-- > 0)
			ra(a, 1);
	else
	{
		pos = sz - pos;
		while (pos-- > 0)
			rra(a, 1);
	}
}

void	rotate_to_top_b(t_node **b, int pos)
{
	int	sz;

	sz = stack_size(*b);
	if (pos <= sz / 2)
		while (pos-- > 0)
			rb(b, 1);
	else
	{
		pos = sz - pos;
		while (pos-- > 0)
			rrb(b, 1);
	}
}
