/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_builtin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johmatos <johmatos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 14:31:33 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/07/18 20:57:12 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <unistd.h>

static int	has_non_numeric_char(char *str);
static void	free_and_exit(t_databus *data, char *failure_message);
static void	handle_exit_argument(t_databus *data, char *exit_argument);

void	exit_builtin(t_node *current)
{
	char		*exit_argument;
	t_databus	*data;

	(void)current;
	data = getter_data();
	exit_argument = NULL;
	if (current->next && current->next->next)
		exit_argument = current->next->next->str;
	data->exit_status = 0;
	if (!exit_argument)
		free_and_exit(data, NULL);
	handle_exit_argument(data, exit_argument);
}

static void	handle_exit_argument(t_databus *data, char *exit_argument)
{
	if (is_llmin(exit_argument))
		data->exit_status = 0;
	else if (has_non_numeric_char(exit_argument))
	{
		data->exit_status = 2;
		free_and_exit(data, "minishell: exit: numeric argument required\n");
	}
	else if (has_too_many_args())
	{
		data->exit_status = 1;
		ft_putstr_fd("minishell: exit: too many arguments\n", 2);
		return ;
	}
	else
		data->exit_status = ft_atoi(exit_argument);
	free_and_exit(data, NULL);
}

static void	free_and_exit(t_databus *data, char *failure_message)
{
	if (failure_message)
		ft_putstr_fd(failure_message, 2);
	if (isatty(STDIN_FILENO))
		ft_putstr_fd("exit\n", 1);
	free_cmds_arr(data->cmds->arr_cmds);
	free_cmds(data->cmds);
	close(STDIN_FILENO);
	close(STDOUT_FILENO);
	free_all(data);
	exit(data->exit_status);
}

static int	has_non_numeric_char(char *str)
{
	while (*str)
	{
		if ((!ft_isdigit(*str) && *str != '+' && *str != '-')
			|| ((long long)(SIZE_MAX / 2) < ft_atoull(str)))
			return (TRUE);
		str++;
	}
	return (FALSE);
}

int	has_too_many_args(void)
{
	t_node	*arg1;
	t_node	*arg2;
	t_node	*cmd;

	arg2 = NULL;
	cmd = getter_data()->cmds->head;
	arg1 = next_node_with_this_token(cmd->next, T_WORD);
	if (arg1)
		arg2 = next_node_with_this_token(arg1->next, T_WORD);
	if (arg2)
		return (TRUE);
	return (FALSE);
}
