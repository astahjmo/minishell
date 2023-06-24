/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_signal.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johmatos <johmatos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 15:59:11 by johmatos          #+#    #+#             */
/*   Updated: 2023/06/12 17:58:48 by johmatos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	define_handle(int sig)
{
	if (sig == SIGINT)
	{
		ft_putstr_fd("\n", 1);
		rl_on_new_line();
		rl_replace_line ("", 0);
		rl_redisplay();
	}
}

void	init_signal(void)
{
	struct sigaction	sa_sigint;
	struct sigaction	sa_sigquit;

	sa_sigquit.sa_handler = SIG_IGN;
	sa_sigquit.sa_flags = SA_RESTART;
	sigemptyset(&sa_sigquit.sa_mask);
	sigemptyset(&sa_sigint.sa_mask);
	sa_sigint.sa_handler = define_handle;
	sa_sigint.sa_flags = SA_RESTART;
	sigaddset(&sa_sigint.sa_mask, SIGINT);
	sigaddset(&sa_sigquit.sa_mask, SIGQUIT);
	sigaction(SIGINT, &sa_sigint, NULL);
	sigaction(SIGQUIT, &sa_sigquit, NULL);
}
