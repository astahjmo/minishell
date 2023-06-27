/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_builtins_02.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 22:44:41 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/06/26 21:55:43 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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

char	*get_content_from_name_alone(char *name)
{
	t_databus	*data;
	int			i;
	char		content[STR_LIMIT];

	i = -1;
	data = getter_data();
	while (++i < data->number_of_envs)
	{
		if (!ft_strncmp(name, data->env[i], ft_strlen(name)))
		{
			if (!ft_strchr(data->env[i], '='))
				return (ft_strdup(""));
			get_env_content(content, name, data->env[i]);
			return (ft_strdup(content));
		}
	}
	return (ft_strdup(""));
}

int	is_valid_env_name(char *env)
{
	if (!ft_isalpha(*env) && *env != '_')
		return (FALSE);
	env++;
	while (*env != '\0' && *env != '=')
	{
		if (!ft_isalnum(*env) && *env != '_')
			return (FALSE);
		env++;
	}
	return (TRUE);
}

int	getindex_of_env(char *to_unset)
{
	int			i;
	int			len;
	int			nb;
	t_databus	*data;

	i = -1;
	len = ft_strlen(to_unset);
	data = getter_data();
	nb = data->number_of_envs;
	if (!len)
		return (-1);
	while (++i < nb)
	{
		if (!ft_strncmp(data->env[i], to_unset, len)
			&& whole_prefix_matched(data, i, len))
			break ;
	}
	if (i == nb)
		return (-1);
	return (i);
}
