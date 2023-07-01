/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_linked_list.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 16:42:56 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/06/28 16:49:37 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_node	*create_new_node(void *content, t_tokens tok)
{
	t_node	*node;

	node = (t_node *)malloc(sizeof(*node));
	node->str = content;
	node->token = tok;
	node->next = NULL;
	return (node);
}

void	lstfree(t_node **list)
{
	t_node	*tmp;

	tmp = *list;
	if (list == NULL)
		return ;
	while (tmp)
	{
		*list = tmp->next;
		free(tmp);
		tmp = *list;
	}
	free(list);
}

void	lstadd_back(t_node **lst, t_node *nw)
{
	t_node	*temp;

	if (!lst || !nw)
		return ;
	if (!*lst)
	{
		*lst = nw;
		return ;
	}
	temp = *lst;
	while (temp->next)
		temp = temp->next;
	temp->next = nw;
	nw->next = NULL;
}
