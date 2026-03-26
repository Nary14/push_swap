/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: traomeli <traomeli@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/26 06:46:26 by traomeli          #+#    #+#             */
/*   Updated: 2026/03/26 07:12:08 by traomeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void reverse_rotate_stack (t_list **stack)
{
    t_list *prev;
    t_list *temp;
    
    if (!stack || !*stack)
        return ;
    prev = *stack;
    while (prev->next->next != NULL)
        prev = prev->next;
    temp = prev->next;
    prev->next = NULL;
    ft_listadd_front(stack, temp);
}

void rra (t_list **stack_a)
{
    reverse_rotate_stack(stack_a);
    ft_putstr_fd("rra\n", 1);
}

void rrb (t_list **stack_b)
{
    reverse_rotate_stack(stack_b);
    ft_putstr_fd("rrb\n", 1);
}

void rrr (t_list **stack_a, t_list **stack_b)
{
    reverse_rotate_stack(stack_a);
    reverse_rotate_stack(stack_b);
    ft_putstr_fd("rrr\n", 1);
}
