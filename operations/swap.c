/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: traomeli <traomeli@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 07:39:20 by traomeli          #+#    #+#             */
/*   Updated: 2026/03/25 09:06:04 by traomeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../push_swap.h"

static void swap_top(t_list *stack)
{
    void *temp;

    if (stack == NULL || stack->next == NULL)
        return ;
    temp = stack->content;
    stack->content = stack->next->content;
    stack->next->content = temp; 
}

void sa(t_list *stack_sa)
{
    swap_top(stack_sa);
    ft_putstr_fd("sa\n", 1);
}

void sb(t_list *stack_sb)
{
    swap_top(stack_sb);
    ft_putstr_fd("sb\n", 1);
}

void ss(t_list *stack_sa, t_list *stack_sb)
{
    swap_top(stack_sa);
    swap_top(stack_sb);
    ft_putstr_fd("ss\n", 1);
}