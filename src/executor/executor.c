/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johmatos <johmatos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 17:41:22 by johmatos          #+#    #+#             */
/*   Updated: 2023/07/18 14:08:33 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_node	*dup_node(t_node *target)
{
	t_node	*node;

	node = list_node_new();
	node->str = ft_strdup(target->str);
	node->token = target->token;
	node->next = NULL;
	return (node);
}

t_node	*inset_at_arr(t_node *cursor, t_node **arr, t_node *head, int *i)
{
	head = dup_node(cursor);
	cursor = cursor->next;
	while (cursor && cursor->token != T_PIPE)
	{
		list_add_back(list_last_node(head), dup_node(cursor));
		cursor = cursor->next;
	}
	arr[*i] = head;
	(*i)++;
	return (cursor);
}

void	create_commnd_list(t_databus *data, t_node **arr)
{
	t_node	*head;
	t_node	*cursor;
	int		i;

	i = 0;
	head = NULL;
	cursor = data->cmds->head;
	while (cursor)
	{
		while (cursor && ((cursor->token != T_PIPE && *cursor->str == 0)
				|| cursor->token == T_SPACE))
			cursor = cursor->next;
		if (!cursor)
			return ;
		if (cursor->token == T_PIPE)
		{
			arr[i] = NULL;
			cursor = cursor->next;
			i++;
			continue ;
		}
		cursor = inset_at_arr(cursor, arr, head, &i);
		cursor = next_node_with_this_token(cursor, T_WORD);
	}
}

t_node	**prepare_commands(t_databus *data, int *i)
{
	t_node	*cursor;
	t_node	**cmds;

	cursor = data->cmds->head;
	while (cursor)
	{
		if (cursor->token == T_PIPE)
			(*i)++;
		cursor = cursor->next;
	}
	cmds = ft_calloc(*i + 1, sizeof(t_node *));
	create_commnd_list(data, cmds);
	return (cmds);
}

void	executor(t_databus *data)
{
	t_node	**cmds;
	int		i;

	i = 1;
	if (getter_data()->exit_status == 130)
		return ;
	cmds = prepare_commands(data, &i);
	getter_data()->cmds->idx = 0;
	getter_data()->cmds->last_cmd_idx = i - 1;
	getter_data()->cmds->arr_cmds = cmds;
	if (i == 1)
		one_command(cmds[getter_data()->cmds->idx]);
	else
		mult_commands(cmds);
	after_execution();
}
