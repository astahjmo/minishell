/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johmatos <johmatos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 05:31:29 by johmatos          #+#    #+#             */
/*   Updated: 2023/07/14 14:59:41 by johmatos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	free_and_exit(int ext)
{
	free_cmds(getter_data()->cmds);
	free_all(getter_data());
	rl_clear_history();
	exit(ext);
}

static void	print_warning(char *delimiter)
{
	ft_printf("minishell: warning: here-document at line 1 delimited by "
		"end-of-file (wanted %s)\n",
		delimiter);
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
	state = input_is_delimiter(*buf, delimiter);
	while (*buf && state == FALSE)
	{
		put_end_line(*buf, fd[1]);
		free(*buf);
		*buf = readline("> ");
		state = input_is_delimiter(*buf, delimiter);
		if (state == TRUE || !*buf)
		{
			if (!*buf)
				print_warning(delimiter);
			break ;
		}
	}
	write(fd[1], *buf, ft_strlen(*buf));
	close(fd[1]);
	free_and_exit(1);
}

int	here_doc(int *status, char *delimiter)
{
	pid_t	pid;
	int		*fd;

	fd = getter_pipes();
	if (pipe(fd) < 0)
		return (0);
	pid = fork();
	if (pid == 0)
		child_execute(fd, delimiter);
	close(fd[1]);
	waitpid(pid, status, 0);
	return (fd[0]);
}
