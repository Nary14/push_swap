/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: traomeli <traomeli@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 22:36:41 by traomeli          #+#    #+#             */
/*   Updated: 2026/01/22 21:25:07 by traomeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*desti;
	unsigned char	*srci;

	i = 0;
	desti = dest;
	srci = (unsigned char *)src;
	while (i < n)
	{
		desti[i] = srci[i];
		i++;
	}
	return (desti);
}
