/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astaroth <astaroth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 05:31:29 by johmatos          #+#    #+#             */
/*   Updated: 2023/06/05 19:00:38 by johmatos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	child_execute(int fd[], char *delimiter)
{
	char	*switcher;
	char	*tmp;
	char	*buf;
	int		state;

	signal(SIGINT, SIG_DFL);
	state = 0;
	close(fd[0]);
	buf = readline("> ");
	state = check_unclosed_quotes(buf, delimiter);
	while (state == FALSE)
	{
		tmp = readline("> ");
		state = check_unclosed_quotes(tmp, delimiter);
		if (state == TRUE)
			break ;
		switcher = ft_strjoin_free(buf, tmp);
		buf = switcher;
	}
	write(fd[1], buf, ft_strlen(buf));
	close(fd[1]);
	free(buf);
	exit(1);
}

void	main_process(int fd[], pid_t pid, int *status)
{
	close(fd[1]);
	waitpid(pid, status, 0);
}

int	here_doc(int *status, char *quote)
{
	pid_t	pid;
	int		fd[2];

	if (pipe(fd) < 0)
		return (0);
	pid = fork();
	if (pid == 0)
		child_execute(fd, quote);
	else
		main_process(fd, pid, status);
	return (fd[0]);
}
