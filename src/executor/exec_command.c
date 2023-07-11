/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_command.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johmatos <johmatos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 17:41:22 by johmatos          #+#    #+#             */
/*   Updated: 2023/07/07 19:44:43 by johmatos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

static int	count_nodes(t_node *cmds)
{
	int	count;

	count = 0;
	while (cmds)
	{
		if (cmds->token != T_SPACE)
			count++;
		cmds = cmds->next;
	}
	return (count);
}

static char	**create_args(t_node *cmds)
{
	int		i;
	t_node	*cursor;
	char	**cmds_pars;

	i = count_nodes(cmds);
	cursor = cmds;
	cmds_pars = malloc((i + 1) * sizeof(char *));
	i = 0;
	while (cursor)
	{
		if (cursor && cursor->token == T_SPACE)
		{
			cursor = cursor->next;
			continue ;
		}
		cmds_pars[i] = cursor->str;
		cursor = cursor->next;
		i++;
	}
	cmds_pars[i] = NULL;
	return (cmds_pars);
}

char	**create_envs(void)
{
	char	**envps;
	int		i;

	i = -1;
	envps = malloc((getter_data()->number_of_envs + 1) * (sizeof(char *)));
	while (getter_data()->number_of_envs != ++i)
		envps[i] = getter_data()->envp[i];
	envps[i] = NULL;
	return (envps);
}

void	exec_command(t_node *cmd, t_node **free_if_invalid)
{
	char	*path;
	char	**args;
	char	**envs;
	t_cmds	ar;

	signal(SIGINT, SIG_DFL);
	path = get_cmd_path(cmd->str);
	ar.head = cmd;
	if (path == NULL)
	{
		printf("minishell: %s: comando não encontrado\n", cmd->str);
		free(free_if_invalid);
		free_cmds(&ar);
		free_all(getter_data());
		exit(127);
	}
	args = create_args(cmd);
	envs = create_envs();
	execve(path, args, envs);
}
