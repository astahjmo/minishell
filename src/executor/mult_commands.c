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

#include "libft.h"
#include "minishell.h"
#include <sys/types.h>
#include <unistd.h>

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
}

void	child_routine(t_node *cmds, int count)
{
	t_process_io	*fds;
	t_fn_built_exec	**exec;
	t_tokens		builtin_idx;

	fds = command_hook(count);
	exec = get_built_func_arr();
	builtin_idx = is_builtin(cmds->str);
	if (fds->input > 2)
		fds->input = dup2_and_close(fds->input, STDIN_FILENO);
	if (fds->output > 2)
		fds->output = dup2_and_close(fds->output, STDOUT_FILENO);
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

	cmd_count = 0;
	bkp_fd = STDIN_FILENO;
	while (cmds[cmd_count])
	{
		pipe(fds);
		pid = fork();
		if (pid == CHILD_PROCESS)
		{
			if (bkp_fd != 0)
				getter_stdio()->input = dup2_and_close(bkp_fd, STDIN_FILENO);
			close(fds[0]);
			if (cmd_count != getter_data()->cmds->idx)
				getter_stdio()->output = dup2_and_close(fds[1], STDOUT_FILENO);
			child_routine(cmds[cmd_count], cmd_count);
		}
		main_routine(pid, &bkp_fd, &cmd_count, fds);
	}
	close(bkp_fd);
}
