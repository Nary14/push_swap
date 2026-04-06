/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: traomeli <traomeli@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 00:25:32 by traomeli          #+#    #+#             */
/*   Updated: 2026/01/22 21:27:45 by traomeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *l, int m, size_t n)
{
	size_t			i;
	unsigned char	*p;

	i = 0;
	p = l;
	while (i < n)
	{
		p[i] = m;
		i++;
	}
	return (l);
}
