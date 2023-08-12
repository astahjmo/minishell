/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   after_execution.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johmatos <johmatos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 14:00:01 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/08/12 19:04:48 by johmatos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <signal.h>
#include <stdlib.h>

static void	reset_stdin_and_out(void)
{
	getter_stdio()->input = STDIN_FILENO;
	getter_stdio()->output = STDOUT_FILENO;
}

void	after_execution(void)
{
	int				idx;
	t_io			*process_ios;

	idx = 0;
	reset_stdin_and_out();
	process_ios = getter_t_ios();
	free_cmds_arr(getter_data()->cmds->arr_cmds);
	signal(SIGINT, define_handle);
	while (idx <= getter_data()->cmds->idx)
	{
		getter_input()[idx] = 0;
		getter_output()[idx] = 0;
		getter_heredoc_tmp()[idx] = 0;
		if (process_ios[idx].input > 2)
			close(process_ios[idx].input);
		if (process_ios[idx].output > 2)
			close(process_ios[idx].output);
		ft_bzero(&process_ios[idx], sizeof(int) * 2);
		idx++;
	}
}

void	execve_error(t_node *cmd)
{
	char	*s;

	s = fmt_s("minishell: %s: execve error\n!", cmd->str, 0, 0);
	ft_putstr_fd(s, STDERR_FILENO);
	getter_data()->exit_status = 126;
	free(s);
}

void	set_exit_code(int status)
{
	if (WIFEXITED(status) == 0)
		getter_data()->exit_status = 128 + status;
	else
		getter_data()->exit_status = WEXITSTATUS(status);
}
