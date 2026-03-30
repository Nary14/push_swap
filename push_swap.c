/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marasolo <marasolo@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/26 06:20:35 by traomeli          #+#    #+#             */
/*   Updated: 2026/03/30 10:06:55 by marasolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap(t_node **a, t_node **b)
{
	if (!a || !*a)
		return ;
	assign_index(*a);
	adaptive_sort(a, b);
}

int	main(int argc, char **argv)
{
	t_node	*a;
	t_node	*b;

	a = NULL;
	b = NULL;
	if (argc < 2)
		return (0);
	parse_args(argc, argv, &a);
	if (is_sorted(a))
	{
		free_stack(&a);
		return (0);
	}
	push_swap(&a, &b);
	free_stack(&a);
	free_stack(&b);
	return (0);
}
