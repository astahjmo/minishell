/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mult_command_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johmatos <johmatos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 20:46:31 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/08/12 18:42:32 by johmatos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	wait_all_children(int bkp_fd, int *pids)
{
	int	count;
	int	status;

	count = 0;
	status = 0;
	while (count <= getter_data()->cmds->last_cmd_idx)
	{
		waitpid(pids[count], &status, 0);
		set_exit_code(status);
		count++;
	}
	if (bkp_fd > 2)
		close(bkp_fd);
}

t_bool	handle_empty_string(t_node **cmds, int *cmd_count)
{
	if (cmds[*cmd_count] == NULL)
	{
		(*cmd_count)++;
		getter_data()->cmds->idx++;
		return (TRUE);
	}
	return (FALSE);
}

pid_t	*arr_of_pid(int total_commands)
{
	pid_t	*arr;

	arr = ft_calloc(sizeof(pid_t), total_commands);
	return (arr);
}
