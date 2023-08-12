/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_command.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johmatos <johmatos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 17:41:22 by johmatos          #+#    #+#             */
/*   Updated: 2023/08/12 19:05:37 by johmatos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "minishell.h"

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
	while (cursor && cursor->token != T_PIPE)
	{
		if (cursor && cursor->token == T_SPACE)
		{
			cursor = cursor->next;
			continue ;
		}
		if (cursor->token != T_SPACE)
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

static void	exec_command_frees(char **path, char **args, char **envs, char **s)
{
	free(*path);
	free(args);
	free(envs);
	free(*s);
}

void	exec_command(t_node *cmd)
{
	char	*path;
	char	**args;
	char	**envs;
	char	*s;

	signal(SIGINT, handle_sigint);
	path = get_cmd_path(cmd->str);
	args = create_args(cmd);
	envs = create_envs();
	s = fmt_s("minishell: %s: comando não encontrado\n", cmd->str, 0, 0);
	if (!test_directory(path))
	{
		ft_putstr_fd(s, STDERR_FILENO);
		exec_command_frees(&path, args, envs, &s);
		return ;
	}
	if (path)
		execve(path, args, envs);
	exec_command_frees(&path, args, envs, &s);
	execve_error(cmd);
}
