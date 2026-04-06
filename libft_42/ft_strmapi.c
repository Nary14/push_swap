/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: traomeli <traomeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 16:41:52 by traomeli          #+#    #+#             */
/*   Updated: 2026/01/29 22:07:31 by traomeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*allocate;
	unsigned int	i;

	if (!s || !f)
		return (NULL);
	allocate = malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!allocate)
		return (NULL);
	i = 0;
	while (s[i])
	{
		allocate[i] = f(i, s[i]);
		i++;
	}
	allocate[i] = '\0';
	return (allocate);
}
