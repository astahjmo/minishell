/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johmatos <johmatos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 14:47:17 by johmatos          #+#    #+#             */
/*   Updated: 2022/12/12 14:51:48 by johmatos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void ft_lstclear(t_node **lst, void (*del)(void*))
{
	t_node *cursor;
	t_node *next;

	cursor = *lst;
	while (cursor)
	{
		next = cursor->next;
		del(cursor->value);
		free(cursor);
		cursor = next;
	}
}
