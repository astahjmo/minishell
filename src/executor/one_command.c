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
#include <readline/history.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <time.h>
#include <unistd.h>

int	command_hook(int cmd_count)
{
	int	*o_redir;
	int	*i_redir;
	int	re;

	re = 0;
	i_redir = getter_heredoc_fd();
	o_redir = getter_redirections();
	if (i_redir[cmd_count] > 2)
		re = dup2(i_redir[cmd_count], STDIN_FILENO);
	if (o_redir[cmd_count] > 2)
		re = dup2(o_redir[cmd_count], STDOUT_FILENO);
	return (re);
}

static void	fork_and_execute(t_node *cmds)
{
	pid_t	pid;
	int		i;

	pid = fork();
	if (pid < 0)
		printf("sda\n");
	i = 0;
	if (pid == 0)
		exec_command(cmds);
	else
		waitpid(pid, &i, 0);
	getter_data()->exit_status = WEXITSTATUS(i);
}

void	one_command(t_node *cmds)
{
	t_tokens		builtin_idx;
	t_fn_built_exec	**exec;

	exec = get_built_func();
	builtin_idx = is_builtin(cmds->str);
	if (builtin_idx != -1)
		exec[builtin_idx](cmds);
	else
		fork_and_execute(cmds);
}
