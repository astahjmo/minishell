/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johmatos <johmatos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 17:41:22 by johmatos          #+#    #+#             */
/*   Updated: 2023/07/12 18:35:45 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	create_commnd_list(t_databus *data, t_node **arr)
{
	t_node	*cursor;
	int		i;
	t_node	*head;
	t_node	*tmp;

	i = 0;
	cursor = data->cmds->head;
	while (cursor)
	{
		head = cursor;
		while (cursor && cursor->token != T_PIPE)
		{
			cursor = cursor->next;
			continue ;
		}
		if (cursor)
		{
			tmp = cursor->next;
			cursor->next = NULL;
			cursor = tmp;
		}
		arr[i] = head;
		i++;
		cursor = list_get_token(cursor, T_WORD);
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
	cmds = ft_calloc(*i, sizeof(t_node *));
	create_commnd_list(data, cmds);
	return (cmds);
}

void	after_execution(void)
{
	int			idx;
	t_file_io	*file_io;

	idx = 0;
	file_io = getter_t_file_io();
	while (idx <= getter_data()->cmds->idx)
	{
		if (file_io[idx].input > 2)
			close(file_io[idx].input);
		if (file_io[idx].output > 2)
			close(file_io[idx].output);
		ft_bzero(&file_io[idx], sizeof(int) * 2);
		idx++;
	}
}

void	executor(t_databus *data)
{
	t_node	**cmds;
	int		i;

	i = 1;
	cmds = prepare_commands(data, &i);
	getter_data()->cmds->idx = 0;
	getter_data()->cmds->arr_cmds = cmds;
	if (i == 1)
		one_command(cmds[getter_data()->cmds->idx], cmds);
	else
	{
		while (i-- != 1)
		{
			getter_data()->cmds->idx++;
		}
		one_command(cmds[getter_data()->cmds->idx], cmds);
	}
	after_execution();
	free(cmds);
}
