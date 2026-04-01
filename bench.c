#include "push_swap.h"
#include <stdio.h>

int g_bench = 0;
char *g_strategy_name = "Unknown";
char *g_strategy_complexity = "";

long g_sa = 0;
long g_sb = 0;
long g_ss = 0;
long g_pa = 0;
long g_pb = 0;
long g_ra = 0;
long g_rb = 0;
long g_rr = 0;
long g_rra = 0;
long g_rrb = 0;
long g_rrr = 0;

void	bench_log(char *op, int print)
{
	if (print)
		ft_putstr_fd(op, 1);
	if (!g_bench)
		return ;
	if (ft_strncmp(op, "sa", 2) == 0 && op[2] == '\n')
		g_sa++;
	else if (ft_strncmp(op, "sb", 2) == 0 && op[2] == '\n')
		g_sb++;
	else if (ft_strncmp(op, "ss", 2) == 0 && op[2] == '\n')
		g_ss++;
	else if (ft_strncmp(op, "pa", 2) == 0 && op[2] == '\n')
		g_pa++;
	else if (ft_strncmp(op, "pb", 2) == 0 && op[2] == '\n')
		g_pb++;
	else if (ft_strncmp(op, "ra", 2) == 0 && op[2] == '\n')
		g_ra++;
	else if (ft_strncmp(op, "rb", 2) == 0 && op[2] == '\n')
		g_rb++;
	else if (ft_strncmp(op, "rr", 2) == 0 && op[2] == '\n')
		g_rr++;
	else if (ft_strncmp(op, "rra", 3) == 0 && op[3] == '\n')
		g_rra++;
	else if (ft_strncmp(op, "rrb", 3) == 0 && op[3] == '\n')
		g_rrb++;
	else if (ft_strncmp(op, "rrr", 3) == 0 && op[3] == '\n')
		g_rrr++;
}

static long	bench_total_ops(void)
{
	return (g_sa + g_sb + g_ss + g_pa + g_pb + g_ra + g_rb + g_rr + g_rra + g_rrb + g_rrr);
}

void	bench_print_summary(double disorder)
{
	if (!g_bench)
		return ;
	dprintf(2, "[bench] disorder : %.2f%%\n", disorder * 100.0);
	dprintf(2, "[bench] strategy : %s / %s\n", g_strategy_name, g_strategy_complexity);
	dprintf(2, "[bench] total_ops : %ld\n", bench_total_ops());
	dprintf(2, "[bench] sa: %ld   sb:  %ld   pa:   %ld   pb :  %ld\n", g_sa, g_sb, g_pa, g_pb);
	dprintf(2, "[bench] ra: %ld  rb :  %ld    rr:  %ld   rra:  %ld   rrb:  %ld   rrr: %ld\n",
		g_ra, g_rb, g_rr, g_rra, g_rrb, g_rrr);
}
