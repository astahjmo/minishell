/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johmatos <johmatos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 17:41:22 by johmatos          #+#    #+#             */
/*   Updated: 2023/06/21 19:41:46 by johmatos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "minishell.h"

static int	is_operator(t_tokens token)
{
	return (token > T_INITIAL && token <= T_OUT_REDIR);
}

t_node	*create_new_list(t_node *cursor)
{
	t_node	*new_node;

	new_node = list_node_new();
	new_node->token = cursor->token;
	new_node->str = ft_strdup(cursor->str);
	new_node->next = NULL;
	return (new_node);
}

static void	add_to_new_list(t_node **head, t_node *cursor)
{
	t_node	*node;

	if (*head == NULL)
	{
		*head = create_new_list(cursor);
		return ;
	}
	else if (list_last_node(*head)->token == T_SPACE
		&& cursor->token == T_SPACE)
		return ;
	node = create_new_list(cursor);
	list_add_back(list_last_node(*head), node);
}

t_node	*remove_operators(t_node *cursor)
{
	t_node	*head;
	int		status;
	t_node	*tmp;

	head = NULL;
	status = 0;
	while (cursor)
	{
		if ((is_operator(cursor->token) && cursor->token != T_PIPE)
			|| status == 1)
		{
			if (status == 1 && cursor->token != T_SPACE)
				status = 0;
			else
				status = 1;
			cursor = cursor->next;
			continue ;
		}
		tmp = cursor->next;
		add_to_new_list(&head, cursor);
		cursor = tmp;
	}
	return (head);
}
