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
	buf = get_next_line(0);
	state = check_unclosed_quotes(buf, delimiter);
	while (state != 1)
	{
		tmp = get_next_line(0);
		switcher = ft_interpol("%s%s", buf, tmp);
		free(buf);
		free(tmp);
		buf = switcher;
		state = check_unclosed_quotes(buf, delimiter);
	}
	write(fd[1], buf, ft_strlen(buf));
	free(buf);
	exit(1);
}

//TODO: Make the read process dynamic
char	*main_process(int fd[], pid_t pid, char *line)
{
	int		status;
	char	*str;
	char	*buff[1024];

	close(fd[1]);
	waitpid(pid, &status, 0);
	ft_memset(buff, 0, 1024);
	read(fd[0], buff, 1024);
	str = ft_interpol("%s%s", line, buff);
	close(fd[0]);
	return (str);
}

char	*here_doc(char	*line, char *quote)
{
	line = (char *)line;
	quote = (char *)quote;
	return (NULL);
}
