/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: traomeli <traomeli@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 08:28:36 by traomeli          #+#    #+#             */
/*   Updated: 2026/03/25 09:21:28 by traomeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../push_swap.h"

static void push(t_node **stack_a, t_node **stack_b)
{
    int *temp;

    if (stack_a == NULL || *stack_a == NULL)
        return ;
    temp = *stack_a;
    add_front(stack_b, temp);
    *stack_a = temp->next;
}

void	pa(t_node **a, t_node **b, int print)
{
    push(stack_a, stack_b);
    if (print)
      ft_putstr_fd("pa\n", 1);
}

void	pb(t_node **a, t_node **b, int print)
{
    push(stack_a, stack_b);
    if (print)
      ft_putstr_fd("pb\n", 1);
}
