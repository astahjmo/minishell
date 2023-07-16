/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   one_command.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johmatos <johmatos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 17:41:22 by johmatos          #+#    #+#             */
/*   Updated: 2023/07/12 20:16:13 by johmatos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_process_io	*command_hook(int cmd_count)
{
	t_process_io	*fds;
	t_process_io	*stdio;

	stdio = getter_stdio();
	fds = getter_t_process_io();
	if (fds[cmd_count].input > 2)
		stdio->input = fds[cmd_count].input;
	if (fds[cmd_count].output > 2)
		stdio->output = fds[cmd_count].output;
	return (stdio);
}

t_process_io	*getter_stdio(void)
{
	static t_process_io	fds = {STDIN_FILENO, STDOUT_FILENO};

	return (&fds);
}

static void	dup2_and_close(int fd, int clone)
{
	dup2(fd, clone);
	close(fd);
}

static void	fork_and_execute(t_node *cmds, t_node **free_if_invalid)
{
	pid_t			pid;
	int				i;
	t_process_io	*fds;
	int				cmd_count;

	cmd_count = getter_data()->cmds->idx;
	pid = fork();
	if (pid < 0)
		printf("sda\n");
	i = 0;
	if (pid == 0)
	{
		fds = command_hook(cmd_count);
		if (fds->input > 2)
			dup2_and_close(fds->input, STDIN_FILENO);
		if (fds->output > 2)
			dup2_and_close(fds->output, STDOUT_FILENO);
		exec_command(cmds, free_if_invalid);
		exit(1);
	}
	else
		waitpid(pid, &i, 0);
	getter_data()->exit_status = WEXITSTATUS(i);
}

void	one_command(t_node *cmds, t_node **free_if_invalid)
{
	t_tokens		builtin_idx;
	t_fn_built_exec	**exec;

	exec = get_built_func_arr();
	builtin_idx = is_builtin(cmds->str);
	if (builtin_idx != -1)
		exec[builtin_idx](cmds);
	else
		fork_and_execute(cmds, free_if_invalid);
}
