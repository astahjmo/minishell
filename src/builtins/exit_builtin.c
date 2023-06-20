/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 14:31:33 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/06/09 14:35:04 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	has_non_numeric_char(char *str);
static int	has_too_many_args(t_databus *data);

void	free_all(t_databus *data)
{
	free_cmds(data->cmds);
	free(data->cmds);
	free(data->stream);
	free(data->prompt);
	rl_clear_history();
}

void	exit_builtin(t_databus *data)
{
	char	*exit_argument;

	exit_argument = NULL;
	if (data->cmds->head->next)
		exit_argument = data->cmds->head->next->data;
	if (exit_argument)
	{
		if (has_too_many_args(data))
		{
			data->exit_status = 1;
			printf("minishell: exit: too many arguments\n");
		}
		else if (has_non_numeric_char(exit_argument))
			data->exit_status = 2;
		else
			data->exit_status = ft_atoi(exit_argument);
	}
	if (!has_too_many_args(data))
	{
		if (isatty(STDIN_FILENO))
			ft_putstr_fd("exit\n", 1);
		free_all(data);
		exit(data->exit_status);
	}
}

static int	has_non_numeric_char(char *str)
{
	while (*str)
	{
		if (!ft_isdigit(*str))
			return (1);
		str++;
	}
	return (0);
}

static int	has_too_many_args(t_databus *data)
{
	t_node	*head;
	t_node	*arg1;
	t_node	*too_many_args;

	arg1 = NULL;
	head = NULL;
	too_many_args = NULL;
	head = data->cmds->head;
	if (head)
		arg1 = head->next;
	if (arg1)
		too_many_args = arg1->next;
	return (too_many_args != NULL);
}
