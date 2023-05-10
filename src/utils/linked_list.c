/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johmatos <johmatos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 05:41:48 by johmatos          #+#    #+#             */
/*   Updated: 2023/05/10 06:01:50 by johmatos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <stdlib.h>

void	ft_add_back(t_node *node, t_node *new)
{
	t_node	*temp;

	if (!node)
		return ;
	temp = node->next;
	new->next = temp;
	node->next = new;
	new->back = node;
	return ;
}

t_node	*ft_node_new(void)
{
	t_node	*node;

	node = malloc(sizeof(t_node));

	node->back = NULL;
	node->head = NULL;
	node->data = NULL;
	node->next = NULL;
	node->token = -1;

	return (node);
}
t_node	*ft_last_node(t_node *head)
{
	t_node *cursor;

	cursor = head;

	while (cursor->next != NULL)
		cursor = cursor->next;
	return (cursor);
}

void	 ft_addfront(t_node *old, t_node *new)
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
