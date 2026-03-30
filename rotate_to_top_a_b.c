/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_to_top_a_b.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marasolo <marasolo@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/30 22:02:51 by marasolo          #+#    #+#             */
/*   Updated: 2026/03/30 22:14:49 by marasolo         ###   ########.fr       */
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
