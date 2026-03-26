/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marasolo <marasolo@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/26 05:27:48 by marasolo          #+#    #+#             */
/*   Updated: 2026/03/26 09:57:43 by marasolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int find_min_index(t_list **stack)
{
    
}

void	ft_simple_sort_2(t_list	**stack)
{
	int	*a;
	int	*b;
	
	a = (int *)stack->content;
	b = (int *)stack->next->content;
	if (*a > *b)
        sa(&stack);
}

void	ft_simple_sort_3(t_list **stack)
{
	int	*a;
	int	*b;
	int	*c;

	a = (int *)stack->content;
	b = (int *)stack->next->content;
	c = (int *)stack->next->next->content;
	if (*a > *b && *b < *c && *a < *c)
        sa(&stack);
	else if (*a > *b && *b > *c)
    {
        sa(&stack);
        rra(&stack);
    }
	else if (*a > *b && *b < *c && *a > *c)
        ra(&stack);
	else if (*a < *b && *b > *c && *a < *c)
	{
        sa(&stack);
        ra(&stack);
    }
	else if (*a < *b && *b > *c && *a > *c)
        rra(&stack);
}

void	ft_simple_sort_plus4(t_list **stack1, t_list **stack2, int size)
{

}

void	ft_simple_sort(t_list **stack1, t_list **stack2, int size)
{
	if (size == 2)
		ft_simple_sort_2(stack1);
	else if (size == 3)
		ft_simple_sort_3(stack1);
	else
		ft_simple_sort_plus4(stack1, stack2, size);
}