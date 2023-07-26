/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mult_commands.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johmatos <johmatos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 20:14:51 by johmatos          #+#    #+#             */
/*   Updated: 2023/07/26 10:26:20 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <unistd.h>

static void	handle_pipe_fds(int bkp_fd, int pipe_fds[2], int cmd_count);

static void	post_child_routine(int *pipes)
{
	int	status;

	status = getter_data()->exit_status;
	close_pipe_fds(pipes);
	close(getter_stdio()->input);
	close(getter_stdio()->output);
	free_cmds_arr(getter_data()->cmds->arr_cmds);
	free_cmds(getter_data()->cmds);
	free_all(getter_data());
	exit(status);
}

static int	main_routine(int bkp_fd, int *count, int *pipe_fds)
{
	(*count)++;
	if (bkp_fd != 0)
		close(bkp_fd);
	bkp_fd = dup(pipe_fds[0]);
	close_pipe_fds(pipe_fds);
	return (bkp_fd);
}

void	child_routine(t_node *cmds, int count, int *pipes)
{
	t_io			*cmd;
	t_tokens		builtin_idx;
	t_fn_built_exec	**exec;

	cmd = command_hook(count);
	if (!cmd)
	{
		getter_data()->exit_status = 1;
		return (post_child_routine(pipes));
	}
	exec = get_built_func_arr();
	builtin_idx = is_builtin(cmds->str);
	if (cmd->input > 2)
		getter_stdio()->input = duplicate_stdin(cmd->input);
	if (cmd->output > 2)
		getter_stdio()->output = duplicate_stdout(cmd->output);
	if (builtin_idx != T_INVALID)
		exec[builtin_idx](cmds);
	else
		exec_command(cmds);
	post_child_routine(pipes);
}

void	mult_commands(t_node **cmds)
{
	int		pipe_fds[2];
	int		bkp_fd;
	int		cmd_count;
	pid_t	*pids;

	cmd_count = 0;
	bkp_fd = STDIN_FILENO;
	pids = arr_of_pid(getter_data()->cmds->last_cmd_idx + 1);
	while (cmds[cmd_count])
	{
		if (handle_empty_string(cmds, cmd_count))
			continue ;
		pipe(pipe_fds);
		pids[cmd_count] = fork();
		if (pids[cmd_count] == CHILD_PROCESS)
		{
			free(pids);
			handle_pipe_fds(bkp_fd, pipe_fds, cmd_count);
			if (bkp_fd != 0)
				close(bkp_fd);
			child_routine(cmds[cmd_count], cmd_count, pipe_fds);
		}
		bkp_fd = main_routine(bkp_fd, &cmd_count, pipe_fds);
		getter_data()->cmds->idx++;
	}
	wait_all_children(bkp_fd, pids);
	free(pids);
}

static void	handle_pipe_fds(int bkp_fd, int pipe_fds[2], int cmd_count)
{
	t_io	*stdio;

	stdio = getter_stdio();
	if (bkp_fd != 0)
		stdio->input = duplicate_stdin(bkp_fd);
	close(pipe_fds[WRTE]);
	if (cmd_count != getter_data()->cmds->last_cmd_idx)
		stdio->output = duplicate_stdout(pipe_fds[READ]);
}
