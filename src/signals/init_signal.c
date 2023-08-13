/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_signal.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johmatos <johmatos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 15:59:11 by johmatos          #+#    #+#             */
/*   Updated: 2023/08/12 20:14:25 by johmatos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <signal.h>
#include <stdio.h>

void	define_handle(int sig)
{
	if (sig == SIGINT)
	{
		ft_putstr_fd("\n", 1);
		rl_on_new_line();
		rl_replace_line ("", 0);
		rl_redisplay();
		getter_data()->exit_status = 130;
	}
}

void	handle_sigint(int sig)
{
	write(1, "\n", 1);
	rl_on_new_line();
	rl_replace_line("", 0);
	(void)sig;
}

void	handle_pipe(int sig)
{
	(void)sig;
	close(2);
}

void	init_signal(void)
{
	signal(SIGPIPE, handle_pipe);
	signal(SIGQUIT, SIG_IGN);
	signal(SIGINT, define_handle);
}
