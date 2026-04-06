/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: traomeli <traomeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 08:46:36 by traomeli          #+#    #+#             */
/*   Updated: 2026/01/30 00:53:25 by traomeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*allocate;

	if (s == NULL)
		return (NULL);
	if (start > ft_strlen(s))
		return (ft_strdup(""));
	if (len > ft_strlen(s) - start)
		len = ft_strlen(s) - start;
	allocate = malloc(sizeof(char) * (len + 1));
	if (!allocate)
		return (NULL);
	i = 0;
	while (i < len)
	{
		allocate[i] = s[start];
		i++;
		start++;
	}
	allocate[i] = '\0';
	return (allocate);
}
