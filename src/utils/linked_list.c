/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astaroth <astaroth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 05:41:48 by johmatos          #+#    #+#             */
/*   Updated: 2023/05/15 17:49:28 by astaroth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <stdlib.h>

void	ft_add_back(t_node *old_node, t_node *new)
{
	t_node	*temp;

	if (!old_node)
		return ;
	temp = old_node->next;
	new->next = temp;
	old_node->next = new;
	new->back = old_node;
	return ;
}

t_node	*ft_node_new(void)
{
	t_node	*node;

	node = malloc(sizeof(t_node));
	node->back = NULL;
	node->data = NULL;
	node->next = NULL;
	node->token = -1;
	return (node);
}

t_node	*ft_last_node(t_node *head)
{
	t_node	*cursor;

	cursor = head;
	while (cursor->next != NULL)
		cursor = cursor->next;
	return (cursor);
}

void	ft_addfront(t_node *old, t_node *new)
{
	t_node	temp;

	if (!old)
		return ;
	temp = *old;
	*old = *new;
	*new = temp;
	old->next = new;
	old->back = new->back;
	new->back = old;
}
