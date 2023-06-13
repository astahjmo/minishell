/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johmatos <johmatos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 17:41:22 by johmatos          #+#    #+#             */
/*   Updated: 2023/06/13 15:42:11 by johmatos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	executor(t_databus *data)
{
	char	*cmd;
	t_node	*node;

	node = data->cmds->head;
	cmd = node->data;
	if (!ft_strncmp(cmd, "exit", 5))
		exit_builtin(data);
	else if (!ft_strncmp(cmd, "env", 4))
		env_builtin(data);
	else if (!ft_strncmp(cmd, "export", 7) && node->next)
		export_builtin(data);
	else if (!ft_strncmp(cmd, "export", 7) && !node->next)
		alt_env_builtin(data);
	else if (!ft_strncmp(cmd, "unset", 6))
		unset_builtin(data);
	return ;
}
