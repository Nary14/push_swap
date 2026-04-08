/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marasolo <marasolo@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/08 21:23:34 by marasolo          #+#    #+#             */
/*   Updated: 2026/04/08 21:31:30 by marasolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	handle_mode(int *mode, int val, int *sc)
{
	*mode = val;
	ft_bench()->strategy_forced = val;
	(*sc)++;
}

void	set_forced_meta(int forced)
{
	if (forced == 1)
		ft_bench()->strategy_name = "Simple";
	else if (forced == 2)
		ft_bench()->strategy_name = "Chunk";
	else if (forced == 3)
		ft_bench()->strategy_name = "Radix";
	if (forced == 1)
		ft_bench()->strategy_complexity = "O(n^2)";
	else if (forced == 2)
		ft_bench()->strategy_complexity = "O(n√n)";
	else if (forced == 3)
		ft_bench()->strategy_complexity = "O(n log n)";
}
