/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: traomeli <traomeli@student.42Antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/26 06:20:35 by traomeli          #+#    #+#             */
/*   Updated: 2026/04/06 15:50:39 by traomeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap(t_node **a, t_node **b)
{
	if (!a || !*a)
		return ;
	assign_index(*a);
	ft_adaptive_sort(a, b);
}

void	parse_flags(int argc, char **argv, int *mode, int *bench)
{
	int	i;
	int	sc;

	sc = 0;
	i = 1;
	while (i < argc)
	{
		if (is_flag(argv[i], "--bench", 7))
			*bench = 1;
		else if (is_flag(argv[i], "--simple", 8) && ++sc)
			*mode = 1;
		else if (is_flag(argv[i], "--medium", 8) && ++sc)
			*mode = 2;
		else if (is_flag(argv[i], "--complex", 9) && ++sc)
			*mode = 3;
		else if (is_flag(argv[i], "--adaptive", 10) && ++sc)
			*mode = 0;
		else if (ft_strncmp(argv[i], "--", 2) == 0)
			ft_error_exit();
		i++;
	}
	if (sc > 1)
		ft_error_exit();
}

char	**build_new_argv(int argc, char **argv, int *new_argc)
{
	char	**new_argv;
	int		i;

	check_has_numbers(argc, argv);
	new_argv = malloc(sizeof(char *) * (argc + 1));
	if (!new_argv)
		ft_error_exit();
	new_argv[0] = argv[0];
	*new_argc = 1;
	i = 1;
	while (i < argc)
	{
		if (ft_strncmp(argv[i], "--", 2) != 0)
			new_argv[(*new_argc)++] = argv[i];
		i++;
	}
	new_argv[*new_argc] = NULL;
	return (new_argv);
}

static void	ft_run_if_unsorted(t_node **a, t_node **b, int *params)
{
	double	disorder;

	disorder = compute_disorder(*a);
	set_strategy(disorder, stack_size(*a));
	ft_bench()->active = params[1];
	assign_index(*a);
	run_sort(a, b, params[0]);
	bench_print_summary(disorder);
}

int	main(int argc, char **argv)
{
	t_node	*a;
	t_node	*b;
	char	**new_argv;
	int		params[3];

	a = NULL;
	b = NULL;
	if (argc < 2)
		return (0);
	params[0] = 0;
	params[1] = 0;
	parse_flags(argc, argv, &params[0], &params[1]);
	new_argv = build_new_argv(argc, argv, &params[2]);
	if (!parse_args(params[2], new_argv, &a))
		return (free(new_argv), ft_error_exit(), 1);
	free(new_argv);
	ft_run_if_unsorted(&a, &b, params);
	free_stack(&a);
	free_stack(&b);
	return (0);
}
