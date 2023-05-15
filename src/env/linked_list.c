/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astaroth <astaroth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 16:42:42 by astaroth          #+#    #+#             */
/*   Updated: 2023/05/15 16:43:31 by astaroth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_add_env_back(t_node *node, t_node *new)
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

t_node	*ft_env_new(void)
{
	t_node	*node;

	node = malloc(sizeof(t_node));
	node->back = NULL;
	node->data = NULL;
	node->next = NULL;
	node->token = -1;
	return (node);
}

t_node	*ft_last_env(t_node *head)
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
