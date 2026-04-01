/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marasolo <marasolo@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/01 13:36:38 by marasolo          #+#    #+#             */
/*   Updated: 2026/04/01 19:25:45 by marasolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_bench	*ft_bench(void)
{
	static t_bench	b;

	return (&b);
}

void	bench_init(void)
{
	ft_bench()->active = 0;
	ft_bench()->strategy_name = "Unknown";
	ft_bench()->strategy_complexity = "";
	ft_bench()->sa = 0;
	ft_bench()->sb = 0;
	ft_bench()->ss = 0;
	ft_bench()->pa = 0;
	ft_bench()->pb = 0;
	ft_bench()->ra = 0;
	ft_bench()->rb = 0;
	ft_bench()->rr = 0;
	ft_bench()->rra = 0;
	ft_bench()->rrb = 0;
	ft_bench()->rrr = 0;
}

void	bench_log(char *op, int print)
{
	if (print)
		ft_putstr_fd(op, 1);
	if (!ft_bench()->active)
		return ;
	if (ft_strncmp(op, "sa", 2) == 0 && op[2] == '\n')
		ft_bench()->sa++;
	else if (ft_strncmp(op, "sb", 2) == 0 && op[2] == '\n')
		ft_bench()->sb++;
	else if (ft_strncmp(op, "ss", 2) == 0 && op[2] == '\n')
		ft_bench()->ss++;
	else if (ft_strncmp(op, "pa", 2) == 0 && op[2] == '\n')
		ft_bench()->pa++;
	else if (ft_strncmp(op, "pb", 2) == 0 && op[2] == '\n')
		ft_bench()->pb++;
	else
		bench_log_ops(op);
}
