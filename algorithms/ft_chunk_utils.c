/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chunk_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marasolo <marasolo@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/30 22:38:33 by marasolo          #+#    #+#             */
/*   Updated: 2026/03/30 22:40:59 by marasolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	pos_of_first_in_range(t_node *a, int lowv, int highv)
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

int	pos_of_max(t_node *s)
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
