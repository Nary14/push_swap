/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: traomeli <traomeli@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 16:14:53 by traomeli          #+#    #+#             */
/*   Updated: 2026/01/22 21:27:55 by traomeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int				i;
	unsigned char	*s1;

	s1 = (unsigned char *)s;
	if ((char)c == '\0')
	{
		i = ft_strlen(s);
		return ((char *)&s1[i]);
	}
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
		{
			return ((char *)&s1[i]);
		}
		i++;
	}
	return (NULL);
}
