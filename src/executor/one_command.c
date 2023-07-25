/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   one_command.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johmatos <johmatos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 17:41:22 by johmatos          #+#    #+#             */
/*   Updated: 2023/07/16 14:59:03 by johmatos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <stdio.h>
#include <unistd.h>

t_io	*command_hook(int cmd_count)
{
	t_io	*fds;
	t_io	*stdio;

	stdio = getter_stdio();
	fds = getter_t_ios();
	if (fds[cmd_count].input < 0 || fds[cmd_count].output < 0)
		return (NULL);
	if (fds[cmd_count].input > 2)
		stdio->input = fds[cmd_count].input;
	if (fds[cmd_count].output > 2)
		stdio->output = fds[cmd_count].output;
	return (stdio);
}

t_io	*getter_stdio(void)
{
	static t_io	fds = {STDIN_FILENO, STDOUT_FILENO};

	return (&fds);
}

static void	post_child_routine(void)
{
	int	status;

	status = getter_data()->exit_status;
	if (getter_stdio()->input > 2)
		close(getter_stdio()->input);
	if (getter_stdio()->output > 2)
		close(getter_stdio()->output);
	free_cmds_arr(getter_data()->cmds->arr_cmds);
	free_cmds(getter_data()->cmds);
	free_all(getter_data());
	exit(status);
}

static void	fork_and_execute(t_node *cmds)
{
	pid_t	pid;
	int		i;
	t_io	*cmd;
	int		cmd_count;

	cmd_count = getter_data()->cmds->idx;
	pid = fork();
	if (pid < 0)
		printf("sda\n");
	i = 0;
	if (pid == 0)
	{
		cmd = command_hook(cmd_count);
		if (!cmd)
			return (post_child_routine());
		if (cmd->input > 2)
			dup2_and_close(cmd->input, STDIN_FILENO);
		if (cmd->output > 2)
			dup2_and_close(cmd->output, STDOUT_FILENO);
		exec_command(cmds);
		exit(getter_data()->exit_status);
	}
	else
		waitpid(pid, &i, 0);
	getter_data()->exit_status = WEXITSTATUS(i);
}

void	one_command(t_node *cmds)
{
	t_tokens		builtin_idx;
	t_fn_built_exec	**exec;
	t_io			*cmd;

	if (!cmds || *cmds->str == 0)
		return ;
	cmd = command_hook(0);
	if (!cmd)
		return ;
	cmd = command_hook(0);
	if (!cmd)
		return (post_child_routine());
	exec = get_built_func_arr();
	builtin_idx = is_builtin(cmds->str);
	if (builtin_idx != -1)
		exec[builtin_idx](cmds);
	else
		fork_and_execute(cmds);
}
