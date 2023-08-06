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

t_bool	skip_at_pipe_or_word(void)
{
	t_cmds	*c;

	c = getter_data()->cmds;
	return (c->cursor && ((c->cursor->token != T_PIPE && *c->cursor->str == 0)
			|| c->cursor->token == T_SPACE));
}

t_node	*dup_node(t_node *target)
{
	t_node	*node;

	node = list_node_new();
	node->str = ft_strdup(target->str);
	node->token = target->token;
	node->next = NULL;
	return (node);
}

void	create_arr_cmds(t_databus *data, t_node **arr)
{
	t_cmds	*c;

	c = data->cmds;
	while (c->cursor)
	{
		while (skip_at_pipe_or_word())
			c->cursor = c->cursor->next;
		if (!c->cursor)
			return ;
		if (c->cursor->token == T_PIPE)
		{
			arr[c->tmp_idx++] = NULL;
			c->cursor = c->cursor->next;
			continue ;
		}
		c->tmp_head = dup_node(c->cursor);
		c->cursor = c->cursor->next;
		while (c->cursor && c->cursor->token != T_PIPE)
		{
			list_add_back(list_last_node(c->tmp_head), dup_node(c->cursor));
			c->cursor = c->cursor->next;
		}
		arr[c->tmp_idx++] = c->head;
		c->cursor = next_node_with_this_token(c->cursor, T_WORD);
	}
}

t_node	**prepare_commands(t_databus *data, int *i)
{
	t_node	*cursor;
	t_node	**cmds;

	cursor = data->cmds->head;
	data->cmds->tmp_idx = 0;
	data->cmds->cursor = data->cmds->head;
	while (cursor)
	{
		if (cursor->token == T_PIPE)
			(*i)++;
		cursor = cursor->next;
	}
	cmds = ft_calloc(*i + 1, sizeof(t_node *));
	create_arr_cmds(data, cmds);
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
