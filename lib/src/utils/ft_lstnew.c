/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johmatos <johmatos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 13:53:25 by johmatos          #+#    #+#             */
/*   Updated: 2022/12/13 12:48:18 by johmatos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_node *ft_lstnew(void* content)
{
	t_node *new;

	new = malloc(sizeof(t_node) * 1);
	if (!new)
		return ((void *) NULL);
	new->value = content;
	new->next = (void *) NULL;
	return (new);
}
