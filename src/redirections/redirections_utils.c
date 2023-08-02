/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_redirections.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johmatos <johmatos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 13:15:05 by johmatos          #+#    #+#             */
/*   Updated: 2023/07/14 14:55:05 by johmatos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	setup_heredoc(int *status, t_node *node)
{
	int		*arr_fd;
	int		aux;

	arr_fd = getter_heredoc_tmp();
	aux = 0;
	while (node != NULL && WEXITSTATUS(*status) != 130)
	{
		if (node->token == T_PIPE)
			aux++;
		if (node->token == T_HERE_DOC)
		{
			if (arr_fd[aux] > 0)
				close(arr_fd[aux]);
			arr_fd[aux] = here_doc(status,
					next_node_with_this_token(node, T_WORD)->str);
		}
		node = node->next;
	}
	getter_data()->exit_status = WEXITSTATUS(*status);
}

void	close_all_unused_fd(void)
{
	int	aux;

	aux = 0;
	while (aux < MAX_FD)
	{
		if (getter_input()[aux] != getter_t_ios()[aux].input
					&& getter_input()[aux] > 2)
			close(getter_input()[aux]);
		if (getter_output()[aux] != getter_t_ios()[aux].output
					&& getter_output()[aux] > 2)
			close(getter_output()[aux]);
		if (getter_heredoc_tmp()[aux] != getter_t_ios()[aux].input
					&& getter_heredoc_tmp()[aux] > 2)
			close(getter_heredoc_tmp()[aux]);
		aux++;
	}
}

void	close_all_fds(void)
{
	int	b;

	b = -1;
	while (++b < MAX_FD)
		close(b);
}
