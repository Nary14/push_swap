/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marasolo <marasolo@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 05:55:20 by marasolo          #+#    #+#             */
/*   Updated: 2026/03/23 13:03:01 by marasolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "push_swap.h"
#include <unistd.h>

#include <stdlib.h>
#include <stdio.h>

/*verifie si le chaine de carracter est un nombre valide*/
int	valid_number(char *str)
{
	int i;
	
	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

/*verifie les doublent dans le tableau*/
int	duplicat(t_stack *stack, int valu)
{
	t_node	current;

	current = stack->top;
	while (current)
	{
		if (current->valu == valu)
			return (1);
		current = current->next;
	}
	return (0);
}

void	error_exit(void)
{
	write(1, "error\n",5);
	exit(EXIT_FAILURE);
}

// int main(void)
// {
// 	error_exit();
// 	printf("%d\n", valid_number("6"));
// 	printf("%d\n", duplicat("sadf", '1'));
// 	printf("%d\n", ft_atoi("-54485"));
// }
