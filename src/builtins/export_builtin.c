/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_cmd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 17:44:31 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/06/10 17:50:25 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	export_builtin(t_databus *data)
{
	char *new_env;

	new_env = data->cmds->head->next->data;
	if (!is_valid_env_name(new_env))
	{
		printf("minishell: export: `%s': not a valid identifier\n", new_env);
		return ;
	}
	if (!ft_strchr(new_env, '='))
		return ;
	if (is_valid_syntax(data->cmds->head))
	{
		if (++data->number_of_envs < HEAP_OVERFLOW_PROTECTION)
			data->env[data->number_of_envs - 1] = ft_strdup(new_env);
	}
}

int	is_valid_env_name(char *name_value)
{
	if (!ft_isalpha(*name_value) && *name_value != '_')
		return (0);
	name_value++;
	while (*name_value != '\0' && *name_value != '=')
	{
		if (!ft_isalnum(*name_value) && *name_value != '_')
			return (0);
		name_value++;
	}
	return (1);
}
