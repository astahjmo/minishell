/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   after_execution.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 14:00:01 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/07/18 14:08:33 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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

	s = fmt_s("minishell: %s: Algum acabou de acontecer!", cmd->str, 0, 0);
	ft_putendl_fd(s, STDERR_FILENO);
	getter_data()->exit_status = 126;
	free(s);
}
