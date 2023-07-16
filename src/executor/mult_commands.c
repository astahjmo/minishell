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

void	close_pipe_fds(int *pipe_fds)
{
	close(pipe_fds[0]);
	close(pipe_fds[1]);
}

static void	dup2_and_close(int fd, int clone)
{
	dup2(fd, clone);
	close(fd);
}

void	child_routine(t_node *cmds, int count)
{
	t_process_io	*fds;

	fds = command_hook(count);
	if (fds->input > 2)
		dup2_and_close(fds->input, STDIN_FILENO);
	if (fds->output > 2)
		dup2_and_close(fds->output, STDOUT_FILENO);
	exec_command(cmds);
	exit(1);
}

void	mult_command(t_node **cmds)
{
	int		pipe_fds[2];
	int		bkp_fd;
	int		cmd_count;
	pid_t	pid;

	cmd_count = 0;
	bkp_fd = STDIN_FILENO;
	while (cmds[cmd_count])
	{
		pipe(pipe_fds);
		pid = fork();
		if (pid == 0)
		{
			if (bkp_fd != 0)
				dup2(bkp_fd, STDIN_FILENO);
			close(pipe_fds[0]);
			if (cmd_count != getter_data()->cmds->idx)
				dup2(pipe_fds[1], STDOUT_FILENO);
			child_routine(cmds[cmd_count], cmd_count);
		}
		cmd_count++;
		bkp_fd = dup(pipe_fds[0]);
		close_pipe_fds(pipe_fds);
	}
	close(bkp_fd);
}
