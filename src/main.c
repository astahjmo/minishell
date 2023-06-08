/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johmatos <johmatos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 14:03:44 by johmatos          #+#    #+#             */
/*   Updated: 2023/06/05 18:45:33 by johmatos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	print_env(t_infoenv *info)
{
	long int	a;

	a = 0;
	while (a < 1e4)
	{
		if (info->bucket[a])
			ft_printf("%s\n", info->bucket[a]->value);
		a++;
	}
}

int	main(int argc, char *argv[], char *envp[])
{
	t_databus	data;

	(void)argc;
	(void)argv;
	init_signal();
	main_setup_hook(&data);
	init_environ(envp, data.env);
	print_env(data.env);
	repl(data);
	return (0);
}
