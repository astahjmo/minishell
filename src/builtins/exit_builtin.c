/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_builtin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 14:31:33 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/06/21 14:40:24 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	if_has_too_many_args(t_databus *data, int *too_many_arguments);
static int	is_llmin(char *str);
static void	if_has_non_numeric_char(t_databus *data);

void	exit_builtin(t_databus *data)
{
	char	*exit_argument;
	int		too_many_arguments;

	exit_argument = NULL;
	too_many_arguments = 0;
	if (data->cmds->head->next)
		exit_argument = data->cmds->head->next->data;
	if (exit_argument)
	{
		if (is_llmin(exit_argument))
			data->exit_status = 0;
		else
		{
			data->exit_status = ft_atoi(exit_argument);
			if_has_too_many_args(data, &too_many_arguments);
			if_has_non_numeric_char(data);
		}
	}
	if (!too_many_arguments)
	{
		if (isatty(STDIN_FILENO))
			ft_putstr_fd("exit\n", 1);
		free_all(data);
		exit(data->exit_status);
	}
}

static void	if_has_non_numeric_char(t_databus *data)
{
	char	*str;

	str = data->cmds->head->next->data;
	while (*str)
	{
		if ((!ft_isdigit(*str) && *str != '+' && *str != '-')
			|| ((long long)(SIZE_MAX / 2) < ft_atoull(str)))
		{
			if (!is_llmin(str))
			{
				data->exit_status = 2;
				ft_putstr_fd("minishell: numeric argument required\n", 2);
				break ;
			}
		}
		str++;
	}
}

static void	if_has_too_many_args(t_databus *data, int *has_too_many_arguments)
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
	if (too_many_args != NULL)
	{
		data->exit_status = 1;
		ft_putstr_fd("minishell: exit: too many arguments\n", 2);
		(*has_too_many_arguments) = 1;
	}
}

static int	is_llmin(char *str)
{
	char	*llmin;

	llmin = "9223372036854775808";
	if (*str++ == '-')
	{
		while (*str)
		{
			if (*str != *llmin)
				return (0);
			str++;
			llmin++;
		}
		return (1);
	}
	return (0);
}
