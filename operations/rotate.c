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
void rotate_stack (t_list **stack)
{
    t_list *temp;

    if (!stack || !*stack)
        return ; 
    temp = *stack;
    *stack = temp->next;
    temp->next = NULL;
    ft_listadd_back(stack, temp);
}

void ra (t_list **stack_a)
{
    rotate_stack(stack_a);
    ft_putstr_fd("ra\n", 1);
}

void rb (t_list **stack_b)
{
    rotate_stack(stack_b);
    ft_putstr_fd("rb\n", 1);
}

void rr (t_list **stack_a, t_list **stack_b)
{
    rotate_stack(stack_a);
    rotate_stack(stack_b);
    ft_putstr_fd("rr\n", 1);
}
