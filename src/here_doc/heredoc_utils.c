/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johmatos <johmatos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 19:46:33 by johmatos          #+#    #+#             */
/*   Updated: 2023/06/24 15:00:42 by johmatos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "minishell.h"

int	*getter_heredoc_fd(void)
{
	static int	heredoc_fds[MAX_FD];

	ft_bzero(heredoc_fds, sizeof(*heredoc_fds));
	return (heredoc_fds);
}

int	init_heredoc(t_node *node)
{
	int	*heredoc_fd;
	int	status;

	heredoc_fd = getter_heredoc_fd();
	status = 0;
	ft_bzero(heredoc_fd, MAX_FD);
	open_heredoc(node, heredoc_fd, &status);
	return (status);
}

char	**getter_buff(void)
{
	static char	*buf;

	buf = NULL;
	return (&buf);
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
	exit(130);
}
