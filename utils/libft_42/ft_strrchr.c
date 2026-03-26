/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: traomeli <traomeli@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 06:15:06 by traomeli          #+#    #+#             */
/*   Updated: 2026/01/22 20:11:51 by traomeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int				i;
	unsigned char	*s1;

	s1 = (unsigned char *)s;
	i = ft_strlen(s);
	while (i >= 0)
	{
		if (s1[i] == (unsigned char)c)
		{
			return ((char *)(s1 + i));
		}
		i--;
	}
	return (NULL);
}
