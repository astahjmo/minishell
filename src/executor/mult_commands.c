/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mult_commands.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johmatos <johmatos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 20:14:51 by johmatos          #+#    #+#             */
/*   Updated: 2023/07/07 21:18:15 by johmatos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "minishell.h"
#include <sys/types.h>
#include <unistd.h>

int	child_routine(t_node *cmds);

int	main_routine(t_node *cmds);

int	fork_and_execute(t_node *cmds)
{
	pid_t	pid;

	pid = fork();
	if (pid < 0)
		ft_printf("deu merda");
	if (pid == 0)
		child_routine(cmds);
	else
		main_routine(cmds);
	return (pid);
}

void	mult_command(t_node *cmds)
{
	t_tokens		builtin_idx;
	t_fn_built_exec	**exec;

	exec = get_built_func();
	builtin_idx = is_builtin(cmds->str);
	if (builtin_idx != -1)
		exec[builtin_idx](cmds);
	else
		exec_command(cmds);
}
