/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marasolo <marasolo@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 07:51:56 by traomeli          #+#    #+#             */
/*   Updated: 2026/03/30 22:42:06 by marasolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "utils/libft_42/libft.h"
# include <limits.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_node
{
	int				value;
	int				index;
	struct s_node	*next;

}					t_node;

void				ft_error(void);
long				ft_atol(const char *str);

int					ft_isdigit(int c);

void				parse_args(int argc, char **argv, t_node **a);
int					is_valid_int(const char *s);

int					has_duplicate(t_node *stack, int value);

t_node				*new_node(int value);
void				add_back(t_node **stack, t_node *new_n);
void				add_front(t_node **stack, t_node *new_n);
int					stack_size(t_node *stack);
int					is_sorted(t_node *stack);

void				free_stack(t_node **stack);

void				rotate_to_top_a(t_node **a, int pos);
void				rotate_to_top_b(t_node **b, int pos);

void				sa(t_node **a, int print);
void				sb(t_node **b, int print);
void				ss(t_node **a, t_node **b, int print);
void				pa(t_node **a, t_node **b, int print);
void				pb(t_node **a, t_node **b, int print);
void				ra(t_node **a, int print);
void				rb(t_node **b, int print);
void				rr(t_node **a, t_node **b, int print);
void				rra(t_node **a, int print);
void				rrb(t_node **b, int print);

void				rrr(t_node **a, t_node **b, int print);

void				assign_index(t_node *a);
void				ft_simple_sort(t_node **a, t_node **b, int size);
void				ft_chunk_sort(t_node **a, t_node **b, int chunks);
void				ft_radix_sort(t_node **a, t_node **b);
void				ft_adaptive_sort(t_node **stack1, t_node **stack2);

void				push_swap(t_node **a, t_node **b);

int					pos_of_first_in_range(t_node *a, int lowv, int highv);
int					pos_of_max(t_node *s);

#endif
