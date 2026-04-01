/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_simple_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: traomeli <traomeli@student.42Antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/26 05:27:48 by marasolo          #+#    #+#             */
/*   Updated: 2026/04/01 08:52:02 by traomeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	find_min_index(t_node **stack)
{
	int		min_pos;
	int		min_value;
	int		pos;
	t_node	*current;

	min_pos = 0;
	min_value = INT_MAX;
	pos = 0;
	current = *stack;
	while (current)
	{
		if (current->value < min_value)
		{
			min_value = current->value;
			min_pos = pos;
		}
		pos++;
		current = current->next;
	}
	return (min_pos);
}

static void	ft_simple_sort_2(t_node	**stack)
{
	int	a;
	int	b;

	a = (*stack)->value;
	b = (*stack)->next->value;
	if (a > b)
		sa(stack, 1);
}

static void	ft_simple_sort_3(t_node **stack)
{
	int	a;
	int	b;
	int	c;

	a = (*stack)->value;
	b = (*stack)->next->value;
	c = (*stack)->next->next->value;
	if (a > b && b < c && a < c)
		sa(stack, 1);
	else if (a > b && b > c)
	{
		sa(stack, 1);
		rra(stack, 1);
	}
	else if (a > b && b < c && a > c)
		ra(stack, 1);
	else if (a < b && b > c && a < c)
	{
		sa(stack, 1);
		ra(stack, 1);
	}
	else if (a < b && b > c && a > c)
		rra(stack, 1);
}

static void	ft_simple_sort_4_5(t_node **stack1, t_node **stack2, int size)
{
	int	min_index;

	while (size > 3)
	{
		min_index = find_min_index(stack1);
		if (min_index < size / 2)
			while (min_index-- > 0)
				ra(stack1, 1);
		else
			while (min_index++ < size)
				rra(stack1, 1);
		pb(stack1, stack2, 1);
		size--;
	}
	ft_simple_sort(stack1, stack2, size);
	while (*stack2)
		pa(stack1, stack2, 1);
}

void	ft_simple_sort(t_node **stack1, t_node **stack2, int size)
{
	if (size == 2)
		ft_simple_sort_2(stack1);
	else if (size == 3)
		ft_simple_sort_3(stack1);
	else
		ft_simple_sort_4_5(stack1, stack2, size);
}
