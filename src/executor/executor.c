/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johmatos <johmatos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 17:41:22 by johmatos          #+#    #+#             */
/*   Updated: 2023/07/04 13:09:04 by johmatos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "minishell.h"
#include <stdio.h>
#include <stdlib.h>

static int	init_redir(void)
{
	int	status;

	status = init_heredoc(getter_data()->cmds->head);
	if (WEXITSTATUS(status) == 129)
		return (status);
	status = init_redirections(getter_data()->cmds->head);
	return (status);
}

int	pre_executor(t_databus *data)
{
	t_node			*head;
	unsigned int	status;

	status = init_redir();
	if (WEXITSTATUS(status) == 129)
		return (status);
	head = remove_operators(data->cmds->head);
	free_cmds(data->cmds);
	data->cmds->head = head;
	return (status);
}

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

void	executor(t_databus *data)
{
	t_node			**cmds;
	int				i;

	i = 1;
	cmds = prepare_commands(data, &i);
	one_command(cmds[0]);
}
