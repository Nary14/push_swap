/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chunk_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marasolo <marasolo@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/30 04:19:50 by traomeli          #+#    #+#             */
/*   Updated: 2026/03/30 22:40:35 by marasolo         ###   ########.fr       */
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

static void	push_chunks(t_node **a, t_node **b, int *s, int cs)
{
	int	chunk;
	int	low;
	int	high;
	int	pos;

	chunk = 0;
	while (chunk * cs < stack_size(*a))
	{
		low = chunk * cs;
		high = low + cs - 1;
		if (high >= stack_size(*a))
			high = stack_size(*a) - 1;
		pos = pos_of_first_in_range(*a, s[low], s[high]);
		while (pos != -1 && *a)
		{
			rotate_to_top_a(a, pos);
			pb(a, b, 1);
			pos = pos_of_first_in_range(*a, s[low], s[high]);
		}
		chunk++;
	}
}

static void	push_back(t_node **a, t_node **b)
{
	int	pos;

	while (*b)
	{
		pos = pos_of_max(*b);
		rotate_to_top_b(b, pos);
		pa(a, b, 1);
	}
}

void	ft_chunk_sort(t_node **a, t_node **b, int chunks)
{
	int	size;
	int	chunk_size;
	int	*sorted;

	if (!a || !*a || chunks <= 0)
		return ;
	size = stack_size(*a);
	sorted = sorted_array(*a, size);
	if (!sorted)
		return ;
	chunk_size = size / chunks;
	if (chunk_size == 0)
		chunk_size = 1;
	push_chunks(a, b, sorted, chunk_size);
	free(sorted);
	push_back(a, b);
}
