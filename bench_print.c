/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marasolo <marasolo@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/01 13:36:38 by marasolo          #+#    #+#             */
/*   Updated: 2026/04/01 19:25:45 by marasolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	bench_log_ops(char *op)
{
	if (ft_strncmp(op, "ra", 2) == 0 && op[2] == '\n')
		ft_bench()->ra++;
	else if (ft_strncmp(op, "rb", 2) == 0 && op[2] == '\n')
		ft_bench()->rb++;
	else if (ft_strncmp(op, "rr", 2) == 0 && op[2] == '\n')
		ft_bench()->rr++;
	else if (ft_strncmp(op, "rra", 3) == 0 && op[3] == '\n')
		ft_bench()->rra++;
	else if (ft_strncmp(op, "rrb", 3) == 0 && op[3] == '\n')
		ft_bench()->rrb++;
	else if (ft_strncmp(op, "rrr", 3) == 0 && op[3] == '\n')
		ft_bench()->rrr++;
}

static void	bench_print_ops(void)
{
	ft_putstr_fd("[bench] sa: ", 2);
	ft_putnbr_fd(ft_bench()->sa, 2);
	ft_putstr_fd("  sb: ", 2);
	ft_putnbr_fd(ft_bench()->sb, 2);
	ft_putstr_fd("  pa: ", 2);
	ft_putnbr_fd(ft_bench()->pa, 2);
	ft_putstr_fd("  pb: ", 2);
	ft_putnbr_fd(ft_bench()->pb, 2);
	ft_putchar_fd('\n', 2);
	ft_putstr_fd("[bench] ra: ", 2);
	ft_putnbr_fd(ft_bench()->ra, 2);
	ft_putstr_fd("  rb: ", 2);
	ft_putnbr_fd(ft_bench()->rb, 2);
	ft_putstr_fd("  rr: ", 2);
	ft_putnbr_fd(ft_bench()->rr, 2);
	ft_putstr_fd("  rra: ", 2);
	ft_putnbr_fd(ft_bench()->rra, 2);
	ft_putstr_fd("  rrb: ", 2);
	ft_putnbr_fd(ft_bench()->rrb, 2);
	ft_putstr_fd("  rrr: ", 2);
	ft_putnbr_fd(ft_bench()->rrr, 2);
	ft_putchar_fd('\n', 2);
}

void	bench_print_summary(double disorder)
{
	long	total;

	if (!ft_bench()->active)
		return ;
	(void)disorder;
	total = ft_bench()->sa + ft_bench()->sb + ft_bench()->ss
		+ ft_bench()->pa + ft_bench()->pb + ft_bench()->ra
		+ ft_bench()->rb + ft_bench()->rr + ft_bench()->rra
		+ ft_bench()->rrb + ft_bench()->rrr;
	ft_putstr_fd("[bench] strategy : ", 2);
	ft_putstr_fd(ft_bench()->strategy_name, 2);
	ft_putstr_fd(" / ", 2);
	ft_putendl_fd(ft_bench()->strategy_complexity, 2);
	ft_putstr_fd("[bench] total_ops : ", 2);
	ft_putnbr_fd(total, 2);
	ft_putchar_fd('\n', 2);
	bench_print_ops();
}
