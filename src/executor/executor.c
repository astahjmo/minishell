/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johmatos <johmatos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 17:41:22 by johmatos          #+#    #+#             */
/*   Updated: 2023/07/07 20:14:22 by johmatos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "minishell.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

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
	int	*i_redir;
	int	*o_redir;
	int	count;

	i_redir = getter_heredoc_fd();
	o_redir = getter_redirections();
	count = 0;
	while (count <= getter_data()->cmds->cmd_count)
	{
		if (i_redir[count] > 2)
			close(i_redir[count]);
		if (o_redir[count] > 2)
			close(o_redir[count]);
		i_redir[count] = 0;
		o_redir[count] = 0;
		count++;
	}
}

void	executor(t_databus *data)
{
	t_node	**cmds;
	int		i;

	i = 1;
	cmds = prepare_commands(data, &i);
	getter_data()->cmds->cmd_count = 0;
	if (i == 1)
		one_command(cmds[getter_data()->cmds->cmd_count]);
	else
	{
		while (i-- != 1)
		{
			getter_data()->cmds->cmd_count++;
		}
		one_command(cmds[getter_data()->cmds->cmd_count]);
	}
	after_execution();
	free(cmds);
}
