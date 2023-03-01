/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johmatos <johmatos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 16:58:26 by johmatos          #+#    #+#             */
/*   Updated: 2022/12/12 14:43:41 by johmatos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_node *ft_lstmap(t_node *lst, void *(*f)(void *), void (*del)(void *))
{
	t_node		*new;
	t_node		*list;

	if (!lst)
		return (NULL);
	list = f(lst);
	new = list;
	while (lst->next)
	{
		lst = lst->next;
		if (!(list->next = f(lst)))
		{
			ft_lstclear(&list, del);
			return (NULL);
		}
		list = list->next;
	}
	return (new);
}
