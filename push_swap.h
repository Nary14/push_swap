/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: traomeli <traomeli@student.42Antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 07:51:56 by traomeli          #+#    #+#             */
/*   Updated: 2026/04/06 15:49:20 by traomeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft_42/libft.h"
# include <limits.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_bench
{
	int		active;
	char	*strategy_name;
	char	*strategy_complexity;
	long	sa;
	long	sb;
	long	ss;
	long	pa;
	long	pb;
	long	ra;
	long	rb;
	long	rr;
	long	rra;
	long	rrb;
	long	rrr;
}	t_bench;

t_bench		*ft_bench(void);

typedef struct s_node
{
	int				value;
	int				index;
	struct s_node	*next;
}	t_node;

typedef struct s_chunk
{
	int	*s;
	int	cs;
	int	total_size;
}	t_chunk;

void		ft_error(void);
void		ft_error_exit(void);
long		ft_atol(const char *str);

int			ft_isdigit(int c);

int			parse_args(int argc, char **argv, t_node **a);
int			is_valid_int(const char *s);

int			has_duplicate(t_node *stack, int value);

t_node		*new_node(int value);
void		add_back(t_node **stack, t_node *new_n);
void		add_front(t_node **stack, t_node *new_n);
int			stack_size(t_node *stack);

void		free_stack(t_node **stack);

void		rotate_to_top_a(t_node **a, int pos);
void		rotate_to_top_b(t_node **b, int pos);

void		sa(t_node **a, int print);
void		sb(t_node **b, int print);
void		ss(t_node **a, t_node **b, int print);
void		pa(t_node **a, t_node **b, int print);
void		pb(t_node **a, t_node **b, int print);
void		ra(t_node **a, int print);
void		rb(t_node **b, int print);
void		rr(t_node **a, t_node **b, int print);
void		rra(t_node **a, int print);
void		rrb(t_node **b, int print);
void		rrr(t_node **a, t_node **b, int print);

void		assign_index(t_node *a);
void		ft_simple_sort(t_node **a, t_node **b, int size);
void		ft_chunk_sort(t_node **a, t_node **b, int chunks);
void		ft_radix_sort(t_node **a, t_node **b);
void		ft_adaptive_sort(t_node **stack1, t_node **stack2);

void		push_swap(t_node **a, t_node **b);

void		ft_float(double n, int precision, int fd);

int			pos_of_first_in_range(t_node *a, int lowv, int highv);
int			pos_of_max(t_node *s);

void		bench_init(void);
void		bench_log(char *op, int print);
void		bench_log_ops(char *op);
void		bench_print_summary(double disorder);

int			is_flag(char *s, char *flag, int len);
void		set_adaptive_complexity(double disorder);
void		run_sort(t_node **a, t_node **b, int mode);
void		check_has_numbers(int argc, char **argv);
void		set_strategy(double disorder, int size);
void		parse_flags(int argc, char **argv, int *mode, int *bench);
char		**build_new_argv(int argc, char **argv, int *new_argc);
double		compute_disorder(t_node *a);

#endif
