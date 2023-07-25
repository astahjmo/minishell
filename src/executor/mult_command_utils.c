/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wait_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 20:46:31 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/07/19 15:03:59 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	wait_all_children(int bkp_fd, int *pids)
{
	int	count;
	int	status;

	count = 0;
	while (count <= getter_data()->cmds->total_cmds)
	{
		waitpid(pids[count], &status, 0);
		getter_data()->exit_status = WEXITSTATUS(status);
		count++;
	}
	close(bkp_fd);
}

t_bool	handle_empty_string(t_node **cmds, int cmd_count)
{
	if (*cmds[cmd_count]->str == 0)
	{
		cmd_count++;
		return (TRUE);
	}
	return (FALSE);
}

void	close_pipe_fds(int *fds)
{
	close(fds[WRTE]);
	close(fds[READ]);
}

int	dup2_and_close(int fd, int clone)
{
	int	a;

	a = dup2(fd, clone);
	return (a);
}

pid_t	*arr_of_pid(int total_commands)
{
	pid_t	*arr;

	arr = ft_calloc(sizeof(pid_t), total_commands);
	return (arr);
}
