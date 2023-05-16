/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astaroth <astaroth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 14:03:44 by johmatos          #+#    #+#             */
/*   Updated: 2023/05/16 15:27:40 by astaroth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int argc, char *argv[], char *envp[])
{
	t_databus	data;

	init_signal();
	main_setup_hook(&data);
	init_environ(envp, data.env);
	ft_print_env(data.env);
	//free_env(data.env);
	//free(data.env);
	//free(data.cmds);
	return (0);
	wait_input(data);
	**argv = **argv;
	**envp = **envp;
	argc = argc;
	return (0);
}
