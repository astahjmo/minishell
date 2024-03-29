/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johmatos <johmatos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 14:03:44 by johmatos          #+#    #+#             */
/*   Updated: 2023/08/12 18:59:00 by johmatos         ###   ########.fr       */
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
	data->exit_status = 0;
	(void)argc;
	(void)argv;
	data->envp = envp;
	init_signal();
	main_setup_hook(data);
	init_env(data);
	read_evaluate_print_loop(data);
	return (data->exit_status);
}
