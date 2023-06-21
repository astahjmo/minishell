/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johmatos <johmatos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 14:03:44 by johmatos          #+#    #+#             */
/*   Updated: 2023/06/21 13:16:29 by johmatos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_databus	*getter_data(void)
{
	static t_databus	data;

	return (&data);
}

int	main(int argc, char *argv[], char *envp[])
{
	t_databus	*data;

	data = getter_data();
	(void)argc;
	(void)argv;
	ft_bzero(&data, sizeof(data));
	data.envp = envp;
	init_signal();
	main_setup_hook(&data);
	init_env(&data);
	repl(&data);
	return (data.exit_status);
}
