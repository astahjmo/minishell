/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johmatos <johmatos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 19:46:33 by johmatos          #+#    #+#             */
/*   Updated: 2023/06/24 15:00:42 by johmatos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "minishell.h"

static int	setup_redir(t_node *node, t_tokens token)
{
	int		fd;
	char	*path;

	while (node->token != T_WORD)
		node = node->next;
	path = node->str;
	if (token == T_OUT_REDIR)
		fd = open(path, O_RDWR | O_TRUNC | O_CREAT, 0666);
	else
		fd = open(path, O_RDWR | O_APPEND, 0666);
	return (fd);
}

static void	open_redir(t_node *node, int *fds, int *status)
{
	int	aux;

	aux = 0;
	while (node != NULL && *status != 2)
	{
		if (node->token == T_PIPE)
			aux++;
		if (node->token == T_OUT_REDIR || node->token == T_O_OUT_REDIR)
		{
			if (fds[aux])
				close(fds[aux]);
			fds[aux] = setup_redir(node, node->token);
		}
		node = node->next;
	}
}

int	*getter_redirections(void)
{
	static int	redirections[MAX_FD] = {0};

	return (redirections);
}

int	init_redirections(t_node *node)
{
	int	*redirections;
	int	status;

	status = 0;
	redirections = getter_redirections();
	open_redir(node, redirections, &status);
	return (status);
}
