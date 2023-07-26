/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fds_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 10:24:50 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/07/26 10:25:23 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	close_pipe_fds(int *fds)
{
	close(fds[WRTE]);
	close(fds[READ]);
}

int	duplicate_stdin(int fd)
{
	return (dup2(fd, STDIN_FILENO));
}

int	duplicate_stdout(int fd)
{
	return (dup2(fd, STDOUT_FILENO));
}
