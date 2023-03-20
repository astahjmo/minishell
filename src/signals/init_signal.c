/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_signal.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johmatos <johmatos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 15:59:11 by johmatos          #+#    #+#             */
/*   Updated: 2023/03/16 20:10:37 by johmatos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void define_handle(int sig)
{
	if (sig != SIGINT)
		return ;
	ft_printf("\n");
	rl_on_new_line();
	rl_replace_line ("", 0);
	rl_redisplay();
}

void init_signal()
{
	struct sigaction sa_sig;

	sa_sig.sa_handler = define_handle;
	sa_sig.sa_flags = 0;
	sigemptyset(&sa_sig.sa_mask);
	sigaddset(&sa_sig.sa_mask, SIGINT);
	sigaction(SIGINT, &sa_sig, NULL);
}
