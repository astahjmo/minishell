/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_builtin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 14:31:33 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/06/21 17:32:39 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	has_too_many_args(t_databus *data);
static int	has_non_numeric_char(char *str);
static void	free_and_exit(t_databus *data, char *failure_message);
static void	handle_exit_argument(t_databus *data, char *exit_argument);

void	exit_builtin(t_databus *data)
{
	char	*exit_argument;

	exit_argument = NULL;
	if (data->cmds->head->next)
		exit_argument = data->cmds->head->next->data;
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
	else if (has_too_many_args(data))
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

static int	has_too_many_args(t_databus *data)
{
	t_node	*head;
	t_node	*arg1;
	t_node	*too_many_args;

	arg1 = NULL;
	head = NULL;
	head = data->cmds->head;
	too_many_args = NULL;
	if (head)
		arg1 = head->next;
	if (arg1)
		too_many_args = arg1->next;
	if (too_many_args)
	{
		return (TRUE);
	}
	return (FALSE);
}
