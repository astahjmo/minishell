/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johmatos <johmatos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 20:37:17 by johmatos          #+#    #+#             */
/*   Updated: 2023/03/24 16:14:46 by johmatos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
//TODO: Make buf to be a dynamic string.
static void	child_execute(int fd[], char *buf, char *delimiter)
{
	char	*iostream;

	signal(SIGINT, SIG_DFL);
	close(fd[0]);
	iostream = malloc(sizeof(char) * 1024);
	ft_memset(iostream, 0, 1024);
	buf = readline("> ");
	ft_strlcat(iostream, buf, ft_strlen(buf) + ft_strlen(iostream) + 2);
	ft_strlcat(iostream, "\n", 2 + ft_strlen(iostream));
	while (!check_unclosed_quotes(buf, delimiter))
	{
		buf = readline("> ");
		ft_strlcat(iostream, buf, ft_strlen(buf) + ft_strlen(iostream) + 2);
		ft_strlcat(iostream, "\n", 2 + ft_strlen(iostream) + 2);
	}
	write(fd[1], iostream, ft_strlen(iostream + 1));
	close(fd[1]);
	exit(1);
}

//TODO: Split main_process waitpid to this function 
//return the final here_doc buffer
//TODO: Get the current line and concat with final buffer and return
char	*main_process(int fd[], pid_t pid, char *buff);

char	*here_doc(char	*line, char *quote)
{
	int		fd[2];
	char	*buf;
	char	buff[1024];
	pid_t	pid;
	int		*status;

	if (pipe(fd) < 0)
	{
		perror("pipe error");
		exit(EXIT_FAILURE);
	}
	pid = fork();
	if (pid < 0)
	{
		perror("error");
		exit(EXIT_FAILURE);
	}
	else if (pid == 0)
		child_execute(fd, buf, quote);
	else
	{
		close(fd[1]);
		waitpid(pid, status, 0);
		read(fd[0], buff, 10000);
		close(fd[0]);
	}
	return ("a");
}
