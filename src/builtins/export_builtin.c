/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_builtin.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johmatos <johmatos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 17:44:31 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/06/25 09:07:24 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	increase_number_of_envs(t_databus *data);
static int	is_valid_env_name_err(char *env);
static int	check_strlen(int len, char *new_env);

void	export_builtin(t_node *current)
{
	int			len;
	char		*new_env;
	t_databus	*data;

	if (!is_valid_syntax(current))
		return ;
	data = getter_data();
	current = current->next;
	while (current->next)
	{
		current = current->next;
		if (current->token != T_WORD)
			current = current->next;
		new_env = current->str;
		len = ft_strlen(new_env) + 1;
		if (!is_valid_env_name_err(new_env))
			break ;
		else if (overwrite_env(data, new_env))
			continue ;
		if (!increase_number_of_envs(data))
			return ;
		if (!check_strlen(len, new_env))
			return ;
		ft_strlcpy(data->env[data->number_of_envs - 1], new_env, len);
	}
}

static int	is_valid_env_name_err(char *env)
{
	if (!env || (!ft_isalpha(*env) && *env != '_'))
	{
		ft_putstr_fd("minishell: export:", 1);
		ft_putstr_fd(" not a valid identifier\n", 2);
		getter_data()->exit_status = 1;
		return (0);
	}
	env++;
	while (*env != '\0' && *env != '=')
	{
		if (!ft_isalnum(*env) && *env != '_')
		{
			ft_putstr_fd("minishell: export:", 1);
			ft_putstr_fd(" not a valid identifier\n", 2);
			getter_data()->exit_status = 1;
			return (0);
		}
		env++;
	}
	return (1);
}

static int	increase_number_of_envs(t_databus *data)
{
	if ((data->number_of_envs + 1) == ENVS_LIMIT)
	{
		printf("minishell: too many environment variables\n");
		getter_data()->exit_status = 1;
		return (0);
	}
	data->number_of_envs++;
	return (1);
}

static int	check_strlen(int len, char *new_env)
{
	if (len >= STR_LIMIT)
	{
		ft_putstr_fd("minishell: export:", 2);
		ft_putstr_fd(new_env, 2);
		ft_putstr_fd(": error: variable is too long.\n", 2);
		getter_data()->exit_status = 1;
		return (FALSE);
	}
	return (TRUE);
}

int	overwrite_env(t_databus *data, char *new_env)
{
	int	i;

	i = 0;
	while (i < data->number_of_envs)
	{
		if (names_are_equal(data->env[i], new_env)
			&& is_being_initialized(new_env))
			return (ft_strlcpy(data->env[i], new_env, ft_strlen(new_env) + 1));
		i++;
	}
	return (FALSE);
}
