/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_builtins_02.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 22:44:41 by vcedraz-          #+#    #+#             */
/*   Updated: 2023/06/21 22:45:10 by vcedraz-         ###   ########.fr       */
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
