/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johmatos <johmatos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 05:31:29 by johmatos          #+#    #+#             */
/*   Updated: 2023/06/24 14:32:56 by johmatos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "minishell.h"
#include <readline/readline.h>

static int	here_doc(int *status, char *delimiter);
static void	child_execute(int fd[], char *delimiter);
static void	free_buf_all(char *buf, unsigned int code);

void	open_heredoc(t_node *node, int *fds, int *status)
{
	int	aux;

	aux = 0;
	while (node != NULL && *status != 2)
	{
		if (node->token == T_PIPE)
			aux++;
		if (node->token == T_HERE_DOC)
		{
			if (fds[aux])
				close(fds[aux]);
			fds[aux] = here_doc(status, node->next->str);
		}
		node = node->next;
	}
}

static int	here_doc(int *status, char *delimiter)
{
	pid_t	pid;
	int		fd[2];

	if (pipe(fd) < 0)
		return (0);
	pid = fork();
	if (pid == 0)
		child_execute(fd, delimiter);
	close(fd[1]);
	waitpid(pid, status, 0);
	return (fd[0]);
}

static void	child_execute(int fd[], char *delimiter)
{
	char	*switcher;
	char	*tmp;
	char	**buf;
	int		state;

	buf = getter_buff();
	signal(SIGINT, sig_handler);
	state = 0;
	close(fd[0]);
	*buf = readline("> ");
	if (*buf == NULL)
		free_buf_all(*buf, 3);
	state = string_is_equal(*buf, delimiter);
	while (state == FALSE)
	{
		tmp = readline("> ");
		state = string_is_equal(tmp, delimiter);
		if (state == TRUE || tmp == NULL)
			break ;
		switcher = strjoin_free(*buf, tmp);
		*buf = switcher;
	}
	write(fd[1], buf, ft_strlen(*buf));
	close(fd[1]);
	free_buf_all(*buf, 1);
}

static void	free_buf_all(char *buf, unsigned int code)
{
	t_databus	*data;

	data = getter_data();
	free_all(data);
	free(buf);
	exit(code);
}
