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

#include "libft.h"
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

static int	setup_out_redir(int *status, t_node *node, t_tokens token)
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
	if (fd < 0)
		apply_error_and_return(node->str);
	*status = fd;
	return (fd);
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
	if (fd < 0)
		apply_error_and_return(node->str);
	return (fd);
}

static void	setup_redir(int	*status, t_node *node, int aux, t_bool io)
{
	t_io	*fds;

	fds = getter_t_ios();
	if (io)
	{
		if (fds[aux].input)
			close(fds[aux].input);
		fds[aux].input = setup_input_redir(status, node, node->token);
	}
	else 
	{
		if (fds[aux].output)
			close(fds[aux].output);
		fds[aux].output = setup_out_redir(status, node, node->token);
	}
}

void	open_redir_io(t_node *node, t_io *fds, int *status)
{
	int	aux;

	aux = 0;
	while (node != NULL && *status != 2)
	{
		if (node->token == T_PIPE)
			aux++;
		if (node->token == T_HERE_DOC || node-> token == T_INPUT_REDIR)
			setup_redir(status, node, aux, READ);
		if (node->token == T_OUT_REDIR || node->token == T_O_OUT_REDIR)
			setup_redir(status, node, aux, WRTE);
		if (WEXITSTATUS(*status) == 129)
			break ;
		if (fds[aux].output < 0 || fds[aux].input < 0)
		{
			while (node && node->token != T_PIPE)
				node = node->next;
			continue ;
		}
		node = node->next;
	}
}
