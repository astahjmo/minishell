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
			fds[aux] = here_doc(status, list_get_token(node, T_WORD)->str);
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
	char	**buf;
	int		state;

	buf = getter_buff();
	signal(SIGINT, sig_handler);
	close(fd[0]);
	state = FALSE;
	*buf = readline("> ");
	state = string_is_equal(*buf, delimiter);
	while (state == FALSE)
	{
		write(fd[1], *buf, ft_strlen(*buf));
		write(fd[1], "\n", 1);
		*buf = readline("> ");
		state = string_is_equal(*buf, delimiter);
		if (state == TRUE || *buf == NULL)
			break ;
	}
	write(fd[1], *buf, ft_strlen(*buf));
	printf("CHILD %s\n", *buf);
	close(fd[1]);
	exit(1);
}
