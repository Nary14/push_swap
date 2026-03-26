/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: traomeli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 07:33:43 by traomeli          #+#    #+#             */
/*   Updated: 2026/01/29 08:33:37 by traomeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*list_n;
	t_list	*temp;

	if (!lst || !f || !del)
		return (NULL);
	list_n = NULL;
	while (lst)
	{
		temp = ft_lstnew(f(lst->content));
		if (temp == NULL)
		{
			ft_lstclear(&list_n, del);
			return (NULL);
		}
		ft_lstadd_back(&list_n, temp);
		lst = lst->next;
	}
	return (list_n);
}
