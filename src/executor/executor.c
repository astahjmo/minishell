/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johmatos <johmatos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 17:41:22 by johmatos          #+#    #+#             */
/*   Updated: 2023/06/13 17:18:32 by johmatos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "minishell.h"

void	executor(t_databus *data)
{
	char			*cmd;
	t_node			*node;
	t_tokens		builtin;
	t_fn_built_exec	**exec;

	node = data->cmds->head;
	cmd = node->data;
	exec = get_built_func();
	builtin = is_builtin(cmd);
	if (builtin != -1)
		exec[is_builtin(cmd) - 1](data);
	return ;
}
