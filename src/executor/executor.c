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

void	executor(t_databus *data)
{
	t_tokens		builtin_idx;
	t_fn_built_exec	**exec;
	t_node			*cursor;

	exec = get_built_func();
	cursor = data->cmds->head;
	while (cursor)
	{
		builtin_idx = is_builtin(cursor->str);
		if (builtin_idx != -1)
			exec[builtin_idx](cursor);
		cursor = cursor->next;
	}
	return ;
}
