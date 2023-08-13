/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   one_command.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johmatos <johmatos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 17:41:22 by johmatos          #+#    #+#             */
/*   Updated: 2023/08/12 19:03:28 by johmatos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
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
	close_all_fds();
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
	if (is_fork_error(pid))
		return ;
	i = 0;
	if (pid == 0)
	{
		cmd = command_hook(cmd_count);
		if (!cmd)
			return (post_child_routine());
		if (cmd->input > 2)
			duplicate_stdin(cmd->input);
		if (cmd->output > 2)
			duplicate_stdout(cmd->output);
		exec_command(cmds);
		post_child_routine();
	}
	else
		waitpid(pid, &i, 0);
	set_exit_code(i);
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
	signal(SIGINT, handle_sigint);
	if (builtin_idx != -1)
		exec[builtin_idx](cmds);
	else
		fork_and_execute(cmds);
}
