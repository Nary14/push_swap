/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marasolo <marasolo@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 05:55:20 by marasolo          #+#    #+#             */
/*   Updated: 2026/03/24 08:34:21 by marasolo         ###   ########.fr       */
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

//verifie les doublent
int	duplicat(t_list *stack, int valu)
{
	t_list	*tmp;
	int		*count;

	tmp = stack
	while (tmp)
	{
		count = (int *)tmp->content
		if (*count == num)
			return (1);
		tmp = tmp->next;
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
