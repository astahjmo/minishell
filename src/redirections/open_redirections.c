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

static int	setup_out_redir(t_node *node, t_tokens token)
{
	int		fd;
	char	*path;

	while (node->token != T_WORD)
		node = node->next;
	path = node->str;
	if (token == T_OUT_REDIR)
		fd = open(path, O_RDWR | O_TRUNC | O_CREAT, 0666);
	else
		fd = open(path, O_RDWR | O_CREAT | O_APPEND, 0666);
	return (fd);
}

void	open_out_redir(t_node *node, t_process_io *fds, int *status)
{
	int	aux;

	aux = 0;
	while (node != NULL && *status != 2)
	{
		if (node->token == T_PIPE)
			aux++;
		if (node->token == T_OUT_REDIR || node->token == T_O_OUT_REDIR)
		{
			if (fds[aux].output)
				close(fds[aux].output);
			fds[aux].output = setup_out_redir(node, node->token);
		}
		node = node->next;
	}
}

static int	setup_input_redir(int *status, t_node *node, t_tokens token)
{
	int		fd;
	char	*path;

	while (node->token != T_WORD)
		node = node->next;
	path = node->str;
	if (token == T_INPUT_REDIR)
		fd = open(path, O_RDONLY);
	else
		fd = here_doc(status,
				next_node_with_this_token(node, T_WORD)->str);
	return (fd);
}

void	open_input_redir(t_node *node, t_process_io *fds, int *status)
{
	int	aux;

	aux = 0;
	while (node != NULL && *status != 2)
	{
		if (node->token == T_PIPE)
			aux++;
		if (node->token == T_HERE_DOC || node-> token == T_INPUT_REDIR)
		{
			if (fds[aux].input)
				close(fds[aux].input);
			fds[aux].input = setup_input_redir(status, node, node->token);
		}
		node = node->next;
	}
}
