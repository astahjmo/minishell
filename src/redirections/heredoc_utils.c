/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johmatos <johmatos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 14:23:39 by johmatos          #+#    #+#             */
/*   Updated: 2023/07/14 14:23:50 by johmatos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	*getter_pipes(void)
{
	static int	pipes[2];

	return (pipes);
}

char	**getter_buff(void)
{
	static char	*buf;

	buf = NULL;
	return (&buf);
}

void	sig_handler(int sig)
{
	if (sig != SIGINT)
		return ;
	close(getter_pipes()[0]);
	close(getter_pipes()[1]);
	free(*getter_buff());
	free_cmds(getter_data()->cmds);
	free_all(getter_data());
	rl_clear_history();
	exit(130);
}
