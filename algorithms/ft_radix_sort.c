/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_radix_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: traomeli <traomeli@student.42Antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/29 15:46:35 by traomeli          #+#    #+#             */
/*   Updated: 2026/04/01 08:51:55 by traomeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	max_bits(t_node *a)
{
	int		max;
	int		bits;
	t_node	*tmp;

	if (!a)
		return (0);
	tmp = a;
	max = tmp->index;
	while (tmp)
	{
		if (tmp->index > max)
			max = tmp->index;
		tmp = tmp->next;
	}
	bits = 0;
	while ((max >> bits) != 0)
		++bits;
	return (bits);
}

void	ft_radix_sort(t_node **a, t_node **b)
{
	int	size;
	int	i;
	int	j;
	int	bits;

	if (!a || !*a || !b)
		return ;
	size = stack_size(*a);
	bits = max_bits(*a);
	i = 0;
	while (i < bits)
	{
		j = 0;
		while (j < size)
		{
			if ((((*a)->index >> i) & 1) == 0)
				pb(a, b, 1);
			else
				ra(a, 1);
			++j;
		}
		while (*b)
			pa(a, b, 1);
		++i;
	}
}
