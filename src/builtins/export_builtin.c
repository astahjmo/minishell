/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_builtin.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johmatos <johmatos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 17:44:31 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/06/13 15:43:34 by johmatos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	increase_number_of_envs(t_databus *data);
static int	is_valid_env_name(char *env);
static int	check_strlen(int len, char *new_env);
static int	overwrite_if_already_exists(t_databus *data);

void	export_builtin(t_databus *data)
{
	int		len;
	char	*new_env;

	new_env = data->cmds->head->next->data;
	if (!is_valid_syntax(data->cmds->head) || !is_valid_env_name(new_env))
		return ;
	if (overwrite_if_already_exists(data) || !increase_number_of_envs(data))
		return ;
	len = ft_strlen(new_env) + 1;
	if (!check_strlen(len, new_env))
		return ;
	ft_strlcpy(data->env[data->number_of_envs - 1], new_env, len);
}

static int	is_valid_env_name(char *env)
{
	if (!ft_isalpha(*env) && *env != '_')
		return (0);
	env++;
	while (*env != '\0' && *env != '=')
	{
		if (!ft_isalnum(*env) && *env != '_')
		{
			ft_putstr_fd("minishell: export: `", 2);
			ft_putstr_fd(env, 2);
			ft_putstr_fd("': not a valid identifier\n", 2);
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
		return (FALSE);
	}
	return (TRUE);
}

static int	overwrite_if_already_exists(t_databus *data)
{
	int		i;
	char	*new_env;

	i = 0;
	new_env = data->cmds->head->next->data;
	while (i < data->number_of_envs)
	{
		if (names_are_equal(data->env[i], new_env)
			&& is_being_initialized(new_env))
			return (ft_strlcpy(data->env[i], new_env, ft_strlen(new_env) + 1));
		i++;
	}
	return (FALSE);
}
