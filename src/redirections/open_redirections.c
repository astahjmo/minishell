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
#include <unistd.h>

static void	apply_error_and_return(char *str)
{
	char	*s;

	if (*str == 0)
		s = fmt_s("minishell: %s: Ambiguous redirects!\n", str, NULL, NULL);
	if (is_permission_denied(str))
		s = fmt_s("minishell: %s: Permission denied\n", str, NULL, NULL);
	else
		s = fmt_s("minishell: %s: No such file or directory\n",
				str,
				NULL,
				NULL);
	getter_data()->exit_status = 1;
	ft_putstr_fd(s, 2);
	free(s);
}

int	setup_out_redir(int *status, t_node *node,
		t_tokens token, int aux)
{
	int		fd;
	char	*path;

	while (node->token != T_WORD)
		node = node->next;
	path = node->str;
	if (token == T_OUT_REDIR)
		fd = open(path, O_RDWR | O_TRUNC | O_CREAT, 0644);
	else
		fd = open(path, O_RDWR | O_CREAT | O_APPEND, 0644);
	if (fd < 0)
		apply_error_and_return(node->str);
	if (getter_output()[aux] > 0)
		close(getter_output()[aux]);
	getter_output()[aux] = fd;
	*status = fd;
	return (fd);
}

int	setup_input_redir(int *status, t_node *node,
		t_tokens token, int aux)
{
	int		fd;
	char	*path;

	while (node->token != T_WORD)
		node = node->next;
	path = node->str;
	if (token == T_INPUT_REDIR)
		fd = open(path, O_RDONLY);
	else
		fd = getter_heredoc_tmp()[aux];
	if (fd < 0)
		apply_error_and_return(node->str);
	if (token == T_INPUT_REDIR && getter_input()[aux] > 0)
		close(getter_input()[aux]);
	if (token == T_INPUT_REDIR)
		getter_input()[aux] = fd;
	*status = fd;
	return (fd);
}

static void	setup_redir(t_node *node, int aux, t_bool io, int *status)
{
	t_io	*fds;

	fds = getter_t_ios();
	if (io)
		fds[aux].input = setup_input_redir(status, node, node->token, aux);
	else
		fds[aux].output = setup_out_redir(status, node, node->token, aux);
	return ;
}

void	open_redir_io(t_node *node, int *status)
{
	int		x;

	setup_heredoc(status, node);
	if (WEXITSTATUS(*status) == 130)
		return (close_heredocs());
	x = 0;
	while (node)
	{
		if (node->token == T_PIPE)
			x++;
		if (node->token == T_HERE_DOC || node->token == T_INPUT_REDIR)
			setup_redir(node, x, TRUE, status);
		if (node->token == T_OUT_REDIR || node->token == T_O_OUT_REDIR)
			setup_redir(node, x, FALSE, status);
		if (getter_t_ios()[x].input < 0 || getter_t_ios()[x].output < 0)
		{
			if (getter_heredoc_tmp()[x] > 2)
				close(getter_heredoc_tmp()[x]);
			while (node && node->token != T_PIPE)
				node = node->next;
			continue ;
		}
		close_all_unused_fd();
		node = node->next;
	}
}
