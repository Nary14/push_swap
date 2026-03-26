/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: traomeli <traomeli@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 16:39:58 by traomeli          #+#    #+#             */
/*   Updated: 2026/01/22 23:50:13 by traomeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*my_mal;
	size_t	i;

	my_mal = malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!my_mal || !s)
		return (NULL);
	i = 0;
	while (s[i])
	{
		my_mal[i] = s[i];
		i++;
	}
	my_mal[i] = '\0';
	return (my_mal);
}
