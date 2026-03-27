/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: traomeli <traomeli@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 07:51:56 by traomeli          #+#    #+#             */
/*   Updated: 2026/03/25 09:22:28 by traomeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>


typedef struct s_node
{
    int				value;
    int				index;
    struct s_node	*next;
}	t_node;



void	ft_error(void);
long	ft_atol(const char *str);
int		ft_isdigit(int c);



void	parse_args(int argc, char **argv, t_node **a);
int		is_valid_int(const char *s);
int		has_duplicate(t_node *stack, int value);


t_node	*new_node(int value);
void	add_back(t_node **stack, t_node *new_n);
void  add_front(t_node **stack, t_node *new_n);
int		stack_size(t_node *stack);
int		is_sorted(t_node *stack);
void	free_stack(t_node **stack);


void	sa(t_node **a, int print);
void	sb(t_node **b, int print);
void	ss(t_node **a, t_node **b, int print);
void	pa(t_node **a, t_node **b, int print);
void	pb(t_node **a, t_node **b, int print);
void	ra(t_node **a, int print);
void	rb(t_node **b, int print);
void	rr(t_node **a, t_node **b, int print);
void	rra(t_node **a, int print);
void	rrb(t_node **b, int print);
void	rrr(t_node **a, t_node **b, int print);


void	assign_index(t_node *a);
void	sort_three(t_node **a);
void	sort_five(t_node **a, t_node **b);
void	radix_sort(t_node **a, t_node **b);
void	push_swap(t_node **a, t_node **b);

#endif
