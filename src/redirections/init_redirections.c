/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_redirections.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johmatos <johmatos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 19:46:33 by johmatos          #+#    #+#             */
/*   Updated: 2023/07/14 14:23:22 by johmatos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "minishell.h"

int	*getter_outputs(void)
{
	static int	redirections[MAX_FD] = {0};

	return (redirections);
}

int	*getter_inputs(void)
{
	static int	heredoc_fds[MAX_FD];

	ft_bzero(heredoc_fds, sizeof(*heredoc_fds));
	return (heredoc_fds);
}

int	init_output(t_node *node)
{
	t_io	*redirections;
	int		status;

	status = 0;
	redirections = getter_t_ios();
	open_out_redir(node, redirections, &status);
	return (status);
}

int	init_input(t_node *node)
{
	t_io	*heredoc_fd;
	int		status;

	heredoc_fd = getter_t_ios();
	status = 0;
	ft_bzero(heredoc_fd, MAX_FD);
	open_input_redir(node, heredoc_fd, &status);
	return (status);
}
