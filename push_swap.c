/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: traomeli <traomeli@student.42Antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/26 06:20:35 by traomeli          #+#    #+#             */
/*   Updated: 2026/04/01 09:56:03 by traomeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "utils/libft_42/libft.h"

void	push_swap(t_node **a, t_node **b)
{
	if (!a || !*a)
		return ;
	assign_index(*a);
	ft_adaptive_sort(a, b);
}

int	main(int argc, char **argv)
{
	t_node	*a;
	t_node	*b;
	int	i;
	int	bench;
	int	mode;
	int	strategy_count;
	char	**new_argv;
	int	new_argc;

	a = NULL;
	b = NULL;
	if (argc < 2)
		return (0);
	mode = 0;
	bench = 0;
	strategy_count = 0;

	i = 1;
	while (i < argc)
	{
		if (ft_strncmp(argv[i], "--", 2) == 0)
		{
			if (ft_strncmp(argv[i], "--bench", 7) == 0 && ft_strlen(argv[i]) == 7)
				bench = 1;
			else if (ft_strncmp(argv[i], "--simple", 8) == 0 && ft_strlen(argv[i]) == 8)
			{
				mode = 1;
				strategy_count++;
			}
			else if (ft_strncmp(argv[i], "--medium", 8) == 0 && ft_strlen(argv[i]) == 8)
			{
				mode = 2;
				strategy_count++;
			}
			else if (ft_strncmp(argv[i], "--complex", 9) == 0 && ft_strlen(argv[i]) == 9)
			{
				mode = 3;
				strategy_count++;
			}
			else if (ft_strncmp(argv[i], "--adaptive", 10) == 0 && ft_strlen(argv[i]) == 10)
			{
				mode = 0;
				strategy_count++;
			}
			else
				ft_error_exit();
		}
		i++;
	}

	if (strategy_count > 1)
		ft_error_exit();
	{
		int	has_numbers;
		has_numbers = 0;
		i = 1;
		while (i < argc)
		{
			if (!(ft_strncmp(argv[i], "--", 2) == 0))
			{
				has_numbers = 1;
				break;
			}
			i++;
		}
		if (!has_numbers)
			ft_error_exit();
	}

	new_argv = malloc(sizeof(char *) * (argc + 1));
	if (!new_argv)
		ft_error_exit();
	new_argc = 1;
	new_argv[0] = argv[0];
	i = 1;
	while (i < argc)
	{
		if (!(ft_strncmp(argv[i], "--", 2) == 0))
		{
			new_argv[new_argc++] = argv[i];
		}
		i++;
	}
	new_argv[new_argc] = NULL;

	if (!parse_args(new_argc, new_argv, &a))
	{
		free(new_argv);
		ft_error_exit();
	}
	free(new_argv);
	if (is_sorted(a))
	{
		free_stack(&a);
		return (0);
	}

	/* compute disorder and enable bench globals */
	{
		double	disorder;
		int	size;
		disorder = compute_disorder(a);
		g_bench = bench;
		/* determine strategy name and complexity */
		size = stack_size(a);
		if (mode == 1)
		{
			g_strategy_name = "Simple";
			g_strategy_complexity = "O(n^2)";
		}
		else if (mode == 2)
		{
			g_strategy_name = "Chunk";
			g_strategy_complexity = "O(n\u221An)";
		}
		else if (mode == 3)
		{
			g_strategy_name = "Radix";
			g_strategy_complexity = "O(n log n)";
		}
		else /* adaptive */
		{
			g_strategy_name = "Adaptive";
			if (size <= 5)
				g_strategy_complexity = "O(n^2)";
			else if (size <= 100)
				g_strategy_complexity = "O(n\u221An)";
			else
				g_strategy_complexity = "O(n log n)";
		}

		assign_index(a);
		if (mode == 1)
			ft_simple_sort(&a, &b, stack_size(a));
		else if (mode == 2)
			ft_chunk_sort(&a, &b, 5);
		else if (mode == 3)
			ft_radix_sort(&a, &b);
		else
			ft_adaptive_sort(&a, &b);

		if (g_bench)
			bench_print_summary(disorder);
	}
	
	free_stack(&a);
	free_stack(&b);
	return (0);
}
