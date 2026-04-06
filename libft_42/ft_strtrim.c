/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: traomeli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 10:19:22 by traomeli          #+#    #+#             */
/*   Updated: 2026/01/26 13:36:36 by traomeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(const char *s1, const char *set)
{
	size_t	start;
	size_t	end;
	size_t	len;
	char	*res;

	if (!s1 || !set)
		return (NULL);
	len = ft_strlen(s1);
	start = 0;
	while (start < len && ft_strchr(set, s1[start]))
		start++;
	if (start == len)
		return (ft_strdup(""));
	end = len - 1;
	while (end > start && ft_strchr(set, s1[end]))
		end--;
	res = (char *)malloc(end - start + 2);
	if (!res)
		return (NULL);
	ft_strlcpy(res, s1 + start, end - start + 2);
	return (res);
}
