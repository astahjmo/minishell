/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pre_executor.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johmatos <johmatos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 20:10:54 by johmatos          #+#    #+#             */
/*   Updated: 2023/07/07 20:11:01 by johmatos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	init_redir(void)
{
	int	status;

	status = init_heredoc(getter_data()->cmds->head);
	if (WEXITSTATUS(status) == 129)
		return (status);
	status = init_redirections(getter_data()->cmds->head);
	return (status);
}

int	pre_executor(t_databus *data)
{
	t_node			*head;
	unsigned int	status;

	status = init_redir();
	if (WEXITSTATUS(status) == 129)
		return (status);
	head = remove_operators(data->cmds->head);
	free_cmds(data->cmds);
	data->cmds->head = head;
	return (status);
}
