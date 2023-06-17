/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_cmd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 16:26:54 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/06/09 16:26:54 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	env_builtin(t_databus *data)
{
	int		i;
	char	name[STR_LIMIT];
	char	content[STR_LIMIT];

	i = -1;
	ft_bzero(name, STR_LIMIT);
	ft_memset(content, 'x', STR_LIMIT);
	while (++i < data->number_of_envs)
	{
		get_env_name(name, data->env[i]);
		get_env_content(content, name, data->env[i]);
		if (ft_strchr(data->env[i], '='))
		{
			if (is_initialized_to_zero(content))
				printf("%s=\n", name);
			else
				printf("%s=%s\n", name, content);
		}
	}
}

void	alt_env_builtin(t_databus *data)
{
	int		i;
	char	name[STR_LIMIT];
	char	content[STR_LIMIT];

	i = -1;
	ft_bzero(name, STR_LIMIT);
	ft_memset(content, 'x', STR_LIMIT);
	while (++i < data->number_of_envs)
	{
		get_env_name(name, data->env[i]);
		get_env_content(content, name, data->env[i]);
		if (ft_strchr(data->env[i], '='))
		{
			if (is_initialized_to_zero(content))
				printf("declare -x %s=\"\"\n", name);
			else
				printf("declare -x %s=\"%s\"\n", name, content);
		}
		else
			printf("declare -x %s\n", name);
	}
}

void	get_env_name(char *name, char *env)
{
	char	*equal_sign;

	equal_sign = ft_strchr(env, '=');
	if (equal_sign)
		ft_strlcpy(name, env, equal_sign - env + 1);
	else
		ft_strlcpy(name, env, ft_strlen(env) + 1);
	return ;
}

void	get_env_content(char *content, char *name, char *env)
{
	char	*found_name;
	char	*equal_sign;

	found_name = ft_strnstr(env, name, STR_LIMIT);
	if (found_name)
	{
		equal_sign = ft_strchr(found_name, '=');
		if (equal_sign && equal_sign[1])
			ft_strlcpy(content, &equal_sign[1], ft_strlen(equal_sign));
		else if (equal_sign && !(equal_sign[1]))
			ft_bzero(content, STR_LIMIT);
		return ;
	}
}
