/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: traomeli <traomeli@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/26 06:21:57 by traomeli          #+#    #+#             */
/*   Updated: 2026/03/26 06:54:55 by traomeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
void rotate_stack (t_node **stack)
{
    int *temp;

    if (!stack || !*stack)
        return ; 
    temp = *stack;
    *stack = temp->next;
    temp->next = NULL;
    add_back(stack, temp);
}

void	ra(t_node **a, int print)
{
    rotate_stack(stack_a);
    if (print)
      ft_putstr_fd("ra\n", 1);
}

void	rb(t_node **b, int print)
{
    rotate_stack(stack_b);
    if (print)
      ft_putstr_fd("rb\n", 1);
}

void	rr(t_node **a, t_node **b, int print)
{
    rotate_stack(stack_a);
    rotate_stack(stack_b);
    if (print)
      ft_putstr_fd("rr\n", 1);
}
