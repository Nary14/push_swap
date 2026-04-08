/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: traomeli <traomeli@student.42Antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/01 13:36:38 by marasolo          #+#    #+#             */
/*   Updated: 2026/04/08 18:07:24 by traomeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_flag(char *s, char *flag, int len)
{
	return (ft_strncmp(s, flag, len) == 0 && (int)ft_strlen(s) == len);
}

void	set_adaptive_complexity(double disorder, int size)
{
	if (disorder < 0.2 || size <= 5)
		ft_bench()->strategy_complexity = "O(n^2)";
	else if (0.2 <= disorder && disorder < 0.5 && size > 5)
		ft_bench()->strategy_complexity = "O(n√n)";
	else
		ft_bench()->strategy_complexity = "O(n log n)";
}

void	set_strategy(double disorder, int size)
{
	if (ft_bench()->strategy_forced != -1)
	{
		if (ft_bench()->strategy_forced == 1)
		{
			ft_bench()->strategy_name = "Simple";
			ft_bench()->strategy_complexity = "O(n^2)";
		}
		else if (ft_bench()->strategy_forced == 2)
		{
			ft_bench()->strategy_name = "Chunk";
			ft_bench()->strategy_complexity = "O(n√n)";
		}
		else if (ft_bench()->strategy_forced == 3)
		{
			ft_bench()->strategy_name = "Radix";
			ft_bench()->strategy_complexity = "O(n log n)";
		}
		else
		{
			ft_bench()->strategy_name = "Adaptive";
			set_adaptive_complexity(disorder, size);
		}
		return ;
	}
	ft_bench()->strategy_name = "Adaptive";
	set_adaptive_complexity(disorder, size);
}

void	run_sort(t_node **a, t_node **b, int mode)
{
	if (mode == 1)
		ft_simple_sort(a, b, stack_size(*a));
	else if (mode == 2)
		ft_chunk_sort(a, b, 5);
	else if (mode == 3)
		ft_radix_sort(a, b);
	else
		ft_adaptive_sort(a, b);
}

void	check_has_numbers(int argc, char **argv)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (ft_strncmp(argv[i], "--", 2) != 0)
			return ;
		i++;
	}
	ft_error_exit();
}
