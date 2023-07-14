/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johmatos <johmatos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 05:41:48 by johmatos          #+#    #+#             */
/*   Updated: 2023/07/04 13:22:47 by johmatos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <stdlib.h>

void	list_add_back(t_node *old_node, t_node *new)
{
	t_node	*temp;

	if (!old_node)
		return ;
	temp = old_node->next;
	new->next = temp;
	old_node->next = new;
	return ;
}

t_node	*list_node_new(void)
{
	t_node	*node;

	node = malloc(sizeof(t_node));
	node->str = NULL;
	node->next = NULL;
	node->token = -1;
	return (node);
}

t_node	*list_last_node(t_node *head)
{
	t_node	*cursor;

	if (!head)
		return (NULL);
	cursor = head;
	while (cursor->next != NULL)
		cursor = cursor->next;
	return (cursor);
}

void	list_addfront(t_node *old, t_node *new)
{
	t_node	temp;

	if (!old)
		return ;
	temp = *old;
	*old = *new;
	*new = temp;
	old->next = new;
}

t_node	*next_node_with_this_token(t_node *node, t_tokens token)
{
	if (!node)
		return (NULL);
	while (node->token != token)
		node = node->next;
	return (node);
}
