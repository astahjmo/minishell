/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mult_commands.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johmatos <johmatos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 20:14:51 by johmatos          #+#    #+#             */
/*   Updated: 2023/07/16 15:02:53 by johmatos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	close_pipe_fds(int *fds)
{
	close(fds[0]);
	close(fds[1]);
}

static int	dup2_and_close(int fd, int clone)
{
	int	a;

	a = dup2(fd, clone);
	close(fd);
	return (a);
}

static void	main_routine(pid_t pid, int *bkp_fd, int *count, int *pipes_fds)
{
	int	status;

	waitpid(pid, &status, 0);
	(*count)++;
	*bkp_fd = dup(pipes_fds[0]);
	close_pipe_fds(pipes_fds);
	getter_data()->exit_status = WEXITSTATUS(status);
}

void	child_routine(t_node *cmds, int count)
{
	t_io			*cmd;
	t_fn_built_exec	**exec;
	t_tokens		builtin_idx;

	cmd = command_hook(count);
	exec = get_built_func_arr();
	builtin_idx = is_builtin(cmds->str);
	if (cmd->input > 2)
		cmd->input = dup2_and_close(cmd->input, STDIN_FILENO);
	if (cmd->output > 2)
		cmd->output = dup2_and_close(cmd->output, STDOUT_FILENO);
	if (builtin_idx != T_INVALID)
		exec[builtin_idx](cmds);
	else
		exec_command(cmds);
	exit(0);
}

void	mult_command(t_node **cmds)
{
	int		fds[2];
	int		bkp_fd;
	int		cmd_count;
	pid_t	pid;
	t_io	*stdio;

	stdio = getter_stdio();
	cmd_count = 0;
	bkp_fd = STDIN_FILENO;
	while (cmd_count <= getter_data()->cmds->idx)
	{
		pipe(fds);
		pid = fork();
		if (pid == CHILD_PROCESS)
		{
			if (bkp_fd != 0)
				stdio->input = dup2_and_close(bkp_fd, STDIN_FILENO);
			close(fds[0]);
			if (cmd_count != getter_data()->cmds->idx)
				stdio->output = dup2_and_close(fds[1], STDOUT_FILENO);
			child_routine(cmds[cmd_count], cmd_count);
		}
		main_routine(pid, &bkp_fd, &cmd_count, fds);
	}
	close(bkp_fd);
}
