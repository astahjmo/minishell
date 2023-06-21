/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johmatos <johmatos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 05:31:29 by johmatos          #+#    #+#             */
/*   Updated: 2023/06/21 19:10:31 by johmatos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "minishell.h"
#include <readline/readline.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>

static char	**getter_buff(void)
{
	static char	*buf = NULL;

	return (&buf);
}

void	free_buf_all(char	*buf, unsigned int code)
{
	t_databus	*data;

	data = getter_data();
	free_all(data);
	free(buf);
	exit(code);
}

void	sig_handler(int sig)
{
	t_databus	*data;
	char		**buff;

	if (sig != SIGINT)
		return ;
	data = getter_data();
	buff = getter_buff();
	free(*buff);
	free_all(data);
	exit(129);
}

void	child_execute(int fd[], char *delimiter)
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
		switcher = ft_strjoin_free(*buf, tmp);
		*buf = switcher;
	}
	write(fd[1], buf, ft_strlen(*buf));
	close(fd[1]);
	free_buf_all(*buf, 1);
}

int	here_doc(int *status, char *delimiter)
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
