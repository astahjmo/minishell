/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johmatos <johmatos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 05:31:29 by johmatos          #+#    #+#             */
/*   Updated: 2023/08/12 19:12:32 by johmatos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "minishell.h"
#include <signal.h>
#include <stdio.h>

static void	child_execute(int fd[], char *delimiter);
static void	print_warning(char *delimiter);
static void	free_and_exit(int ext);
static void	readline_wrapper(char **buf, char *delimiter, int fd[]);

int	here_doc(int *status, char *delimiter)
{
	pid_t	pid;
	int		*fd;
	int		nfd;

	fd = getter_pipes();
	if (pipe(fd) < 0)
		return (-1);
	signal(SIGINT, SIG_IGN);
	pid = fork();
	if (pid == 0)
		child_execute(fd, delimiter);
	waitpid(pid, status, 0);
	nfd = dup(fd[0]);
	signal(SIGINT, define_handle);
	close(fd[1]);
	close(fd[0]);
	return (nfd);
}

static void	child_execute(int fd[], char *delimiter)
{
	char	**buf;
	int		state;

	buf = getter_buff();
	close(fd[0]);
	signal(SIGINT, sig_handler);
	readline_wrapper(buf, delimiter, fd);
	state = input_is_delimiter(*buf, delimiter);
	while (*buf && state == FALSE)
	{
		put_end_line(*buf, fd[1]);
		*buf = readline("> ");
		state = input_is_delimiter(*buf, delimiter);
		if (state == TRUE || !*buf)
		{
			if (!*buf)
				print_warning(delimiter);
			break ;
		}
	}
	close(fd[1]);
	free_and_exit(0);
}

static void	readline_wrapper(char **buf, char *delimiter, int fd[])
{
	*buf = readline("> ");
	if (NULL == *buf)
	{
		print_warning(delimiter);
		close(fd[1]);
		free_and_exit(0);
	}
}

static void	print_warning(char *delimiter)
{
	char	*s;

	s = fmt_s("minishell: warning: here-document delimited by \
\"end-of-file (wanted %s)\"\n", delimiter, 0, 0);
	ft_putstr_fd(s, STDERR_FILENO);
	free(s);
}

static void	free_and_exit(int ext)
{
	free_cmds(getter_data()->cmds);
	free_all(getter_data());
	exit(ext);
}
