/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: traomeli <traomeli@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 00:05:34 by traomeli          #+#    #+#             */
/*   Updated: 2026/01/22 21:27:11 by traomeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*desti;
	unsigned char	*srci;

	i = 0;
	desti = (unsigned char *)dest;
	srci = (unsigned char *)src;
	if (dest > src)
	{
		while (n > 0)
		{
			desti[n - 1] = srci[n - 1];
			n--;
		}
	}
	else
	{
		while (i < n)
		{
			desti[i] = srci[i];
			i++;
		}
	}
	return (desti);
}
