/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chunk_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marasolo <marasolo@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/30 04:19:50 by traomeli          #+#    #+#             */
/*   Updated: 2026/03/30 22:03:39 by marasolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	cmp_int(const void *a, const void *b)
{
	int	va;
	int	vb;

	va = *(const int *)a;
	vb = *(const int *)b;
	if (va < vb)
		return (-1);
	if (va > vb)
		return (1);
	return (0);
}

static int	*sorted_array(t_node *a, int size)
{
	int		*arr;
	int		i;
	t_node	*cur;

	arr = (int *)malloc(sizeof(int) * size);
	if (!arr)
		return (NULL);
	i = 0;
	cur = a;
	while (cur && i < size)
	{
		arr[i++] = cur->value;
		cur = cur->next;
	}
	qsort(arr, size, sizeof(int), cmp_int);
	return (arr);
}

static int	pos_of_first_in_range(t_node *a, int lowv, int highv)
{
	int	pos;

	pos = 0;
	while (a)
	{
		if (a->value >= lowv && a->value <= highv)
			return (pos);
		pos++;
		a = a->next;
	}
	return (-1);
}

static int	pos_of_max(t_node *s)
{
	int	pos;
	int	max;
	int	maxpos;

	if (!s)
		return (-1);
	max = s->value;
	pos = 0;
	maxpos = 0;
	while (s)
	{
		if (s->value > max)
		{
			max = s->value;
			maxpos = pos;
		}
		pos++;
		s = s->next;
	}
	return (maxpos);
}

void	ft_chunk_sort(t_node **a, t_node **b, int chunks)
{
	int	size;
	int	chunk;
	int	chunk_size;
	int	*sorted;
	int	low_idx;
	int	high_idx;
	int	pos;

	if (!a || !*a || chunks <= 0)
		return ;
	size = stack_size(*a);
	sorted = sorted_array(*a, size);
	if (!sorted)
		return ;
	chunk_size = size / chunks;
	if (chunk_size == 0)
		chunk_size = 1;
	chunk = 0;
	while (chunk < chunks)
	{
		low_idx = chunk * chunk_size;
		high_idx = low_idx + chunk_size - 1;
		if (high_idx >= size)
			high_idx = size - 1;
		pos = pos_of_first_in_range(*a, sorted[low_idx], sorted[high_idx]);
		while (pos != -1 && *a)
		{
			rotate_to_top_a(a, pos);
			pb(a, b, 1);
			pos = pos_of_first_in_range(*a, sorted[low_idx], sorted[high_idx]);
		}
		chunk++;
	}
	free(sorted);
	while (*b)
	{
		pos = pos_of_max(*b);
		rotate_to_top_b(b, pos);
		pa(a, b, 1);
	}
}
