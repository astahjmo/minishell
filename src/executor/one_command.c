/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   one_command.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johmatos <johmatos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 17:41:22 by johmatos          #+#    #+#             */
/*   Updated: 2023/07/07 19:55:50 by johmatos         ###   ########.fr       */
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

int	*command_hook(int cmd_count)
{
	int	*o_redir;
	int	*i_redir;
	int	*re;

	re = getter_fds();
	i_redir = getter_heredoc_fd();
	o_redir = getter_redirections();
	if (i_redir[cmd_count] > 2)
		re[IN_FD] = i_redir[cmd_count];
	if (o_redir[cmd_count] > 2)
		re[OUT_FD] = o_redir[cmd_count];
	return (re);
}

int	*getter_fds(void)
{
	static int	fds[2] = {IN_FD, OUT_FD};

	return (fds);
}

static void	dup2_and_close(int fd, int clone)
{
	dup2(fd, clone);
	close(fd);
}

static void	fork_and_execute(t_node *cmds, t_node **free_if_invalid)
{
	pid_t	pid;
	int		i;
	int		*fds;
	int		cmd_count;

	cmd_count = getter_data()->cmds->idx;
	pid = fork();
	if (pid < 0)
		printf("sda\n");
	i = 0;
	fds = command_hook(cmd_count);
	if (pid == 0)
	{
		if (fds[IN_FD] > 2)
			dup2_and_close(fds[IN_FD], STDIN_FILENO);
		if (fds[OUT_FD] > 2)
			dup2_and_close(fds[OUT_FD], STDOUT_FILENO);
		exec_command(cmds, free_if_invalid);
		exit(1);
	}
	else
		waitpid(pid, &i, 0);
	getter_data()->exit_status = WEXITSTATUS(i);
}

void	one_command(t_node *cmds, t_node **free_if_invalid)
{
	t_tokens		builtin_idx;
	t_fn_built_exec	**exec;

	exec = get_built_func();
	builtin_idx = is_builtin(cmds->str);
	if (builtin_idx != -1)
		exec[builtin_idx](cmds);
	else
		fork_and_execute(cmds, free_if_invalid);
}
