/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: traomeli <traomeli@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 16:23:19 by traomeli          #+#    #+#             */
/*   Updated: 2026/02/03 23:31:11 by traomeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*mal;
	size_t	o;

	o = nmemb * size;
	if (size != 0 && nmemb != o / size)
		return (NULL);
	if (o == 0)
		mal = malloc(1);
	else
		mal = malloc(o);
	if (!mal)
		return (NULL);
	ft_bzero(mal, o);
	return (mal);
}
